#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int maxint = (1ll << 32ll) - 1ll;
	int n; cin >> n;
	bool overflow = false;
	int val = 0;
	std::vector<int> v;
	v.pb(1);
	int times = 1;
	int stopat = -1;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		if (s == "add") {
			if (times > (maxint)) {
				overflow = true;
				break;
			} else {
				val += times;
			}
		} else if (s == "for") {
			int t; cin >> t;
			v.pb(t);
			if (times <= maxint) {
				times *= t;
				if (times > maxint) {
					stopat = v.size();
				} 
			}
		} else {
			if (stopat == v.size()) {
				stopat = -1;
			} 
			if (stopat == -1) {
				times /= v.back();
			} 
			v.pop_back();
		}
	}
	if (overflow || val > maxint) {
		cout << "OVERFLOW!!!";
	} else {
		cout << val;
	}
}