#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
vector<int> pr = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};

struct xor_basis{
	int d, sz;
	vector<int> basis;

	xor_basis(int d) {
		this->d = d;
		sz = 0;
		basis.resize(d);
	}

	bool add(int mask) {
		if (mask == 0) return 0;
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
	int ans = 1;

	xor_basis xrb(19);
	while (n--) {
		int x; cin >> x;
		int mask = 0;
		for (int i = 0; i < 19; i++) {
			while ((x % pr[i]) == 0) {
				x /= pr[i];
				mask ^= (1 << i);
			}
		}
		if (!xrb.add(mask)) ans = (ans * 2) % M;
	}
	ans--;

	cout << (ans + M) % M << '\n';

	return 0;
}