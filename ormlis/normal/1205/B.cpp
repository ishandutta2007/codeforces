#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int maxN = 3e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<ll> a;
    range(i, n) {
        ll x; cin >> x;
        if (x == 0) continue;
        a.push_back(x);
    }
    n = a.size();
    if (n > 200) {
        cout << "3\n";
        return;
    }
    vector<vector<int>> g(n);
    range(i, n) {
        range(j, n) {
            if (i == j) continue;
            if (a[i] & a[j]) {
                g[i].push_back(j);
            }
        }
    }
    int ans = INFi;
    range(i, n) {
        vector<int> d(n, INFi);
        d[i] = 0;
        queue<int> q;
        q.push(i);
        bool f = true;
        while(!q.empty() && f)  {
            int v = q.front();
            q.pop();
            for(auto &u : g[v]) {
                if (d[u] < d[v]) continue;
                if (d[u] == INFi) {
                    q.push(u);
                    d[u] = d[v] + 1;
                    continue;
                }
                ans = min(ans, d[v] + d[u] + 1);
                f = false;
                break;
            }
        }
    }
    cout << (ans == INFi ? -1 : ans) << '\n';
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