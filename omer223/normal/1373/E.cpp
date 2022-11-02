#define MOD 1000000000000000000
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
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) {
	if (!b)return 1;
	ll tmp = modpow(a, b / 2);
	tmp *= tmp;
	if (b & 1)tmp *= a;
	return tmp;
}
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
ll smallest(int n) {
	if (!n)return 0;
	int sz = n / 9, rem = n % 9;
	ll ans = -1;
	ans += modpow(10, sz);
	if (rem)ans += modpow(10, sz)*rem;
	return ans;
}
ll foo(ll n) {
	ll s = 0;
	while (n) {
		s += (n % 10);
		n /= 10;
	}
	return s;
}
ll smallestStarts(ll n, ll num) {
	if (n < foo(num))return 1e18 + 5;
	ll len = to_string(num).length();
	return smallest(n - foo(num)) * modpow(10, len) + num;
}
ll sum(ll begin, ll k) {
	ll res = 0;
	while (k--) {
		res += foo(begin);
		begin++;
	}
	return res;
}
void solve() {
	int n, k;
	bool flag = false;
	cin >> n >> k;
	k++;
	ll mn = 1e18;
	foru(nines, 0, 17) {
		foru(l, 0, 10) {
			foru(r, 0, 10) {

				ll starter = modpow(10, nines + 1)*l + modpow(10, nines + 1) - 10 + r;
				if (starter < 0)continue;
				ll s = sum(starter, k);
				if (s == n) {
					if(starter>=0)mn = min(mn, starter);
				}
				else if (s > n)continue;
				else {
					ll diff = n - s;
					if (diff%k != 0)continue;
					ll x = diff / k;
					string strcand = to_string(smallest(x)), st = to_string(starter);
					if (l == 0)st = '0' + st;
					ll cand = stoll(strcand + st);
					if(cand>=0)mn = min(mn, cand);
				}
			}
		}
	}
	if (mn >= 1e18) {
		cout << -1 << endl;
	}
	else {
		cout << mn << endl;
	}
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}