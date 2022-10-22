#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		for (int i=0; i<n; ++i)
			for (int& j : a[i])
				cin >> j;
		int bad=-1;
		for (int j=0; j<m; ++j) {
			bool ok=1;
			for (int i=0; i<n; ++i) {
				if (j&&a[i][j]<a[i][j-1]||j+1<m&&a[i][j]>a[i][j+1]) {
					ok=0;
					break;
				}
			}
			if (!ok) {
				bad=j;
				break;
			}
		}
		if (bad==-1) {
			cout << "1 1\n";
			continue;
		}
		auto Swap=[&](int x, int y) {
			for (int i=0; i<n; ++i)
				swap(a[i][x], a[i][y]);
		};
		auto isBad=[&](int i) {
			assert(0<=i&&i+1<m);
			for (int j=0; j<n; ++j)
				if (a[j][i]>a[j][i+1])
					return 1;
			return 0;
		};
		int tot=0;
		for (int i=0; i+1<m; ++i)
			tot+=isBad(i);
		auto Consider=[&](int x, int y) {
			int change=0;
			set<int> s;
			for (int i : {x-1, x, y-1, y})
				if (0<=i&&i+1<m)
					s.insert(i);
			for (int i : s)
				change-=isBad(i);
			Swap(x, y);
			for (int i : s)
				change+=isBad(i);
			Swap(x, y);
			return tot+change==0;
		};
		bool found=0;
		for (int i : {bad-1, bad, bad+1}) {
			if (i<0||i>=m)
				continue;
			for (int j=0; j<m; ++j) {
				//cout << i << " " << j << endl;
				if (i!=j&&Consider(i, j)) {
					found=1;
					cout << i+1 << " " << j+1 << "\n";
					break;
				}
			}
			if (found) break;
		}
		if (!found) cout << "-1\n";
	}
	return 0;
}