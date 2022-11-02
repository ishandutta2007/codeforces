#define MOD 1000000007
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define has(set, x) set.find(x) != set.end()
#define nohas(set, x) set.find(x) == set.end()
#define inc(mpp, x) {if(has(mpp, x)) mpp[x]++; else mpp.insert(mp(x,1));}
#define decc(mpp, x) {if(has(mpp, x)) {if(mpp[x] > 1) mpp[x]--; else mpp.erase(x);}}
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define um unordered_map
#define us unordered_set
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <math.h>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <stack>
#include <numeric>
#include <queue>
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }
ll inv(ll a) {
	return modpow(a, MOD - 2);
}
ll mult(ll &a, ll b) {
	a = ((a % MOD) * (b % MOD)) % MOD;
	return a;
}
ll multex(ll a, ll b) {
	return ((a % MOD) * (b % MOD)) % MOD;
}
ll add(ll &a, ll b) {
	a = ((a % MOD) + (b % MOD)) % MOD;
	return a;
}
ll subtract(ll &a, ll b) {
	if (a >= b)a = (a - b) % MOD;
	else a = (a - b) % MOD + MOD;
	return a;
}

const int sz = 1e5 + 5;
int a[sz], n, cnt[sz];

vector<int> divisors(int k) {
	vector<int> ans, a2;
	for (int i = 1; i * i <= k; i++) {
		if (k%i == 0) {
			ans.pb(i);
			if (i*i != k)a2.pb(k / i);
		}
	}
	for (auto p = a2.rbegin(); p != a2.rend(); p++) ans.pb(*p);
	return ans;
}
int main() {
	fast;
	cin >> n;
	foru(i, 0, n)cin >> a[i];
	sort(a, a + n);
	int i = 1e5, j = n-1;
	while (i >= 0 && j >= 0) {
		cnt[i] = cnt[i + 1];
		while (j < n&&a[j] == i) {
			cnt[i]++;
			j--;
		}
		i--;
	}
	while (i >= 0) {
		cnt[i] = cnt[i + 1]; i--;
	}
	ll ans = 0;
	for (int num = 2; num <= 1e5; num++) {
		vector<int> d = divisors(num);
		int mysz = d.size();
		ll tmp = 1, tmp2;
		ford(i, mysz - 2, 0) mult(tmp, modpow(i + 1, cnt[d[i]] - cnt[d[i + 1]]));
		tmp2 = tmp;
		mult(tmp, modpow(mysz, cnt[d[mysz - 1]]));
		mult(tmp2, modpow(mysz - 1, cnt[d[mysz - 1]]));
		ans += (tmp - tmp2 + MOD) % MOD;
		ans %= MOD;
	}
	cout << (ans + 1) % MOD << endl;
	return 0;
}