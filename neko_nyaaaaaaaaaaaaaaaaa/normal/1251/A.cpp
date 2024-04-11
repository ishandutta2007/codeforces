#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
	    string s; cin >> s;
	    set<char> ans;
	    int cur = 0;
	    char ss = ' ';
	    for (char c: s) {
	        if (c == ss) cur++;
	        else {
	            if (cur % 2) ans.insert(ss);
	            ss = c; cur = 1;
	        }
	    }
	    if (cur % 2) ans.insert(s.back());
	    for (char c: ans) cout << c; cout << '\n';
	}

 	return 0;
}