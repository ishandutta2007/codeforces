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
    	int n, k;
    	cin >> n >> k;
    	vector<vector<int>> a(n, vector<int>(n));

    	int res = 0;
    	if (k % n != 0) res = 2;

    	vector<int> cnt(n);
    	for(int i = 0;i < k % n;i++) cnt[i] = k / n + 1;
    	for(int i = k % n;i < n;i++) cnt[i] = k / n;
    	for(int i = 0;i < n;i++) {
    		int c = k / n;
    		if (i < k % n) c++; // govno

    		int M = 0;
    		int c_m = 0;
    		for(int j = 0;j < n;j++) {
    			if (M == cnt[j]) c_m++;
    			if (M < cnt[j]) {
    				M = cnt[j];
    				c_m = 1;
    			}
    		}

    		for(int j = 0;j < n;j++) {
    			if (cnt[j] == M || (cnt[j] == M - 1 && c_m < c)) {
    				if (c == 0) break;
    				c--;
    				if (cnt[j] == M) c_m--;
    				cnt[j]--;
    				a[i][j] = 1;
    			}
    		}
    	}

    	cout << res << '\n';
    	for(auto i : a) {
    		for(int j : i) cout << j;
    		cout << endl;
    	}

    	//cout << endl;
    }
}