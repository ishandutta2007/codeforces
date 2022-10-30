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
typedef long double ld;
typedef vector<ll> vll;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b, ll md) { ll res = 1; a %= md; for (; b; b >>= 1) { if (b & 1)res = res * a%md; a = a * a%md; }return res; }
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
vector<int> primes;
const int sz = 1e7 + 5;
bitset<sz> sieve;
void prec() {
	for (int i = 2; i*i < sz; i++) {
		if (!sieve[i]) {
			sieve[i] = 1;
			primes.pb(i);
			for (int j = 2 * i; j * j < sz; j += i)sieve[j] = 1;
		}
	}
}
vi a, b;

void solve() {
	int n;
	cin >> n;
	vi myp;
	for (int k : primes) {
		if (k*k > n)break;
		if (n%k == 0) {
			myp.pb(k);
			while (n%k == 0)n /= k;
		}
	}
	if (n > 1)myp.pb(n);
	if (myp.size() <= 1) {
		a.pb(-1);
		b.pb(-1);
	}
	else {
		a.pb(myp[0]);
		int mysz = myp.size(), tmp=1;
		for (int i = 1; i < mysz; i++)tmp *= myp[i];
		b.pb(tmp);
	}
}


int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int t;
	cin >> t;
	prec();
	while (t--)solve();
	for (int k : a)cout << k << " ";
	cout << endl;
	for (int k : b) cout << k << " ";
	cout << endl;
	return 0;
}