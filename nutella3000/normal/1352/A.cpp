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
    	vector<int> res;
    	int q = 1;
    	while(n > 0) {
    		if (n % 10 != 0) res.emplace_back(q * (n % 10));
    		q *= 10;
    		n /= 10;
    	}

    	cout << res.size() << endl;
    	for(int i : res) cout << i << " ";
    	cout << endl;
    }
}