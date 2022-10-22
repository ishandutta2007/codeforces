#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, f[100001], g[100001], h[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> f[i];
	set<int> s;
	for (int i=1; i<=n; ++i) {
		if (f[f[i]]!=f[i]) {
			cout << -1;
			return 0;
		}
		s.insert(f[f[i]]);
	}
	int m=s.size();
	int ind=1;
	for (const int &i:s) {
		g[i]=ind;
		h[ind]=i;
		ind++;
	}
	for (int i=1; i<=n; ++i)
		g[i]=g[f[i]];
	cout << m << '\n';
	for (int i=1; i<=n; ++i)
		cout << g[i] << ' ';
	cout << '\n';
	for (int i=1; i<=m; ++i)
		cout << h[i] << ' ';
	return 0;
}