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

    int ansi = -1, ansj = -1;
    int opt = 0;

    auto check = [&](int x) {
        vector<int> has((1 << M), 0);
        vector<int> hasId((1 << M), -1);
        for (int i = 0; i < N; i++) {
            int mask = 0;
            for (int j = 0; j < M; j++) {
                if (A[i][j] >= x) {
                    mask |= (1 << j);
                }
            }
            has[mask] = 1;
            hasId[mask] = i;
        }
        for (int i = 0; i < (1 << M); i++) {
            for (int j = 0; j < (1 << M); j++) {
                if ((i | j) == (1 << M) - 1 && has[i] && has[j]) {
                    ansi = hasId[i];
                    ansj = hasId[j];
                    return true;
                }
            }
        }
        return false;
    };

    int le = 0, ri = 1e9;
    while (le <= ri) {
        int mid = (le + ri) / 2;
        if (check(mid)) {
            opt = mid;
            le = mid + 1;
        } else {
            ri = mid - 1;
        }
    }

    check(opt);
    cout << ansi + 1 << " " << ansj + 1 << "\n";
    return 0;
}