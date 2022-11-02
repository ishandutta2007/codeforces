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
    	vector<int> a(n), b(n);
    	for(int i = 0;i < n;i++) cin >> a[i];
    	for(int i = 0;i < n;i++) cin >> b[i];
 
    	vector<bool> used(n);
 
		bool bad = false;
 
    	for(int i = 0;i < n / 2;i++) {
    		for(int j = 0;j < n / 2;j++) {
    			if (used[j]) {
    				if (j == n / 2 - 1) bad = true;
    				continue;
    			}
    			bool good = a[j] == b[i] && a[n - j - 1] == b[n - i - 1];
    			good |= a[j] == b[n - i - 1] && a[n - j - 1] == b[i];
    			if (good) {
    				used[j] = true;
    				break;
    			}
    			if (j == n / 2 - 1) bad = true;
    		}
    	}
 
 
    	if (n % 2 == 1 && a[n / 2] != b[n / 2]) bad = true;
    	if (!bad) cout << "Yes" << endl;
    	else cout << "No" << endl;
    }
 
}