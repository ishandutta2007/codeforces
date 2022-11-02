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
    	bool bad = false;
    	vector<int> res;
    	if (n % 2 == k % 2) {
    		if (n < k) bad = true;
    		for(int i = 0;i < k - 1;i++) res.emplace_back(1);
    		res.emplace_back(n - k + 1);
    	}else{
    		if (n % 2 == 1) bad = true;
    		else {
    			if (n < 2 * k) bad = true;
    			for(int i = 0;i < k - 1;i++) res.emplace_back(2);
    			res.emplace_back(n - 2 * (k - 1));
    		}
    	}
    	if (bad) cout << "NO" << endl;
    	else {
    		cout << "YES" << endl;
    		for(int i : res) cout << i << " ";
    		cout << endl;
    	}
    }
}