#include <bits/stdc++.h>
using namespace std;
  
//#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e9 + 7;
const int max_n = 1e6 + 3, max_m = 1e4 + 4;
int n, m, g, r;
vector<int> res[max_m];
vector<int> a;
 
 
 
 
void bfs() {
	res[0][0] = 0;
	deque<pii> bfs;
	bfs.emplace_back(0, 0);
 
	while(!bfs.empty()) {
		int v = bfs.front().first;
		int t = bfs.front().second;
		bfs.pop_front();
 
		/*vector<int> q;
		if (v != 0) q.emplace_back(v - 1);
		if (v + 1 < m) q.emplace_back(v + 1);
		if (t == g) q.emplace_back(v);
 */
		/*for(int to : q) {
			int to_t = t + abs(a[v] - a[to]);
			if (to_t > g) continue;
 
			int cost = 0;
			if (to == v) {
				to_t = 0;
				cost = 1;
			}
 
 
			if (res[to][to_t] > res[v][t] + cost) {
				res[to][to_t] = res[v][t] + cost;
				if (cost) one.emplace_back(to, to_t);
				else one.emplace_front(to, to_t);
			}
		}*/

		if (t == g) {
			if (res[v][0] == inf) {
				res[v][0] = res[v][t] + 1;
				bfs.emplace_back(v, 0);
			}
			continue;
		}


		if (v != 0) {
			int to_t = t + a[v] - a[v - 1];
			if (to_t <= g && res[v - 1][to_t] == inf) {
				res[v - 1][to_t] = res[v][t];
				bfs.emplace_front(v - 1, to_t);
			}
		}

		if (v != m - 1) {
			int to_t = t + a[v + 1] - a[v];
			if (to_t <= g && res[v + 1][to_t] == inf) {
				res[v + 1][to_t] = res[v][t];
				bfs.emplace_front(v + 1, to_t);
			}
		}
	}
}
 
 
void scan() {
	cin >> n >> m;
	a.resize(m);
	for(int i = 0;i < m;i++) cin >> a[i];
 
	sort(a.begin(), a.end());
	cin >> g >> r;
 
	for(int i = 0;i < m;i++) res[i].resize(g + 1, inf);
	
}
 
void solve() {
	scan();
	bfs();
	int ans = inf;
	for(int i = 0;i <= g;i++) {
		if (res[m - 1][i] == inf) continue;
		ans = min(ans, i + res[m - 1][i] * (g + r));
	}
 
	if (ans >= inf) cout << -1;
	else cout << ans;
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