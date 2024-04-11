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
		int n;
		cin >> n;
		if (n==1) {
			cout << "1\n";
			continue;
		}
		if (n==2) {
			cout << "-1\n";
			continue;
		}
		int cnt=1;
		vector<vector<int>> ans(n, vector<int>(n));
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				if ((i+j)%2==0)
					ans[i][j]=cnt++;
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				if ((i+j)%2==1)
					ans[i][j]=cnt++;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j)
				cout << ans[i][j] << " ";
			cout << "\n";
		}
	}
	return 0;
}