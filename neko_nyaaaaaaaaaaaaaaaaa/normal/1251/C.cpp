#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
	    string s; cin >> s;
	    vector<char> o, e;
	    for (char c: s) {
	        if ((c - '0') % 2) o.push_back(c);
	        else e.push_back(c);
	    }
	    reverse(o.begin(), o.end());
	    reverse(e.begin(), e.end());
	    
	    string ans;
	    while (o.size() || e.size()) {
	        if (o.empty()) {
	            ans.push_back(e.back()); e.pop_back();
	        } else if (e.empty()) {
	            ans.push_back(o.back()); o.pop_back();
	        } else {
	            if (o.back() < e.back()) {
	                ans.push_back(o.back()); o.pop_back();
	            } else {
	                ans.push_back(e.back()); e.pop_back();
	            }
	        }
	    }
	    cout << ans << '\n';
	}

 	return 0;
}