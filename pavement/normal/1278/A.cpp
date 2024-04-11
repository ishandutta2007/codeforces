#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	string p, h;
	cin >> t;
	while (t--) {
		cin >> p >> h;
		bool b = 0;
		map<char, int> om;
		for (char c : p) om[c]++;
		int l = h.size(), ps = p.size();
		for (int i = 0; i <= l - ps; i++) {
			map<char, int> m;
			for (int j = 0; j < ps; j++)
				m[h[j + i]]++;
			if (m == om) b = 1;
		}
		if (b) cout << "YES\n";
		else cout << "NO\n";
	}	
}