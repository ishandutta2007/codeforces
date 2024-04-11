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
    	int n, k;
    	cin >> n >> k;
    	map<int, int> cnt;
    	for(int i = 0;i < n;i++) {
    		int v;
    		cin >> v;
    		v = (k - v % k) % k;
    		if (v == 0) continue;
    		cnt[v]++;
    	}

    	int res = 0;
    	for(auto i : cnt) {
    		res = max(res, (i.second - 1) * k + i.first + 1);
    	}

    	cout << res << endl;
    }
}