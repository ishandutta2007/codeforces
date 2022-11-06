#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n;
	cin >> n;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	int q;
	cin >> q;
	std::vector<int> lasup(n, 0);
	std::vector<int> v;
	for (int i = 0; i < q; ++i) {
		int c;
		cin >> c;
		if (c == 1) {
			int in, x;
			cin >> in >> x; in--;
			lasup[in] = v.size();
			a[in] = x;
		} else {
			int x;
			cin >> x;
			v.pb(x);
		}
	}
	for (int i = ((int)v.size()) - 2; i >= 0; --i) {
		v[i] = max(v[i], v[i + 1]);
	} 
	for (int i = 0; i < n; ++i) {
		if (lasup[i] != v.size()) {
			a[i] = max(a[i], v[lasup[i]]);
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
}