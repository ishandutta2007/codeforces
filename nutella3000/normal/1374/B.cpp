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
    	int cnt1 = 0, cnt2 = 0;
    	while(n % 2 == 0) {
    		n/= 2;
    		cnt1++;
    	}

    	while(n % 3 == 0) {
    		n /= 3;
    		cnt2++;
    	}

    	if (n != 1 || cnt1 > cnt2) cout << -1 << endl;
    	else cout << 2 * cnt2 - cnt1 << endl;
    }
}