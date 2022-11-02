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
bool of = 0;
ll modpow(ll a, ll b) {
	if (!b)return 1;
	ll tmp = modpow(a, b / 2);
	if (tmp > 1e18 / tmp)of = 1;
	tmp *= tmp;
	if (b & 1) {
		if (tmp > 1e18 / a)of = 1;
		tmp *= a;
	}
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
pii foo(vector<ll> arr) {
	int n = arr.size(), cr = 0,mxhere,mx=0,mnhere,mn=0;
	bool foundpos = 0, foundneg = 0;
	foru(i, 0, n) {
		cr += arr[i];
		if (arr[i] > 0)foundpos = 1;
		if (arr[i] < 0)foundneg = 1;
		mn = min(mn, cr);
		mx = max(mx, cr);
	}
	int f = mx - mn + 1;
	if (f == 1)return mp(1, 1);
	if (!foundpos || !foundneg) {
		if (foundpos&&foundneg)return mp(1, 1);
		else if (foundpos) {
			if (mx == 1)return mp(f, f);
			else return mp(f, f - 1);
		}
		else {
			if (mn == -1)return mp(f, f);
			else return mp(f,f-1);
		}
	}
	if (!mx) {

	}
	int lmx=0, rmx=0, lmn=0, rmn=0;
	bool imx = 0, imn = 0;
	cr = 0;
	foru(i, 0, n) {
		cr += arr[i];
		if (cr == mx) {
			if (!imx) {
				lmx = i; imx = 1;
			}
			rmx = i;
		}
		if (cr == mn) {
			if (!imn) {
				lmn = i; imn = 1;
			}
			rmn = i;
		}
	}
	if (!(lmx - rmn > 1 || lmn - rmx > 1))return mp(f, f);
	else return mp(f, f - 1);
}
void solve() {
	string s;
	cin >> s;
	int n = s.length();
	vector<ll> ud(n+1, 0), lr(n+1, 0);
	foru(i, 1, n + 1) {
		switch (s[i-1]) {
		case 'W':
			ud[i] = 1;
			break;
		case 'S':
			ud[i] = -1;
			break;
		case 'A':
			lr[i] = -1;
			break;
		case 'D':
			lr[i] = 1;
			break;
		}
	}
	pll a = foo(ud), b = foo(lr);
	ll o1 = a.first * b.second, o2 = a.second * b.first;
	cout << min(o1, o2) << endl;
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