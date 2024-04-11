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

ll n, h;

bool down(ll he) {
	if (he + 1 > (2e18 / he)) return false;
	ll s = (he * (he + 1)) / 2;
	return s <= n;
}

bool updown(ll he) {
	ll s1 = (he * (he + 1)) / 2;
	if (s1 > 1e18)return false;
	ll s2 = ((h + he - 1) * (he - h)) / 2;
	return s1 <= n - s2;
}

ll myceil(ll a, ll b) {
	return a / b + (a%b != 0);
}

int main() {
	fast;
	cin >> n >> h;
	ll l = 1, r = h,mid,bst=-1;
	while (l <= r) {
		mid = (l + r + 1) / 2;
		if (down(mid)) {
			bst = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	if (bst == h) {
		ll l = h, r = 2e9, mid, bst = -1;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			if (updown(mid)) {
				bst = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (bst == -1) {
			bst = h;
			ll rem = n - ((bst*(bst + 1)) / 2);
			cout << bst + myceil(rem, bst) << endl;
		}
		else {
			ll rem = n - ((bst*(bst + 1)) / 2 + ((bst - h)*(bst + h - 1)) / 2);
			cout << 2 * bst - h + myceil(rem, bst) << endl;
		}
	}
	else {
		ll rem = n - ((bst*(bst + 1)) / 2);
		cout << bst + myceil(rem, bst) << endl;
	}
	return 0;
}