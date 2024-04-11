#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0) 
#define foru(i, k, n) for (int i = k; i < n; i++) 
#define ford(i, k, n) for (int i = k; i >= n; i--) 
#define pb push_back
#define ff first 
#define ss second 

#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <string> 
#include <list> 
#include <queue> 
#include <set> 
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;

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

ll divi(const ll& lhs, const ll& rhs) {
	return mult(lhs, inv(rhs));
}

const int sz = 5e5;
int n, m, a, b[sz];

int main() {
	fast;
	cin >> n >> m >> a;
	foru(i, 0, m)cin >> b[i + 1];
	ll tot = 1;
	foru(i, 0, m) {
		ll tmp = bpw(a, b[i + 1] - b[i]);
		imult(tot, divi(mult(tmp, tmp + 1), 2));
	}
	imult(tot, bpw(a,2*( n / 2 - b[m]) + (n & 1)));
	cout << tot << '\n';
	return 0;
}