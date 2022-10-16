#include <bits/stdc++.h>
using namespace std;

#define int long long

bool pl(string s) {
	string t = s;
	reverse(s.begin(), s.end());
	return s == t;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    set<char> st;
    for (char c: s) {
		st.insert(c);
    }
    if (st.size() == 1) {
		cout << "Impossible";
		return 0;
    }

    int n = s.size();
    if (n % 2) {
		st.clear();
		for (int i = 0; i < n/2; i++) {
			st.insert(s[i]);
		}
		if (st.size() == 1) {
			cout << "Impossible";
			return 0;
		} else {
			cout << 2; return 0;
		}
    } else {
    	string t = s;
		for (int i = 1; i < n; i++) {
			rotate(s.begin(), s.begin()+1, s.end());
			if (pl(s) && s != t) {cout << "1\n"; cerr << s; return 0;}
		}
		cout << 2;
    }

 	return 0;
}