#include <bits/stdc++.h>
using namespace std;

bool onbit(long long x, int pos) {
	return (x >> pos) & 1;
}

int n, k;
long long f[10], pref[10], dif[10];

bool ok(long long msk) {
	if (msk == 0) return 1;
	int ob = __builtin_popcountll(msk);

	long long need = (1LL << n) - (1LL << (n-ob));
	return msk == need;
}

void brute(int i, long long msk) {
	if (i == k) {
		if (!ok(msk)) {
			cout << "REJECTED\n";
			exit(0);
		} 
	} else {
		int cnt = __builtin_popcountll(f[i] & msk);
		int cd = dif[i];
		msk &= (~f[i]);

		if (cnt == 0) brute(i+1, msk);
		for (int j = n-1; j >= 0; j--) {
			if (onbit(f[i], j) && cnt) {
				cnt--; msk |= (1LL << j);
				if (cnt == 0) brute(i+1, msk);
			} else if (onbit(f[i], j) && cd) {
				cd--; msk |= (1LL << j); 
				brute(i+1, msk);
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	if (n == 1) {
		cout << "ACCEPTED\n";
		exit(0);
	}

	long long mskp = 0;
	for (int i = 0; i < k; i++) {
		long long msk = 0;
		int x; cin >> x;
		while (x--) {
			int y; cin >> y; y--;
			msk |= (1LL << y);
		}

		f[i] = msk;
		for (int j = 0; j < n; j++) {
			if (onbit(msk, j) && !onbit(mskp, j)) {
				dif[i]++;
			}
		}
		mskp |= msk;
		pref[i] = mskp;
	}

	if (mskp != (1LL << n) - 1) {
		cout << "REJECTED\n";
	} else {
		brute(0, 0);
		cout << "ACCEPTED\n";
	}

	return 0;
}