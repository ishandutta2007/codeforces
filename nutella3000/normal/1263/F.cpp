#include <bits/stdc++.h>
        
using namespace std;
        
        
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
        
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
         
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define size(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
        
const int inf = 5e9 + 7;
const int max_n = 2e3 + 3, log_n = 12;

int n;

vector<vector<pii>> scan(int id) {
	int a;
	cin >> a;
	vector<int> par(a), deg(a), least(a, inf), sz(a, 1);
	sz[0] = 0;
	vector<vector<pii>> res(n);

	for(int i = 1; i < a; ++i) {
		cin >> par[i], --par[i];
		deg[par[i]]++;
	}

	for(int i = 0;i < n;i++) {
		int v; cin >> v; --v;

		least[v] = i;

		while(true) {
			res[i].emplace_back(least[v], sz[v]);

			int to = par[v];
			if (least[to] == inf) least[to] = least[v];
			--deg[to];
			sz[to] += sz[v];
			if (deg[to] != 0) break;
			v = to;
		}
	}

	return res;
}

void solve() {
	cin >> n;
	vector<vector<pii>> r1 = scan(0), r2 = scan(1);

	vector<int> dp(n);
	for(int i = 0;i < n;i++) {
		for(pii j : r1[i]) {
			chkmax(dp[i], j.se + (j.fi == 0 ? 0 : dp[j.fi - 1]));
			//cout << j.fi << " " << i << " " << j.se << endl;
		}
		for(pii j : r2[i]) {
			chkmax(dp[i], j.se + (j.fi == 0 ? 0 : dp[j.fi - 1]));
			//cout << j.fi << " " << i << " " << j.se << endl;
		}
	}

	cout << dp[n - 1];
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}