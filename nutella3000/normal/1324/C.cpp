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
  		string s;
  		cin >> s;
  		int n = s.size();
  		int d = 0;
  		int prev = -1;
  		for(int i = 0;i <= n;i++) {
  			d = max(d, i - prev);
  			if (i != n && s[i] == 'R') prev = i;
  		}

  		cout << d << '\n';

  	}
}