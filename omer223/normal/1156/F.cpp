#define MOD 998244353
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
typedef tuple<int, int, int, int> qu;
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
const int sz = 5e3 + 3;
ll dp[sz][sz], n, a[sz], invtable[5005];
vector<pll> v;
void input() {
	cin >> n;
	foru(i, 0, n)cin >> a[i];
	sort(a, a + n);
	int cnt = 0;
	foru(i, 0, n) {
		if (!i || a[i] == a[i - 1])cnt++;
		else {
			v.pb(mp(a[i - 1], cnt));
			cnt = 1;
		}
	}
	v.pb(mp(a[n - 1], cnt));
	invtable[0] = 0;
	foru(i, 1, 5001)invtable[i] = inv(i);
}
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	input();
	int m = v.size();
	ford(before, m, 1) { //includes
		ll coolsum = 0, tot = 0;
		ford(lasttake, m, before) {
			ll instawin = v[lasttake - 1].second - 1, rem = n - before, fine = tot, bad = rem - fine - instawin;
			dp[before][lasttake] = instawin;
			add(dp[before][lasttake], coolsum);
			mult(dp[before][lasttake], invtable[rem]);
			add(tot, v[lasttake - 1].second);
			add(coolsum, dp[before + 1][lasttake] * v[lasttake - 1].second);
		}
	}
	ll ans = 0;
	foru(i, 0, m) add(ans, multex(dp[1][i + 1], v[i].second));
	mult(ans, invtable[n]);
	cout << ans << endl;
	return 0;
}