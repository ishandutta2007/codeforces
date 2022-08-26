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
const int maxN = 1e6 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<int> g1[maxN], g2[maxN];
bool us1[maxN], us2[maxN];

void dfs1(int v) {
    us1[v] = true;
    for(auto &u : g1[v]) {
        if (us1[u]) continue;
        dfs1(u);
    }
}

void dfs2(int v) {
    us2[v] = true;
    for(auto &u : g2[v]) {
        if (us2[u]) continue;
        dfs2(u);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    range(i, n) cin >> a[i];
    auto get = [&](int i, int j) {
        return i * m + j;
    };
    range(i, n) {
        range(j, m) {
            if (a[i][j] == '#') continue;
            if (i && a[i - 1][j] != '#') {
                int v = get(i, j);
                int u = get(i - 1, j);
                g1[u].push_back(v);
                g2[v].push_back(u);
            }
            if (j && a[i][j - 1] != '#') {
                int v = get(i, j);
                int u = get(i, j - 1);
                g1[u].push_back(v);
                g2[v].push_back(u);
            }
        }
    }
    int s = get(0, 0);
    int t = get(n - 1, m - 1);
    dfs1(s);
    dfs2(t);
    if (!us1[t]) {
        cout << "0\n";
        return;
    }
    for(int sum = 1; sum < n - 1 + m - 1; ++sum) {
        int cnt = 0;
        range(i, n) {
            int j = sum - i;
            if (j < 0 || j >= m) continue;
            int v = get(i, j);
            if (us1[v] && us2[v]) cnt++;
        }
        if (cnt == 1) {
            cout << "1\n";
            return;
        }
    }
    cout << "2\n";
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