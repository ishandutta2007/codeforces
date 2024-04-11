#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    pair<int, int> wh = {-1, -1}, bl = {-1, -1};
    for (int bit = 1; bit < 1024; bit<<=1) {
        for (int i = 0; i < N; i++) {
            int b = 0, w = 0;
            for (int j = 0; j < M; j++) {
                if (A[i][j] & bit) {
                    b++;
                } else {
                    w++;
                }
            }
            if (b == 0 || w == 0) {
                continue;
            } else {
                for (int j = 0; j < M; j++) {
                    if (A[i][j] & bit) {
                        bl = {i, j};
                    } else {
                        wh = {i, j};
                    }
                }
                break;
            }
        }
    }

    if (M == 1) {
        int x = 0;
        for (int i = 0; i < N; i++) {
            x ^= A[i][0];
        }
        if (x > 0) {
            cout << "TAK\n";
            for (int i = 0; i < N; i++) {
                cout << 1 << " ";
            }
        } else {
            cout << "NIE\n";
        }
        return 0;
    }

    // if (wh == pair<int, int>{-1, -1}) {
    //     cout << "NIE\n";
    //     return 0;
    // }

    int x = 0;
    vector<int> ans(N, -1);
    for (int i = 0; i < N; i++) {
        if (wh.first == i) {
            continue;
        }
        x ^= A[i][0];
        ans[i] = 0;
    }
    if (wh != make_pair(-1, -1)) {
        if ((x ^ A[wh.first][wh.second]) > 0) {
            ans[wh.first] = wh.second;
            x ^= A[wh.first][wh.second];
        } else if ((x ^ A[bl.first][bl.second]) > 0) {
            ans[bl.first] = bl.second;
            x ^= A[bl.first][bl.second];
        }
    }
    if (x == 0) {
        cout << "NIE\n";
        return 0;
    }
    cout << "TAK\n";
    for (int i = 0; i < N; i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}