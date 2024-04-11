#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;



signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < m;j++) {
				if (i == 0 && j == 0) cout << "W";
				else cout << "B";
			}
			cout << '\n';
		}
	}
}