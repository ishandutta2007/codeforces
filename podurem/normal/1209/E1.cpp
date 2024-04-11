#include <bits/stdc++.h>

using namespace std;

struct Q {
    int x, i, j;
};

int main() {
    int t; cin >> t;
    while (t --> 0) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> A(n, vector<int>(m));
        vector<Q> B(n * m);
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
            B.push_back({ A[i][j], i, j });
        }
        sort(B.begin(), B.end(), [](Q a, Q b) {
            return make_pair(a.x, make_pair(a.i, a.j)) > make_pair(b.x, make_pair(b.i, b.j));
        });
        if (n < 4) {
            int ans = 0;
            for (int i = 0; i < n; ++i) ans += B[i].x;
            cout << ans << "\n";
            continue;
        }
        if (B.size() < 6) {
            cout << B[0].x + B[1].x + B[2].x + B[3].x << "\n";
            continue;
        }
        int ans = -1;
        B.resize(6);
        for (int msk = 0; msk < (1 << 6); ++msk) if (__builtin_popcount(msk) == 4) {
            vector<pair<int, int>> poss;
            map<int, vector<int>> ii;
            int sum = 0;
            for (int i = 0; i < 6; ++i) if ((msk >> i) & 1) {
                sum += B[i].x;
                poss.emplace_back(B[i].j, B[i].i);
                ii[B[i].j].push_back(B[i].i);
            }
            if (ii.size() != 2 || ii[poss[0].first].size() != 2) {
                ans = max(ans, sum);
            } else {
                sort(poss.begin(), poss.end());
                if ((ii[poss[0].first][1] - ii[poss[0].first][0] + 4) % 2 == (ii[poss[2].first][1] - ii[poss[2].first][0] + 4) % 2) {
                    ans = max(ans, sum);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}