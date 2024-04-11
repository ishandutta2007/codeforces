#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const int inf = 1e17 + 7;

int n, m;
vector<vector<int>> a;
vector<vector<int>> res;

void scan() {
    cin >> n >> m;

    vector<string> b(n);
    for(int i = 0;i < n;i++)
        cin >> b[i];

    if (n < m) swap(n, m);

    a.resize(n, vector<int>(m));

    if (n == b.size()) {
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                a[i][j] = b[i][j] - '0';
    }else{
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                a[j][i] = b[i][j] - '0';
    }
}

void solve() {
    scan();
    res.resize(n, vector<int>(8));

    if (m > 3) {
        cout << -1;
        return;
    }

    for(int i = 0;i < n;i++) {
        for(int v = 0;v < (1 << m);v++) {
            int new_cnt = 0;
            for(int j = 0;j < m;j++) {
                if (a[i][j] != ((v >> j) & 1)) new_cnt++;
            }

            if (i == 0) {
                res[i][v] = new_cnt;
                continue;
            }

            res[i][v] = inf;
            for(int pr = 0;pr < (1 << m);pr++) {
                bool bad = false;
                for(int j = 0;j + 1 < m;j++) {
                    int v_ = v >> j;
                    int pr_ = pr >> j;
                    int cnt = (v_ & 1) + (pr_ & 1) + ((v_ / 2) & 1) + ((pr_ / 2) & 1);

                    if (cnt % 2 == 0) bad = true;
                }

                if (bad) continue;
                res[i][v] = min(res[i][v], res[i - 1][pr] + new_cnt);
            }

            //cout << res[i][v]
        }
    }

    int ans = inf;
    for(int i = 0;i < (1 << m);i++) 
        ans = min(ans, res[n - 1][i]);

    cout << ans << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}