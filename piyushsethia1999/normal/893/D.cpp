#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int d; cin >> d;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	int acc = 0;
	std::vector<int> ac(n, 0);
	std::vector<int> b(n, 0);
	for (int i = 0; i < n; ++i) {
		acc += a[i];
		ac[i] = acc;
		if (a[i] == 0 && ac[i] < 0)
			b[i] = -ac[i];
	}
	int ma = 0;
	int maa = 1000000000000000ll;
	int cnt = 0;
	int ex = 0;
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		if (b[i]) {
			if (ma >= b[i]) {
				b[i] = 0;
			} else {
				if (maa + b[i] > d) {
					cnt++;
					maa = -1000000000000000ll;
				} else {

				}
				ex += (b[i] - ma);
				ma = b[i];
			}
		}
		maa = max(ac[i], maa);
		if (ac[i] + ex > d) {
			ok = false;
		} 
	}
	if (ok) cout << cnt;
	else cout << -1;
}