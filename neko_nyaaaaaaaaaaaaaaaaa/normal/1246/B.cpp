#include <bits/stdc++.h>
using namespace std;

const long long MX = 10000000000LL;
vector<int> dv(100001);

void init() {
	for (int i = 2; i <= 100000; i++) {
		if (dv[i]) continue;
		for (int j = i; j <= 100000; j += i) {
			dv[j] = i;
		}
	}
}

vector<long long> generate(long long k) {
	vector<long long> ans(1, 1);
	for (long long i = 2; ; i++) {
		long long tmp = 1;
		for (int j = 0; j < k; j++) {
			tmp *= i;
			if (tmp > MX) return ans;
		}
		ans.push_back(tmp);
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();

	long long n, k; cin >> n >> k;
	vector<long long> powers = generate(k);
	vector<long long> cnt(100001);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		cnt[x]++;
	}

	long long ans = 0;
	for (int j = 1; j <= 100000; j++) {
		if (cnt[j] == 0) continue; 
		// reduce i
		long long i = j;
		long long rd = 1;
		int over = 0;
		while (i > 1) {
			int p = dv[i];
			int pw = 0;
			while (i % p == 0) {
				i /= p;
				pw++;
			}
			pw %= k;
			if (pw == 0) continue;

			pw = k - pw;
			for (int s = 0; s < pw; s++) {
				rd *= p;
				if (rd > 100000) {
					over = 1; break;
				}
			}
			if (over) break;
		}
		//cout << j << ' ' << rd << endl;
		if (over) continue;

		// for each i such that i/rd = power of k
		// that is the answer

		// if i = j
		// then cnt[j]*cnt[j-1]
		// else if i != j
		// then cnt[i]*cnt[j]

		for (int s = 0; s < powers.size(); s++) {
			// take powers[s]*rd and j
			if (powers[s]*rd > 100000) break;
			long long nd = powers[s]*rd;
			if (cnt[nd] == 0) continue;
			if (nd == j) {
				ans += cnt[j]*(cnt[j] - 1);
			} else {
				ans += cnt[j]*cnt[nd];
			}
			
			//cout << j << ' ' << nd << ' ' << ans << endl;
		}
	}
	cout << ans/2 << '\n';

	return 0;
}