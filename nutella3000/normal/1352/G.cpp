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
    	if (n <= 3) {
    		cout << -1 << endl;
    		continue;
    	}

    	if (n % 2 == 0) {
    		for(int i = 1;i <= n - 5;i+= 2) cout << i << " ";
    		cout << n - 1 << " " << n - 3 << " ";
    		for(int i = n;i >= 2;i-= 2) cout << i << " ";
    	}else {
    		for(int i = 1;i <= n;i+= 2) cout << i << " ";

    		cout << n - 3 << " " << n - 1 << " ";
    		for(int i = n - 5;i >= 2;i-= 2) cout << i << " ";
    	}
    	cout << '\n';
    }
}