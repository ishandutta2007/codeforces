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

#define ftime fintime

const int maxn = 100 * 1000 + 10;
int h[maxn],
    stime[maxn],
    ftime[maxn],
    dfstime, n, a, b, da, db;
vector<int> adj[maxn];

void dfs(int u, int p = -1) {
    stime[u] = dfstime++;
    for (auto v : adj[u])
        if (v ^ p) {
            h[v] = h[u] + 1;
            dfs(v, u);
        }
    ftime[u] = dfstime;
}

int solve() {
    cin >> n >> a >> b >> da >> db;
    a--, b--;
    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int fi, se;
        cin >> fi >> se;
        fi--, se--;
        adj[fi].PB(se);
        adj[se].PB(fi);
    }
    h[a] = 0;
    dfstime = 0;
    dfs(a);
    if (h[b] <= da or db <= 2 * da)
        return cout << "Alice\n", 0;
    int cand = max_element(h, h + n) - h;
    h[cand] = 0;
    dfs(cand);
    if (*max_element(h, h + n) > 2 * da)
        cout << "Bob\n";
    else
        cout << "Alice\n";
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}