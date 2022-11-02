#include <bits/stdc++.h>
using namespace std;
  
//#define int long long
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
    	int n, a = 1, b = 1;
    	cin >> n;

    	vector<int> res;
    	while(true) {
    		if (a + b <= n && n <= 2 * a + b) {
    			res.emplace_back(n - b - a);
    			break;
    		}
    		if (n <= b + 4 * a - 1) {
    			n -= b;
    			res.emplace_back(n / 2 - a);
    			a += n / 2 - a;
    			n -= a;
    			res.emplace_back(n - a);
    			break;
    		}

    		res.emplace_back(a);
    		a *= 2;
    		b += a;
    	}

    	cout << res.size() << endl;
    	for(int i : res) cout << i << " ";
    	cout << endl;
    }
}