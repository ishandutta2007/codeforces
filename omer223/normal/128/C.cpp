#define MOD 1000000007
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

void mult(ll &a, ll b) {
	a = ((a % MOD) * (b % MOD)) % MOD;
}
void add(ll &a, ll b) {
	a = ((a % MOD) + (b % MOD)) % MOD;
}
void subtract(ll &a, ll b) {
	if (a >= b)a = (a - b) % MOD;
	else a = (a - b) % MOD + MOD;
}
const int sz = 1e3 + 1;
ll tdp[sz][sz];

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	ll n, m, k;
	cin >> n >> m >> k;
	if (n < m)swap(n, m);
	if (2 * k + 1 > m) {
		cout << 0 << endl;
		return 0;
	}
	ll tmpn = 2 * k + 1, rem = n - tmpn;
	for (int myk = 0; myk <= k; myk++) {
		ll ksm = 0, kspesm = 0;
		for (int mym = 2 * myk + 1; mym <= n; mym++) {
			if (!myk)tdp[myk][mym] = 1;
			else {
				add(kspesm, ksm + tdp[myk - 1][mym - 2]);
				tdp[myk][mym] = kspesm;
				add(ksm, tdp[myk - 1][mym - 2]);
			}
		}
	}
	cout << (tdp[k][m] * tdp[k][n]) % MOD << endl;
	return 0;
}