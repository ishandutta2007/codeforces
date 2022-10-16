#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;

struct xor_basis{
	int d, sz;
	vector<int> basis;

	xor_basis(int d) {
		this->d = d;
		sz = 0;
		basis.resize(d);
	}

	bool add(int mask) {
		for (int i = 0; i < d; i++) {
			if (mask & (1 << i)) {
				if (!basis[i]) {
					basis[i] = mask; sz++;
					return 1;
				}
				mask ^= basis[i];
			}
		}
		return 0;
	}
};

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	xor_basis xrb(30);
	int prf = 0;
	while (n--) {
		int a; cin >> a;
		prf ^= a;

		xrb.add(prf);
	}

	if (!prf) {
		cout << "-1\n";
	} else {
		int ans = 0;
		for (int i = 0; i < 30; i++) {
			ans += (xrb.basis[i] > 0);
		}
		cout << ans << '\n';
	}


	return 0;
}