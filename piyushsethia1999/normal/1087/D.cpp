#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(16);
	int n; cin >> n;
	long double s; cin >> s;
	vector<vector<int> > adj(n); for (int o = 0; o < n - 1; o++) { int x, y; cin >> x >> y; x--; y--; adj[x].pb(y); adj[y].pb(x); }
	int le = 0;
	for (int i = 0; i < n; ++i)
		if (adj[i].size() == 1)
			le++;
	s = (s * (2.0l)) / (le * 1.0l);
	cout << s << "\n";
}