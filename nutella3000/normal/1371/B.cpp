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
    	int n, r;
    	cin >> n >> r;
    	int q = min(n - 1, r);
    	int w = max(0ll, r - n + 1);
    	int res = (q + 1) * q / 2 + min(w, 1ll);
    	cout << res << endl; 
    }
}