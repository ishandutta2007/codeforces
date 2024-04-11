#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	string s; cin >> s;
	int n = s.size();
	int k = 0;
	for (char c: s) k += (c == 'a');
	cout << min(n, k*2 - 1);
	
	return 0;
}