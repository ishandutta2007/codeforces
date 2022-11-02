#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <unordered_set>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 5e5;
const ll mod = 998244353;
int n;
ll dp[sz];
ll mem[sz];

inline ll pw(const ll& a, const ll& b) {
	if (!b)return 1;
	ll tmp = pw(a, b >> 1);
	tmp *= tmp;
	tmp %= mod;
	if (b & 1) {
		tmp *= a;
		tmp %= mod;
	}
	return tmp;
}

inline ll inv(ll x) {
	return pw(x, mod - 2);
}


int main() {
	fast;
	cin >> n;
	const ll hf = inv(2), qtr = inv(4);
	dp[0] = 1;
	dp[1] = hf;
	dp[2] = qtr;
	ll tpw = qtr;
	for (int i = 3; i <= n; i++) dp[i] = ((dp[i - 2] * qtr) % mod + dp[i - 1] * hf) % mod;
	cout << dp[n];
	return 0;
}