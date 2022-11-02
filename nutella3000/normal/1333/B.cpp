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
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		vector<int> cnt(3);
		for(int i = 0;i < n;i++) {
			cin >> a[i];
			cnt[a[i] + 1]++;
		}
		for(int i = 0;i < n;i++) cin >> b[i];

		bool bad = false;

		for(int i = n - 1;i >= 0;i--) {
			cnt[a[i] + 1]--;
			if (a[i] < b[i] && cnt[2] == 0) bad = true;
			else if (a[i] > b[i] && cnt[0] == 0) bad = true;
		}

		if (bad) cout << "NO";
		else cout << "YES";
		cout << '\n';
	}
}