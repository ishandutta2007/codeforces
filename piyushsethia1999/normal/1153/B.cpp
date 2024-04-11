#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	int h; cin >> h;
	vector<int> a(m); for (int o = 0; o < m; o++) { cin >> a[o]; }
	vector<int> b(n); for (int o = 0; o < n; o++) { cin >> b[o]; }
	std::vector<std::vector<int> > gr(n, std::vector<int> (m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> gr[i][j];
			if (gr[i][j] == 1) {
				gr[i][j] = min(a[j], b[i]);
			} 
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) 
			cout << gr[i][j] << " ";
		cout << "\n";
	}

}