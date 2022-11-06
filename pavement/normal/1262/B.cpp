#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> n;
		int p[n], prev = -1;
		set<int> taken;
		for (int i = 1; i <= n; i++) taken.insert(i);
		bool inv = false;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (inv) continue;
			if (x > prev) {
				p[i] = x;
				auto it = taken.find(x);
				if (it == taken.end()) inv = true;
				else taken.erase(taken.find(x));
			} else {
				if (taken.size() == 0 || *taken.begin() > x) {
					inv = true;
					continue;
				}
				p[i] = *taken.begin();
				taken.erase(taken.begin());
			}
			prev = x;
		}
		if (inv) cout << "-1\n";
		else {for (int i : p) cout << i << ' ';
		cout << '\n';}
	}
}