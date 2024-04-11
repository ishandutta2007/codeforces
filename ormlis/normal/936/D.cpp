#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 1e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


void solve() {
    int n, m1, m2, t;
    cin >> n >> m1 >> m2 >> t;
    vector<vector<int>> xt(2);
    vector<int> xc;
    range(i, m1) {
        int x;
        cin >> x;
        xt[0].push_back(x);
        xc.push_back(x - 1);
        xc.push_back(x + 1);
        xc.push_back(x);
    }
    range(i, m2) {
        int x;
        cin >> x;
        xt[1].push_back(x);
        xc.push_back(x);
        xc.push_back(x - 1);
        xc.push_back(x + 1);
    }
    xc.push_back(0);
    xc.push_back(n + 1);
    sort(all(xc));
    xc.resize(unique(all(xc)) - xc.begin());
    n = xc.size();
    vector<vector<bool>> bad(2, vector<bool>(n));
    range(i, 2) {
        for (auto &x : xt[i]) {
            bad[i][lower_bound(all(xc), x) - xc.begin()] = true;
        }
    }
    vector<vector<ll>> dist(2, vector<ll>(n, INF));
    vector<vector<int>> p(2, vector<int>(n, -1));
    dist[0][0] = t;
    p[0][0] = -2;
    range(j, n) {
        {
            ll a = max(0ll, dist[0][j]);
            ll b = max(0ll, dist[1][j]);
            if (a < dist[1][j] && !bad[1][j]) {
                dist[1][j] = a;
                p[1][j] = 0;
            }
            if (b < dist[0][j] && !bad[0][j]) {
                dist[0][j] = b;
                p[0][j] = 0;
            }
        }
        if (j == n - 1) break;
        range(i, 2) {
            if (dist[i][j] == INF) continue;
            ll to = dist[i][j] - (xc[j + 1] - xc[j]);
            if (bad[i][j + 1]) {
                if (to < 0) {
                    to += t;
                    if (dist[i][j + 1] > to) {
                        dist[i][j + 1] = to;
                        p[i][j + 1] = 1;
                    }
                }
            } else {
                if (dist[i][j + 1] > to) {
                    dist[i][j + 1] = to;
                    p[i][j + 1] = 1;
                }
            }
        }
    }
    if (dist[0][n - 1] == INF) {
        assert(dist[1][n - 1] == INF);
        cout << "No\n";
        return;
    }
    vector<int> per;
    int a = 0, b = n - 1;
    while (p[a][b] != -2) {
        assert(p[a][b] != -1);
        if (p[a][b] == 1) {
            b--;
        } else {
            per.push_back(b);
            a ^= 1;
        }
    }
    cout << "Yes\n";
    reverse(all(per));
    cout << per.size() << '\n';
    for (auto &to : per) {
        cout << xc[to] << ' ';
    }
    cout << '\n';
    vector<pair<int, int>> shoots;
    a = 0;
    b = 0;
    ll cd = t;
    for (auto &x : per) {
        ll w = xc[b];
        for (int i = b; i <= x; ++i) {
            if (!bad[a][i]) continue;
            if (cd) {
                w += cd;
                cd = 0;
            }
            //if (w >= xc[i]) exit(0);
            //assert(w < xc[i]);
            shoots.push_back({w, a + 1});
            cd = t;
        }
        //assert(w <= xc[x]);
        cd = max(0ll, cd - (xc[x] - w));
        a ^= 1;
        b = x;
    }
    {
        ll w = xc[b];
        for (int i = b; i < n; ++i) {
            if (!bad[a][i]) continue;
            if (cd) {
                w += cd;
                cd = 0;
            }
            //if (w >= xc[i]) exit(0);
            //assert(w < xc[i]);
            shoots.push_back({w, a + 1});
            cd = t;
        }
        //assert(w <= xc[n - 1]);
    }
    cout << shoots.size() << '\n';
    for (auto &[x, y] : shoots) {
        cout << x << ' ' << y << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}