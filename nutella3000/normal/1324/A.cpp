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
  		int sum = 0;
  		bool o[2];
  		o[0] = false; o[1] = false;
  		for(int i = 0;i < n;i++) {
  			int v;
  			cin >> v;
  			sum += v;
  			o[v % 2] = true;
  		}
  		if (o[0] && o[1]) cout << "NO";
  		else cout << "YES";
  		cout << '\n';
  	  	}
}