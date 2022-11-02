#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e15 + 7;
const int max_n = 2e5 + 1, max_m = 2e5 + 2;
int n, m, s1, s2, f;
int cost[max_m];
vector<int> gr[max_n];



void scan() {
	cin >> n >> m >> s1 >> f >> s2;
	s1--; f--; s2--;

	for(int i = 0;i < n;i++) gr[i].clear();

	for(int i = 0;i < m;i++) cin >> cost[i];

	for(int i = 0;i < m;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		gr[v1].emplace_back(v2);
		gr[v2].emplace_back(v1);
	}


	sort(cost, cost + m);
}


vector<int> bfs(int start) {
	vector<int> dist(n, inf);
	dist[start] = 0;

	deque<int> f;
	f.emplace_back(start);

	while(!f.empty()) {
		int v = f.front();
		f.pop_front();

		for(int to : gr[v]) {
			if (dist[to] > dist[v] + 1) {
				dist[to] = dist[v] + 1;
				f.emplace_back(to);
			}
		}
	}

	return dist;
}

void solve() {
	scan();

	for(int i = 1;i < m;i++) cost[i] += cost[i - 1];

	vector<int> dist1(n), dist2(n), d(n);

	dist1 = bfs(s1);
	dist2 = bfs(s2);
	d = bfs(f);

	//for(int i = 0;i < n;i++) cout << dist1[i] << " " << dist2[i] << " " << d[i] << endl;

	int res = inf;
	for(int i = 0;i < n;i++) {
		if (dist1[i] + dist2[i] + d[i] > m) continue;
		int new_res = cost[dist1[i] + dist2[i] + d[i] - 1] + cost[d[i] - 1];

		res = min(res, new_res);
	}

	cout << res << endl;

}






signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);


   	int t;
   	cin >> t;
   	while(t--) {
   		solve();
   	}


}