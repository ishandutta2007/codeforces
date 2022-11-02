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
#include <unordered_map>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <bitset>
#include <numeric>
#include <cmath>
#include <math.h>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
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

//ll dp[10001];

bool overflow;

ll calc(ll num) {
	if (num & 1) {
		if (num > (long double)(sqrtl(10) * 1e9)) overflow = true;
		return (num * (num - 1)) / 2;
	}
	ll res = num / 2;
	ll tmp = calc(num / 2);
	if (LLONG_MAX - tmp < res) overflow = true;
	return res + tmp;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	ll n;
	cin >> n;
	/*foru(i, 1, n) {
		if (i & 1) dp[i] = (i * (i - 1)) / 2;
		else dp[i] = (i / 2) + dp[i / 2];
	}
	int t, a, b;
	while (true) {
		cin >> t;
		if (t == -1) break;
		else if (t != 0) cout << dp[t] << endl;
		else {
			cin >> a >> b;
			foru(i, a, b + 1)cout << i << " " << dp[i] << endl;
		}
	}*/
	vector<ll> ans;
	int mx = 0;
	foru(i, 0, 64) {
		if ((1LL << i) & n) mx = i + 1;
	}
	foru(i, 1, mx + 2) {
		ll now = (1LL << i), prev = (1LL << (i - 1));
		ll l = 1, r = (1e18 + prev) / now, mid, num, tmp;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			num = mid * now - prev;
			overflow = false;
			tmp = calc(num);
			if (tmp < 0 || overflow || tmp > n) r = mid - 1;
			else if (tmp == n) {
				ans.pb(num);
				break;
			}
			else l = mid + 1;
		}
	}
	if (ans.empty()) cout << -1 << endl;
	else {
		for (auto x : ans) cout << x << endl;
	}
	return 0;
}