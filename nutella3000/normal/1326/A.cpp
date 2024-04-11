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
    	if (n == 1) cout << -1 << '\n';
    	else{
    		for(int i = 0;i < n - 1;i++) cout << 3;
    		cout << 4 << '\n';
    	}
    }
}