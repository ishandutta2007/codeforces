#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

void imult(ll& lhs, const ll& rhs) {
	lhs = ((lhs % mod) * (rhs % mod)) % mod;
}

void iadd(ll& lhs, const ll& rhs) {
	lhs = ((lhs%mod) + (rhs%mod)) % mod;
}

void isubt(ll& lhs, const ll& rhs) {
	ll ret = (lhs - rhs) % mod;
	lhs = ret + (ret < 0 ? mod : 0);
}

ll bpw(const ll& lhs, const ll& rhs) {
	if (rhs == 0)return 1;
	ll ret = bpw(lhs, rhs >> 1);
	imult(ret, ret);
	if (rhs & 1) imult(ret, lhs);
	return ret;
}

ll inv(const ll& x) {
	return bpw(x, mod - 2);
}

ll mult(const ll& lhs, const ll& rhs) {
	return ((lhs % mod) * (rhs % mod)) % mod;
}

ll add(const ll& lhs, const ll& rhs) {
	return ((lhs%mod) + (rhs%mod)) % mod;
}

ll subt(const ll& lhs, const ll& rhs) {
	ll ret = (lhs - rhs) % mod;
	return ret + (ret < 0 ? mod : 0);
}

ll div(const ll& lhs, const ll& rhs) {
	return mult(lhs, inv(rhs));
}


const int sz = 1e3 + 5;//CHANGE
ll dp[2][sz][sz], dpp[2][sz][sz];//right left
int n, k;

ll query(int layer, int i, int j, bool left) {
	if (i > j)
		return 0;
	else if (!i)
		return dpp[left][layer][j];
	else
		return subt(dpp[left][layer][j], dpp[left][layer][i - 1]);
}

void prec() {
	for (int tk = 1; tk <= k; tk++) {
		for (int i = 0; i < n; i++) {
			dp[0][tk][i] = add(1, query(tk - 1, i + 1, n - 1, 1));
			dp[1][tk][i] = add(1, query(tk - 1, 0, i - 1, 0));
			foru(j, 0, 2) {
				if (i)
					dpp[j][tk][i] = add(dp[j][tk][i], dpp[j][tk][i-1]);
				else
					dpp[j][tk][i] = dp[j][tk][i];
			}
		}
	}
}

void solve() {
	cin >> n >> k;
	prec();
	cout << dp[0][k][0] + (k != 1) << '\n';
}

int main() {
	fast;
	prec();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}