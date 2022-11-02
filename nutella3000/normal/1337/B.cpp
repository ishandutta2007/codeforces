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
 		int x, n, m;
 		cin >> x >> n >> m;
 		while(x >= 20 && n > 0) {
 			n--;
 			x = x / 2 + 10;
 		}
 		if ((x + 9) / 10 <= m) cout << "YES";
 		else cout << "NO";
 		cout << endl;
 	}
 
}