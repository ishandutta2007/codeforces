#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <numeric>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int sz = 4e5;
vector<pair<pair<int, bool>, int>> v;
int n, k;

const ll mod = 998244353;
ll f[sz], finv[sz];

ll modpow(ll a, ll b) {
	if (!b)return 1;
	ll ans = modpow(a, b >> 1);
	ans *= ans;
	ans %= mod;
	if (b & 1) {
		ans *= a; ans %= mod;
	}
	return ans;
}

void prec() {
	const int mx = 300005;
	f[0] = 1;
	foru(i, 1, mx + 1)f[i] = (f[i - 1] * i) % mod;
	finv[mx] = modpow(f[mx], mod - 2);
	ford(i, mx - 1, 0)finv[i] = (finv[i + 1] * (i + 1)) % mod;
}

ll choose(int n, int k) {
	if (k > n)return 0;
	ll mul = (f[n] * finv[k]) % mod;
	return (mul * finv[n - k]) % mod;
}

void input() {
	cin >> n >> k;
	foru(i, 0, n) {
		int l, r;
		cin >> l >> r;
		v.pb({ {l,false},i });
		v.pb({ {r,true},i });
	}
	sort(v.begin(), v.end());
	prec();
}

int main() {
	fast;
	input();
	ll tot = 0;
	unordered_set<int> opens;
	foru(i, 0, 2 * n) {
		if (v[i].first.second) {
			opens.erase(v[i].second);
		}
		else {
			opens.insert(v[i].second);
			tot += choose(opens.size() - 1, k - 1);
			tot %= mod;
		}
	}
	cout << tot << endl;
	return 0;
}