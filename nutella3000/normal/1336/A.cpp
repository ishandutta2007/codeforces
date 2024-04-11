#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;
const int max_n = 2e5 + 3;
int n;
vector<int> gr[max_n];
int sz[max_n], dist[max_n];

void dfs1(int v, int pr) {
	if (pr != -1) dist[v] = dist[pr] + 1;
	for(int to : gr[v]) {
		if (to != pr) {
			dfs1(to, v);
			sz[v] += sz[to];
		}
	}
	sz[v]++;
}

vector<int> a;

void dfs2(int v, int pr) {
	a.emplace_back(dist[v] - sz[v] + 1);
	for(int to : gr[v]) {
		if (to != pr) dfs2(to, v);
	}
}

void solve() {
	int k;
	cin >> n >> k;
	for(int i = 0;i < n - 1;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		gr[v1].emplace_back(v2);
		gr[v2].emplace_back(v1);
	}

	dfs1(0, -1);
	dfs2(0, -1);

	sort(a.begin(), a.end(), [](int v1, int v2) {return v1 > v2;});

	int res = 0;
	for(int i = 0;i < k;i++) res += a[i];
		cout << res;
}





signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);

   	solve();

}