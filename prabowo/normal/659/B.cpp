#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <pair <int, string> > v[100002];

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	string s;
	int idx;
	int sc;
	for (int i=0; i<n; i++) {
		cin >> s >> idx >> sc;
		v[--idx].push_back (make_pair (sc, s));
	}
	
	for (int i=0; i<m; i++) {
		sort (v[i].begin(), v[i].end());
		if (v[i].size() > 2 && v[i][v[i].size() - 2].first == v[i][v[i].size() - 3].first) cout << "?\n";
		else cout << v[i][v[i].size() - 1].second << " " << v[i][v[i].size() - 2].second << "\n";
	}
	
	return 0;
}