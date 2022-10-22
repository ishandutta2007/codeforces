#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, ans=0;
vector<pair<int, int>> a;
map<pair<int, int>, bool> visited;
map<pair<int, int>, vector<pair<int, int>>> adj;

void dfs(pair<int, int> p) {
	if (visited[p]) return;
	visited[p]=1;
	for (auto x:adj[p])
		dfs(x);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		pair<int, int> point;
		cin >> point.first >> point.second;
		a.push_back(point);
		visited[point]=0;
	}
	for (int i=0; i<n; ++i) {
		for (int j=i+1; j<n; ++j) {
			if (a[i].first==a[j].first||a[i].second==a[j].second) {
				adj[a[i]].push_back(a[j]);
				adj[a[j]].push_back(a[i]);
			}
		}
	}
	
	int cnt=-1;
	for (auto i:a) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}