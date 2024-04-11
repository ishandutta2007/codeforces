#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef long double ld;
typedef pair <ld, ld> pld;

const int sz = 505;
const ll mod = 998244353;
ll prec[sz][sz], sum[sz][sz];
ll dp[sz][sz], prv[sz][sz];
ll tot = 0;
int n, l;

inline ll add(const ll& lhs, const ll& rhs) {
	return (lhs + rhs) % mod;
}

inline ll neg(const ll& x) {
	ll ret = (-x) % mod;
	if (x < 0) {
		ret += mod;
	}
	return ret;
}

inline ll subt(const ll& lhs, const ll& rhs) {
	return add(lhs, neg(rhs));
}

inline ll mult(const ll& lhs, const ll& rhs) {
	return (lhs * rhs) % mod;
}

int main() {
	fast;
	cin >> n >> l;
	for (int j = 1; j <= n; j++) {
		sum[1][j] = 2;
	}
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			for (int k = 1; k <= n; k++) {
				dp[i][k] = 0;
			}
		}
		dp[1][1] = 2;
		for (int i = 2; i <= n; i++) {
			for (int k = 1; k <= j; k++) {
				if (k == 1) {
					dp[i][k] = sum[i - 1][j];
				}
				else {
					dp[i][k] = dp[i - 1][k - 1];
				}
				sum[i][j] = add(sum[i][j], dp[i][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == 1) {
				prec[i][j] = sum[i][j];
			}
			else {
				prec[i][j] = subt(sum[i][j], sum[i][j - 1]);
				prec[i][j] %= mod;
				if (prec[i][j] < 0)prec[i][j] += mod;
			}
		}
	}
	ll tot = 0;
	for (int i = 1; i <= n && i <= l; i++) {
		ll myBound = min(n, l / i);
		if (i * myBound == l)myBound--;
		tot = add(tot, mult(prec[n][i], sum[n][myBound]));
	}
	tot = mult(tot, 499122177LL);
	cout << tot << '\n';
	return 0;
}