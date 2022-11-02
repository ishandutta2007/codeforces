#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int N = 510;
int pr[N][N];

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<pair<int,int>>> pos(n * n);
    vector<int> minx(n * n, n), maxx(n * n, -1), miny(n * n, n), maxy(n * n, -1);
    set<int> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j]--;
            pos[a[i][j]].pb({i, j});
            st.insert(a[i][j]);
        }
    }
    for (int j = 0; j < n * n; j++) {
        if (pos[j].size() == 0) continue;
        for (auto [x, y] : pos[j]) {
            minx[j] = min(minx[j], x);
            maxx[j] = max(maxx[j], x);
            miny[j] = min(miny[j], y);
            maxy[j] = max(maxy[j], y);
        }
    }
    if (k >= st.size()) {
        cout << k - (int)st.size() << endl;
    } else {
        bool good = 0;
        for (int i = 1; i <= n; i++) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    pr[x][y] = 0;
                }
            }
            for (int j = 0; j < n * n; j++) {
                if (pos[j].size() == 0) continue;
                minx[j] = min(minx[j], n - i);
                miny[j] = min(miny[j], n - i);
                if (maxy[j] - miny[j] + 1 > i || maxx[j] - minx[j] + 1 > i) {
                    continue;
                }
                int x = max(0, maxx[j] - i + 1), y = max(0, maxy[j] - i + 1);
                pr[x][y]++;
                pr[x][miny[j] + 1]--;
                pr[minx[j] + 1][y]--;
                pr[minx[j] + 1][miny[j] + 1]++;
            }
            for (int x = 0; x <= n - i; x++) {
                for (int y = 0; y <= n - i; y++) {
                    if (x > 0) {
                        pr[x][y] += pr[x - 1][y];
                    }
                    if (y > 0) {
                        pr[x][y] += pr[x][y - 1];
                    }
                    if (x > 0 && y > 0) {
                        pr[x][y] -= pr[x - 1][y - 1];
                    }
                    if ((int)(st.size()) - pr[x][y] == k || (int)(st.size()) - pr[x][y] + 1 == k) {
                        good = 1;
                    }
                }
            }
        }
        if (good) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }
    return 0;
}