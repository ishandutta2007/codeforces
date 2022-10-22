#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, k;
vector<int> a, b, adj[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	a.resize(m), b.resize(m);
	for (int i=0; i<m; ++i) {
		cin >> a[i] >> b[i], a[i]--, b[i]--;
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}

	queue<int> q;
	q.push(0);
	vector<int> d(n, -1);
	d[0]=0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u])
			if (d[v] == -1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
	}

	vector<vector<int>> inc(n);
	for (int i=0; i<m; ++i) {
		if (d[a[i]] + 1 == d[b[i]])
			inc[b[i]].push_back(i);
		if (d[b[i]] + 1 == d[a[i]])
			inc[a[i]].push_back(i);
	}

	vector<int> f(n);
	vector<string> result;

	while(k--) {
		string s(m, '0');
		for (int j = 1; j < n; j++)
			s[inc[j][f[j]]] = '1';
		result.push_back(s);
		bool ok = false;
		for (int j = 1; j < n; j++)
			if (f[j] + 1 < inc[j].size()) {
				ok = true;
				f[j]++;
				break;
			} else
				f[j] = 0;
		if (!ok)
			break;
	}
	cout << result.size() << '\n';
	for(string s : result)
		cout << s << '\n';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/