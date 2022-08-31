#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	while (q--) {
		int u, v;
		cin >> u >> v;

		if (u > v) {
			cout << "NO\n";
			continue;
		}

		while (u > 0 && __builtin_clz(u) == __builtin_clz(v)) {
			int bit = 32 - __builtin_clz(u) - 1;
			u ^= 1 << bit, v ^= 1 << bit;
		}

		bitset<30> s(u), t(v);
		bool possible = true;
		for (int i = 0, c = 0; i < 30; i++) {
			if (t[i]) {
				int cc = 0;
				for (int j = 0; j <= i; j++) {
					cc += s[j];
				}
				c += 1;
				possible &= cc >= c;
			}
		}
		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}