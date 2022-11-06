#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	std::vector<int> sl;
	std::vector<int> ov;
	sl.pb(1000000);
	ov.pb(1);
	int cn = 0;
	int spe = 0;
	for (int i = 1; i <= n; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			cin >> spe;
			while (spe > sl.back()) {
				sl.pop_back();
				cn++;
			}  
		} else if (t == 2) {
			while (!(ov.back())) {
				ov.pop_back();
				cn++;
			}
		} else if (t == 3) {
			int s; cin >> s;
			if (spe > s) cn++;
			else sl.pb(s);
		} else if (t == 4) {
			ov.pb(1);
		} else if (t == 5) {
			sl.pb(1000000);
		} else {
			ov.pb(0);
		}
	}
	cout << cn;
}