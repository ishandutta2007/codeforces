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
   		int n, m;
   		cin >> n >> m;
   		if (n == 1 || m == 1 || (n == 2 && m == 2)) cout << "YES" << endl;
   		else cout << "NO" << endl;
   	}

}