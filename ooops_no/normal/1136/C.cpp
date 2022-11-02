/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
using namespace std;

#define int long long
#define pb push_back
#define ld long double

signed main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int g[1010][1010];
	int v[1010][1010];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	vector<int> a, b;
	for (int i = 0; i <= 2 * max(n, m); i++) {
		int ii = i;
		int jj = 0;
		a.clear();
		b.clear();
		while (ii >= 0 && jj < 2 * max(n, m)) {
			a.pb(g[ii][jj]);
			b.pb(v[ii][jj]);
			ii--;
			jj++;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}