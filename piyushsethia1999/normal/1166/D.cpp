#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int q; cin >> q;
	while (q--) {
		int a; cin >> a;
		int b; cin >> b;
		int m; cin >> m;
		if (a == b) {
			cout << 1 << " " << a << "\n";
			continue;
		} 
		int ta, tb;
		bool ok = false;
		std::vector<int> r;
		for (int i = 0ll; i < 49ll; ++i) {
			r.clear();
			int diff = b - ((a + 1ll) * (1ll << i));
			if (diff < 0ll) break; 
			r.resize(i + 1ll, 0ll);
			for (int j = i; j >= 0; --j) {
				int u;
				if (j)
					u = (1ll << (j - 1ll));
				else
					u = 1ll;
				int y = min(diff / u, m - 1ll); 
				diff -= (y * u);
				r[j] = y;
			}
			if (diff == 0) {
				ok = true;
				break;
			} 
		}
		if(!ok) cout << -1 << "\n";
		else {
			reverse(r.begin(), r.end());
			cout << r.size() + 1ll << " ";
			std::vector<int> v(r.size() + 1ll);
			v[0] = a;
			for (int i = 1ll; i < r.size() + 1ll; ++i) {
				v[i] += a;
			}
			for (int i = 1ll; i < r.size() + 1ll; ++i) {
				v[i] += (r[i - 1] + 1ll);
				for (int j = i + 1ll; j < r.size() + 1ll; ++j)
					v[j] += v[i];
			}
			for (int i = 0; i < r.size() + 1ll; ++i)
				cout << v[i] << " ";
			cout << "\n";
		}
	}
}