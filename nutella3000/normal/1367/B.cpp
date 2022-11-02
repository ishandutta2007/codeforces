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
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	int res = 0;
    	int cnt = 0;
    	for(int i = 0;i < n;i++) {
    		int v;
    		cin >> v;
    		v %= 2;
    		if (v != i % 2) res++;
    		if (v == 0) cnt--;
    		else cnt++;
    	}
    	if ((n - 1) % 2 == 0) cnt++;
    	if (cnt != 0) cout << -1 << endl;
    	else cout << res / 2 << endl;
    }
}