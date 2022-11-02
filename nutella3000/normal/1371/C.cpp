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
    	int a, b, n, m;
    	cin >> a >> b >> n >> m;
    	int q = min(n, abs(a - b));
    	n -= q;
    	if (a > b) a -= q;
    	else b -= q;

    	q = min(n, m);
    	a -= q;
    	b -= q;
    	n -= q;
    	m -= q;

    	if (n == 0) {
    		if (a > b) b -= m;
    		else a -= m;
    	}else {
    		b -= (n + 1) / 2;
    		a -= n / 2;
    	}

    	if (a < 0 || b < 0) cout << "No";
    	else cout << "Yes";
    	cout << endl;
    }
}