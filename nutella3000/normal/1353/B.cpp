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
    	int n, k;
    	cin >> n >> k;
    	vector<int> a(n), b(n);
    	for(int i =0;i < n;i++) cin >> a[i];
    	for(int i = 0;i < n;i++) cin >> b[i];
    	sort(a.begin(), a.end());
    	sort(b.begin(), b.end());
    	int res = 0;
    	for(int i = 0;i < n;i++) res += a[i];
    	for(int i = 0;i < k;i++) {
    		if (a[i] > b[n - i - 1]) break;
    		res += b[n - i - 1] - a[i];
    	}
    	cout << res << endl;
    }
}