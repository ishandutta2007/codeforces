#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;
const int n = 1e6 + 3;
vector<int> gr[n];

vector<int> vertex;

void add_edge(int v1, int v2) {
	gr[v1].emplace_back(v2);
	gr[v2].emplace_back(v1);
	vertex.emplace_back(v1);
	vertex.emplace_back(v2);
}

void scan() {
	int temp1;
	cin >> temp1;
	while(temp1--) {
		int v;
		cin >> v;
		vector<int> temp2;
		for(int i = 2;i <= sqrt(v);i++) {
			int cnt = 0;
			while(v % i == 0) {
				cnt++;
				v /= i;
			}
			if (cnt % 2 == 1) temp2.emplace_back(i);
		}
		if (v != 0) temp2.emplace_back(v);

		int v1 = 1;
		if (temp2.size() >= 1) v1 = temp2[0];
		int v2 = 1;
		if (temp2.size() >= 2) v2 = temp2[1];
		//cout << v1 << " " << v2 << '\n';
		add_edge(v1, v2);
	}
}



int bfs(int start) {
	int dist[n];
	for(int i : vertex) dist[i] = inf;

	dist[start] = 0;
	deque<int> b;
	b.emplace_back(start);

	int ans = inf;
	while(!b.empty()) {
		int v = b.front();
		b.pop_front();

		for(int to : gr[v]) {
			if (dist[to] < dist[v]) continue;
			ans = min(ans, dist[to] + dist[v] + 1);
			if (dist[to] > dist[v] + 1) {
				dist[to] = dist[v] + 1;
				b.emplace_back(to);
			}
		}
	}



	return ans;
}

void solve() {
	scan();
	int res = inf;
	for(int i = 1;i <= 1e3;i++) res = min(res, bfs(i));
	if (res == inf) cout << -1;
	else cout << res;
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