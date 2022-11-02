#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e9 + 7;





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
    	int x1, y1, x2, y2;
    	cin >> x1 >> y1 >> x2 >> y2;
    	int n, m;
    	n = x2 - x1 + 1;
    	m = y2 - y1 + 1;

    	if (n > m) swap(n, m);

    	int res = (n - 1) * (n - 2) + (n - 1) * (m - (n - 1));

    	cout << res + 1 << endl;
    }
}