#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int m; cin >> m;
	int n; cin >> n;
	bitset<10000> b[m];
	bitset<10000> a;
	bool f = true;
	for (int i = 0; i < m; ++i) {
		int y; cin >> y;
		for (int j = 0; j < y; ++j) {

			int u; cin >> u; u--;
			b[i].set(u);
		}
		for (int j = 0; j < i; ++j) {
			if (((b[i] & (~b[j])) == b[i]) || ((b[j] & (~b[i])) == b[j])) {
				f = false;
				break;
			} 
		}
		if (!f) break; 
	}
	if (f) cout << "possible";
	else cout << "impossible";
}