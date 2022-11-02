#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e11 + 7;

struct comp {
	bool operator()(pii a, pii b) {
		if (a.second - a.first == b.second - b.first) return a.first < b.first;
		else return a.second - a.first > b.second - b.first;
	}
};


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
    	string s;
    	cin >> n >> k >> s;
    	vector<int> dp(n, inf);
    	int q = 0, w = 0;
    	for(int i = 0;i < n;i++) {
    		if (i >= k) q -= s[i - k] - '0';

    		int e = 0;
    		if (i >= k) e = dp[i - k];
    		
    		dp[i] = q + '1' - s[i] + min(e, w - q);

    		q += s[i] - '0';
    		w += s[i] - '0';
    	}
    	
    	q = 0;
    	for(int i = n - 1;i >= 0;i--) {
    		dp[i] += q;
    		q += s[i] - '0';
    	}

    	/*for(int i = 0;i < n;i++) cout << dp[i] << " ";
    	cout << endl;*/

    	int res = q;
    	for(int i = 0;i < n;i++) res = min(res, dp[i]);
    	cout << res << endl;
    }
}