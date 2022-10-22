#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>

ll ans=0, n, m, x[200000];
queue<int> q;
map<int, int> dist;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> x[i];
		q.push(x[i]);
		dist[x[i]] = 0;
	}
	
	vector<int> sol;
	while (m) {
		int x = q.front();
		q.pop();
		if (dist[x]) {
			ans += dist[x];
			sol.push_back(x);
			m--;
		}
		if (dist.find(x-1)==dist.end()) {
			dist[x-1] = dist[x]+1;
			q.push(x-1);
		}
		if (dist.find(x+1)==dist.end()) {
			dist[x+1] = dist[x]+1;
			q.push(x+1);
		}
	}
	cout << ans << '\n';
	for (int i:sol)
		cout << i << ' ';
	return 0;
}