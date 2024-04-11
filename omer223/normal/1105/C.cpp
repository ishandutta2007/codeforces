#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <set>
#include <queue>
#include <map>

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
const ll sz = 3e5;
ll rem[3],n,l,r, dp[sz][3];

ll calc(ll x, int md) {
	if (x < md)return 0;
	return (x - md) / 3 + 1;
}

int main() {
	fast;
	cin >> n >> l >> r;
	foru(i, 0, 3)dp[0][i] = calc(r, i) - calc(l - 1, i);
	foru(i, 1, n) {
		foru(j, 0, 3) {
			foru(k, 0, 3) {
				iadd(dp[i][j], mult(dp[i - 1][k], dp[0][(j - k + 3) % 3]));
			}
		}
	}
	cout << dp[n-1][0] << '\n';
	return 0;
}