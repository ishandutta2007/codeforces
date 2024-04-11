#include <bits/stdc++.h>
#define int long long
#pragma O3

using namespace std;

int const inf = 1LL << 60;



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
  		int a[n];
  		for(int i = 0;i < n;i++) cin >> a[i];
  		int cnt[n][n + 1];
  		for(int i = 0;i < n;i++) {
  			for(int j = 0;j <= n;j++) {
  				cnt[i][j] = 0;
  				if (a[i] == j) cnt[i][j] = 1;
  				if (i != 0) cnt[i][j] += cnt[i - 1][j];
			}
  		}

  		bool good = false;
  		for(int i = 0;i < n;i++) {
  			for(int next = i + 2;next < n;next++) {
  				if (a[i] == a[next]) {
  					good = true;
  					break;
  				}
  			}
  		}
  		if (good) cout << "YES";
  		else cout << "NO";
  		cout << '\n';
  	}
}