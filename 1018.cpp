#include <iostream>
#include <algorithm>
using namespace std;

char board[50][50];

int counter(int y, int x) {
    int cnt = 0;
    for (int i = y; i < y + 8; i++) {
        for (int j = x; j < x + 8; j++) {
            if ((i + j) % 2 == 0) {
                if (board[i][j] != 'B') cnt++;
            } else {
                if (board[i][j] == 'B') cnt++;
            }
        }
    }
    return min(cnt, 64 - cnt);
}

int main() {
    int N, M;
    int min_val = 32;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            int tmp = counter(i, j);
            if (tmp < min_val) min_val = tmp;
        }
    }
    cout << min_val;
    return 0;
}
