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
#include <cmath>
#include <math.h>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <queue>
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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
const int sz = 5e5;
int n, c, a[sz], pre[sz],vsz=0;
um<int, int, custom_hash> mem;
vector<vector<int>> ind;
int query(int i, int j) {
	if (i > j)return 0;
	else if (!i)return pre[j];
	return pre[j] - pre[i - 1];
}
int kad(vector<int> arr) {
	int szsz = arr.size();
	int here = 0, mx = 0;
	foru(i, 0, szsz) {
		here = max(here + arr[i], arr[i]);
		mx = max(mx, here);
	}
	return mx;
}
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n >> c;
	int mx = 0;
	foru(i, 0, n) {
		cin >> a[i];
		if (a[i] == c) {
			if (!i)pre[i] = 1;
			else pre[i] = pre[i - 1] + 1;
		}
		else {
			pre[i] = pre[i - 1];
			if (mem.find(a[i]) == mem.end()) {
				mem[a[i]] = vsz;
				ind.pb(vector<int>{i});
				vsz++;
			}
			else ind[mem[a[i]]].pb(i);
		}
	}
	mx = pre[n - 1];
	vector<int> vv;
	int vvsz;
	for (vector<int> v : ind) {
		vv.clear();
		vvsz = v.size();
		foru(i, 0, vvsz) {
			vv.pb(1);
			if (i < vvsz - 1)vv.pb(-query(v[i], v[i + 1]));
		}
		int val = kad(vv) + pre[n-1];
		mx = max(mx, val);
	}
	cout << mx << endl;
	return 0;
}