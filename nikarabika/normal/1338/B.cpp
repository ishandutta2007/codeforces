//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 100 * 1000;
vector<int> adj[maxn];

int dfs(int u, int p = -1, int col = 1) {
    if (sz(adj[u]) == 1)
        return col;
    int ret = 0;
    for (auto v: adj[u])
        if (v != p)
            ret |= dfs(v, u, col ^ 3);
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    bool mark[n] = {0};
    for (int i = 1; i < n; i++) {
        int fi, se;
        cin >> fi >> se;
        fi--, se--;
        adj[fi].PB(se);
        adj[se].PB(fi);
    }
    int l = 0;
    for (int i = 0; i < n; i++)
        l += sz(adj[i]) == 1;
    for (int i = 0; i < n; i++)
        if (sz(adj[i]) == 1)
            mark[adj[i][0]] = 1;
    int mn = 1;
    for (int i = 0; i < n; i++)
        if (sz(adj[i]) != 1) {
            mn += 2 * (dfs(i) == 3);
            break;
        }
    cout << mn << ' ' << n - l - 1 + count(mark, mark + n, true) << '\n';
	return 0;
}