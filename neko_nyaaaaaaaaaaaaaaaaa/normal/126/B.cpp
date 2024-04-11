
#include <bits/stdc++.h>
using namespace std;
 
vector<int> prefix_function(string s) {
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}
 
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	string s; cin >> s;
	int n = s.size();
 
	vector<int> pi = prefix_function(s);
	vector<int> borders(n), middles(n);
	for (int i = 1; i < n-1; i++) {
		middles[pi[i]] = 1;
	}
	int cur = pi.back();
	while (cur != 0) {
		borders[cur] = 1;
		cur = pi[cur-1];
	}
 
	for (int i = n-1; i >= 0; i--) {
	    if (middles[i] && borders[i]) {
	        for (int j = 0; j < i; j++) cout << s[j];
	        exit(0);
	    }
	}
	cout << "Just a legend\n";
	
	return 0;
}