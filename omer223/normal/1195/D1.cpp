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

ll n;
ll a[100005], dig[11], pref[11];
string arr[100005];
ll q(int i, int j) {
	if (i > j)return 0;
	if (!i)return pref[j];
	return pref[j] - pref[i - 1];
}
ll mult(ll a, ll b) {
	return ((a % MOD) * (b % MOD)) % MOD;
}
int customLog(ll x) {
	int res = 0;
	while (x) {
		res++;
		x /= 10;
	}
	return res;
}

ll calc(string num, bool first) {
	ll res = 0, m = (first ? 10 : 1);
	int sz = num.length();
	ford(i, sz - 1, 0) {
		res += mult(num[i] - '0', m);
		m = mult(m,100);
		res %= MOD;
	}
	return res;
}
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n;
	foru(i, 0, n) {
		cin >> a[i];
	}
	string tmp;
	sort(a, a + n);
	foru(i, 0, n) {
		tmp = to_string(a[i]);
		arr[i] = tmp;
		dig[tmp.length()]++;
	}
	foru(i, 0, 11) {
		if (!i)pref[i] = 0;
		else pref[i] = pref[i - 1] + dig[i];
	}
	ll res = 0;
	foru(i, 0, n) {
		int digits = arr[i].length();
		res += mult(q(digits, 10), calc(arr[i], true));
		res %= MOD;
		res += mult(q(digits, 10), calc(arr[i], false));
		res %= MOD;
		foru(j, 1, digits) {
			res += mult(dig[j], mult(modpow(10, 2 * j), stoi(arr[i].substr(0, digits - j))) + calc(arr[i].substr(digits - j, j), true));
			res %= MOD;
			res += mult(dig[j], mult(modpow(10, 2 * j), stoi(arr[i].substr(0, digits - j))) + calc(arr[i].substr(digits - j, j), false));
			res %= MOD;
		}
	}
	cout << res << endl;
	return 0;
}
/*
YES 5
1 3 5 2 4
6
YES 6
1 3 5 2 4 6
7
YES 7
1 3 5 2 6 4 7
8
YES 8
1 3 5 2 6 8 4 7
9
YES 9
1 3 5 2 4 7 9 6 8
10
YES 10
1 3 5 2 4 6 8 10 7 9
11
YES 11
1 3 5 2 4 6 8 10 7 9 11*/