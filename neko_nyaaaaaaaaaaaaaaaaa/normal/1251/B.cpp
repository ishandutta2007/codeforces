#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
	    int n; cin >> n;
	    int odd = 0;
	    int z = 0, o = 0;
	    int ans = n;
	    while (n--) {
	        string s; cin >> s;
	        if (s.size() % 2) odd = 1;
	        for (char c: s) if (c == '1') o++; else z++;
	    }
	    
	    if (odd) {
	        cout << ans << '\n';
	    } else {
	        if (z % 2) cout << ans-1 << '\n';
	        else cout << ans << '\n';
	    }
	}

 	return 0;
}