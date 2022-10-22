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
		vector<int> d;
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				d.push_back(max({i+j, i+m-1-j, n-1-i+j, n-1-i+m-1-j}));
		sort(d.begin(), d.end());
		for (int i : d)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}