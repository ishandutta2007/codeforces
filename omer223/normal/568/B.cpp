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


const int sz = 4e3 + 5;
ll n, b[sz];
ll f[sz], finv[sz];
void prec() {
	f[0] = 1;
	foru(i, 1, 4001) f[i] = multex(f[i - 1], i);
	finv[4000] = inv(f[4000]);
	ford(i, 3999, 0)finv[i] = multex(finv[i + 1], i + 1);
}
ll choose(int a, int b) {
	if (a < b)return -1;
	return multex(f[a], multex(finv[b], finv[a - b]));
}
void precDp() {
	b[0] = 1;
	b[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int k = 0; k < i; k++)add(b[i], multex(choose(i - 1, k), b[k]));
	}
}
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n;
	prec();
	precDp();
	ll res = 0;
	for (int ex = 1; ex <= n; ex++) 
		add(res, multex(choose(n, ex), b[n-ex]));
	cout << res << endl;
	return 0;
}