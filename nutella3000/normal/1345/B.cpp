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
    	int n;
    	cin >> n;
    	int res = 0;
    	//int it = 0;
    	while(n > 1) {
    		//it++;
    		//if (it == 100) return 0;
    		int l = 0;
    		int r = 1e9;

    		while(r - l > 1) {
    			int mid = ((l + r) >> 1);

    			int cnt = 3 * mid * (mid + 1) / 2 - mid;

    			if (cnt > n) r = mid;
    			else l = mid;
    		}

    		res++;
    		n -= 3 * l * (l + 1) / 2 - l;
    	}

    	cout << res << endl;
    }
}