#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
string g[400];

void solve() {
	cin >> n;
	vector<int> x, y;
	for (int i=0; i<n; ++i) {
		cin >> g[i];
		for (int j=0; j<n; ++j)
			if (g[i][j]=='*')
				x.push_back(i), y.push_back(j);
	}
	if (x[0]==x[1])
		x[1]=x[0]==0;
	if (y[0]==y[1])
		y[1]=y[0]==0;
	for (int i : x)
		for (int j : y)
			g[i][j]='*';
	for (int i=0; i<n; ++i)
		cout << g[i] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}