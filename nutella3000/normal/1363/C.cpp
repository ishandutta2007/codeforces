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
    	int n, x;
    	cin >> n >> x;
    	int cnt = 0;
    	for(int i = 0;i < n - 1;i++) {
    		int v1, v2;
    		cin >> v1 >> v2;
    		if (v1 == x) cnt++;
    		if (v2 == x) cnt++;	
    	}

    	if (cnt > 1) {
    		if (n % 2 == 0) cout << "Ayush";
    		else cout << "Ashish";
    	}else cout << "Ayush";
    	cout << endl;
    }
}