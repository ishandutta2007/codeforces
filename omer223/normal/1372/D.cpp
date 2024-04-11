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
typedef vector<ll> vll;
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
struct pretree {
	vll prefix;
	pretree(vll arr) {
		int sz = arr.size();
		prefix.resize(sz, 0);
		foru(i, 0, sz) {
			if (!i)prefix[i] = arr[i];
			else prefix[i] = prefix[i - 1] + arr[i];
		}
	}
	ll query(int i, int j) {
		j = min(j, (int)(prefix.size() - 1));
		if (i > j)return 0;
		if (!i)return prefix[j];
		return prefix[j] - prefix[i - 1];
	}
};
const int sz = 2e5 + 5;
ll a[sz], n;

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n;
	vll o, e;
	foru(i, 0, n) {
		cin >> a[i];
		if (i & 1)o.pb(a[i]);
		else e.pb(a[i]);
	}
	if (n == 1) {
		cout << a[0] << endl;
		return 0;
	}
	int es = e.size(), os = o.size();
	pretree etree(e), otree(o);
	ll bst = 0;
	foru(l, 0, n-1) {//deal with l=n-1
		ll tmpsum = a[l] + a[l + 1];
		int myind = (l + 1) / 2, mylind = l / 2;
		switch ((l + 1) & 1) {
		case 0:
			tmpsum += etree.query(myind + 1, es - 1);
			tmpsum += otree.query(0, mylind - 1);
			break;
		case 1:
			tmpsum += otree.query(myind + 1, os - 1);
			tmpsum += etree.query(0, mylind - 1);
			break;
		}
		bst = max(bst, tmpsum);
	}
	ll tmps = a[0] + a[n - 1];
	tmps += etree.query(1, es - 2);
	cout << max(bst,tmps) << endl;
	return 0;
}