#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <bitset>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2e5;
int n;
vector<pii> adj[sz];
ll ans = 0;

ll dpd[sz][2], dpu[sz][2];//tot,1


void input() {
	cin >> n;
	foru(i, 0, n - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[--a].pb({ --b,c });
		adj[b].pb({ a,c });
	}
}

void dfs1(int src, int prv = -1) {
	for (auto x : adj[src]) {
		if (x.first == prv)continue;
		dfs1(x.first, src);
		if (x.second == 0) {
			dpd[src][0]++;
			dpd[src][0] += dpd[x.first][0];
		}
		else {
			dpd[src][0]++;
			dpd[src][1]++;
			dpd[src][0] += dpd[x.first][1];
			dpd[src][1] += dpd[x.first][1];
		}
	}
}

void dfs2(int src, int prv = -1) {
	for (auto x : adj[src]) {
		if (x.first == prv)continue;
		if (x.second == 0) {
			dpu[x.first][0]++;
			dpu[x.first][0] += dpu[src][0];
			dpu[x.first][0] += (dpd[src][0] - dpd[x.first][0] - 1);
		}
		else {
			dpu[x.first][0]++;
			dpu[x.first][0] += dpu[src][1];
			dpu[x.first][0] += (dpd[src][1] - dpd[x.first][1] - 1);
			dpu[x.first][1]++;
			dpu[x.first][1] += dpu[src][1];
			dpu[x.first][1] += (dpd[src][1] - dpd[x.first][1] - 1);
		}
		dfs2(x.first, src);
	}
}

int main() {
	fast;
	input();
	dfs1(0);
	dfs2(0);
	foru(i, 0, sz) ans += (dpd[i][0] + dpu[i][0]);
	cout << ans << endl;
	return 0;
}