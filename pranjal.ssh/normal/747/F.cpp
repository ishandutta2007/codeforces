#include <bits/stdc++.h>
using namespace std;


long long fac[20];
int avail[16];
int final[20];
long long dp[20][16];

long long f(int no, int pos = 0) {
	if (pos == 16) return no == 0;
	long long & ans = dp[no][pos];
	if (~ans) return ans;
	ans = 0;
	for (int i = 0; i <= min(no, avail[pos]); ++i) {
		ans += f(no - i, pos + 1) * (fac[no] / fac[no - i]) / fac[i];
	}
	return ans;
}

void go(int pos, int len, long long k) {
	if (pos == len) {
		assert(k == 0);
		return;
	}
	for (int d = 0; d <= 15; ++d) {
		memset(dp, -1, sizeof dp);
		avail[d]--;
		if (k < f(len - pos - 1)) {
			final[pos] = d;
			go(pos + 1, len, k);
			return;
		}
		k -= f(len - pos - 1);
		avail[d]++;
	}
}
inline char Hex(int x) {
	return x <= 9 ? '0' + x : x - 10 + 'a';
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);

	fac[0] = 1;
	for (int i = 1; i < 20; ++i) fac[i] = fac[i - 1] * i;

	long long k; int t;
	cin >> k >> t; --k;

	for (int i = 0; i <= 15; ++i) avail[i] = t;
	avail[0]--;
	
	memset(dp, -1, sizeof dp);

	for (int l = 1; ; ++l) {
		if (k < 15 * f(l - 1)) {
			for (int d = 1; d <= 15; ++d) {
				if (k < f(l - 1)) {
					avail[0]++;
					avail[d]--;
					final[0] = d;
					go(1, l, k);

					for (int j = 0; j < l; ++j)
						cout << Hex(final[j]);

					cout << "\n";
					return 0;
				}
				k -= f(l - 1);
			}
		}
		k -= 15 * f(l - 1);
	}

	return 0;
}