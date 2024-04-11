#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e18 + 7;


signed main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
  	#endif
 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
    	int n, k;
    	cin >> n >> k;
    	int d = 1;
    	for(int i = 1;i * i <= n;i++) {
    		if (n % i == 0) {
    			if (i <= k) d = max(d, i);
    			if (n / i <= k) d = max(d, n / i);
    		}
    	}

    	cout << n / d << endl;
    }
}