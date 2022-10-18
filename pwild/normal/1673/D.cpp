#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int MOD = 1e9 + 7;

i64 solve() {
	i64 bstart, bstep, bcount, cstart, cstep, ccount;
	cin >> bstart >> bstep >> bcount >> cstart >> cstep >> ccount;

	i64 bend = bstart + (bcount-1)*bstep;
	i64 cend = cstart + (ccount-1)*cstep;

	if ((cstart-bstart)%bstep != 0) return 0;
	if (cstep % bstep != 0) return 0;
	if (cstart < bstart || bend < cend) return 0;

	i64 cprev = cstart - cstep, cnext = cend + cstep;
	if (cprev < bstart || cnext > bend) return -1;

	i64 res = 0;
	auto consider = [&](i64 astep) {
		if (lcm(astep,bstep) != cstep) return;
		i64 k = cstep/astep;
		res = (res + k*k) % MOD;
	};

	for (i64 d = 1; d*d <= cstep; d++) if (cstep%d == 0) {
		consider(d);
		if (d < cstep/d) consider(cstep/d);
	}
	return res;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		cout << solve() << '\n';
	}
}