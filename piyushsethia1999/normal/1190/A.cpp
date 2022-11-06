#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define int long long
#define se second
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int m; cin >> m;
	int k; cin >> k;
	vector<int> p(m); for (int o = 0; o < m; o++) { cin >> p[o]; }
	p.pb(1000003000000000000ll);
	int in = 0;
	int off = 0;
	int op = 0;
	while (in < m) {
		int page = (p[in] - off + k - 1ll) / k;
		int jn = in;
		while (jn < m + 1 && ((p[jn] - off + k - 1ll) / k == page)) {
			jn++;
		} 
		off += (jn - in);
		op++;
		in = jn;
	} 
	cout << op;
}