#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n;
map<string, vector<string>> adj;

int dfs(string start="polycarp", int depth=1) {
	int mx = depth;
	for (string s : adj[start])
		mx = max(mx, dfs(s, depth+1));
	return mx;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		string a, b;
		cin >> a >> b >> b;
		transform(a.begin(), a.end(), a.begin(), ::tolower);
		transform(b.begin(), b.end(), b.begin(), ::tolower);
		adj[b].push_back(a);
	}
	
	cout << dfs();
	return 0;
}