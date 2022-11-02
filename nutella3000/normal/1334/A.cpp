#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;



signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	int last1 = 0, last2 = 0;
    	bool bad = false;
    	for(int i = 0;i < n;i++) {
    		int v1, v2;
    		cin >> v1 >> v2;
    		if (v1 - last1 < v2 - last2 || v1 < last1 || v2 < last2) bad = true;
    		last1 = v1;
    		last2 = v2;
    	}

    	if (bad) cout << "NO";
    	else cout << "YES";
    	cout << '\n';
    }

}