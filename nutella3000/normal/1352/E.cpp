#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e11 + 7;



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
    	vector<bool> good(n + 1);
    	vector<int> a(n);
    	for(int i = 0;i < n;i++) cin >> a[i];

    	for(int i = 0;i < n;i++) {
    		int q = 0;
    		for(int j = i;j < n;j++) {
    			q += a[j];
    			if (q > n) break;
    			if (j != i) good[q] = true;
    		}
    	}

    	int res = 0;
    	for(int i : a) res += good[i];

    	cout << res << endl;
    }
}