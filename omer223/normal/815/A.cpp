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
typedef long double ld;
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
bool v1 = false, v2 = false;
const int sz = 1e2+1;
int g[sz][sz], mnr[sz],mnc[sz], q[sz][sz];
vector<pair<char, int>> foo(int n, int m, int num) {
	vector<pair<char, int>> res;
	foru(i, 1, n + 1) {
		foru(j, 1, m + 1) {
			if (j == 1)mnr[i] = g[i][j]; else mnr[i] = min(mnr[i], g[i][j]);
		}
	}
	foru(i, 1, n + 1) {
		foru(k, 0, mnr[i]) res.pb(mp('r', i));
		foru(j, 1, m + 1)g[i][j] -= mnr[i];
	}
	foru(j, 1, m + 1) {
		foru(i, 1, n + 1) {
			if (i == 1)mnc[j] = g[i][j];
			else mnc[j] = min(mnc[j], g[i][j]);
		}
	}
	foru(j, 1, m + 1) {
		foru(k, 0, mnc[j])res.pb(mp('c', j));
		foru(i, 1, n + 1)g[i][j] -= mnc[j];
	}
	bool bad = false;
	foru(i, 1, n + 1) {
		foru(j, 1, m + 1) {
			if (g[i][j]) { bad = true; break; }
		}
	}
	if (bad) {
		return vector<pair<char, int>> {};
	}
	if (num == 1)v1 = true;
	else v2 = true;
	return res;
}
void transpose(int n, int m) {
	int tmp;
	foru(i, 1, n+1) {
		foru(j, 1, m+1) {
			q[j][i] = g[i][j];
		}
	}
}
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, m;
	bool swapped = 0;
	cin >> n >> m;
	foru(i, 1, n + 1) {
		foru(j, 1, m + 1) {
			cin >> g[i][j]; if (j == 1)mnr[i] = g[i][j]; else mnr[i] = min(mnr[i], g[i][j]);
		}
	}
	transpose(n, m);
	vector<pair<char, int>> res1 = foo(n,m,1), res2;
	foru(j, 1, m + 1) {
		foru(i, 1, n + 1)g[j][i] = q[j][i];
	}
	res2 = foo(m, n,2);
	if (v1 && (v2 && res1.size()<=res2.size() || !v2)) {
		cout << res1.size() << endl;
		for (auto x : res1) {
			if (x.first == 'r')cout << "row " << x.second << endl;
			else cout << "col " << x.second << endl;
		}
	}
	else if (v2 && (v1 && res2.size() <= res1.size() || !v1)) {
		cout << res2.size() << endl;
		for (auto x : res2) {
			if (x.first == 'c')cout << "row " << x.second << endl;
			else cout << "col " << x.second << endl;
		}
	}
	else cout << -1 << endl;
	return 0;
}