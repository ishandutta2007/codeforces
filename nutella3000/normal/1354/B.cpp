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
    	string s;
    	cin >> s;
    	int n = sz(s);

    	vector<vector<int>> pref(3, vector<int>(n));

    	//cout << "fack" << endl;

    	for(int i = 0;i < n;i++) {
    		if (i != 0) {
    			for(int j = 0;j < 3;j++) pref[j][i] = pref[j][i - 1];
    		}
    		pref[s[i] - '1'][i]++;
    	}

    	//cout << "scan" << endl;

    	int res = n + 1;
    	int r = 0;
    	for(int l = 0;l < n;l++) {
    		int q[3];
    		for(int i = 0;i < 3;i++) {
    			if (l == 0) q[i] = 0;
    			else q[i] = pref[i][l - 1];
    		}

    		while(r < n) {
    			bool bad = false;
    			for(int i = 0;i < 3;i++) {
    				if (pref[i][r] - q[i] == 0) bad = true;
    			}
    			if (!bad) break;
    			r++;
    		}

    		if (r == n) break;
    		if (r - l + 1 < res) res = r - l + 1;
    	}

    	if (res == n + 1) cout << 0;
    	else cout << res;
    	cout << endl;
    }
}