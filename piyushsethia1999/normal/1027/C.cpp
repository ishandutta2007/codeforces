#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
#ifdef PIYUSH_HOME
	I_O;
#else
#define print(...) 0
#endif
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
		sort(a.begin(), a.end());
		std::vector<int> s;
		print(a);
		for (int i = 0; i < n; ++i) {
			print(i);
			if (i < (n - 1) && a[i] == a[i + 1])
				s.pb(a[i++]);
		}
		print(s);
		pair<int, int> p = {1, 1000000};
		for (int i = 0; i < (s.size() - 1); ++i)
			if ((s[i] * p.second) > (p.first * s[i + 1]))
				p = {s[i], s[i + 1]};
		cout << p.first << " " << p.second << " " << p.first << " " << p.second << "\n";
	}
}