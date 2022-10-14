#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M, 0));
    int can = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char k;
            cin >> k;
            if (k == 'A') {
                can++;
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    if (can == 0) {
        cout << "MORTAL\n";
        return 0;
    }

    int ans = 4;

    if (grid[0][0] == 1 || grid[0][M - 1] == 1 || grid[N - 1][0] == 1 || grid[N - 1][M - 1] == 1) {
        ans = min(ans, 2);
    }
    for (int i = 0; i < N; i++) {
        if (grid[i][0] == 1) {
            ans = min(ans, 3);
        }
        if (grid[i][M - 1] == 1) {
            ans = min(ans, 3);
        }
    }

    for (int i = 0; i < M; i++) {
        if (grid[0][i] == 1) {
            ans = min(ans, 3);
        }
        if (grid[N - 1][i] == 1) {
            ans = min(ans, 3);
        }
    }

    for (int i = 0; i < N; i++) {
        int strip = 1;
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 0) {
                strip = 0;
                break;
            }
        }
        if (strip == 1) {
            if (i == 0 || i == N - 1) {
                ans = min(ans, 1);
            } else {
                ans = min(ans, 2);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int strip = 1;
        for (int j = 0; j < N; j++) {
            if (grid[j][i] == 0) {
                strip = 0;
                break;
            }
        }
        if (strip) {
            if (i == 0 || i == M - 1) {
                ans = min(ans, 1);
            } else {
                ans = min(ans, 2);
            }
        }
    }
    
    int zer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 0) {
                zer++;
            }
        }
    }
    if (zer == 0) {
        ans = 0;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    int T;
    cin >> T;
    while (T--) {
        solve();
    }    




    return 0;
}