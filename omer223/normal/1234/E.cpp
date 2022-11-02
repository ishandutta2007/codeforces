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

const int sz = 2e5 + 5;
ll pref[sz], n, m;
void addTo(int i, int j, ll val) {
	if (i > j)return;
	pref[i] += val;
	pref[j + 1] -= val;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n >> m;
	ll curr, prev;
	cin >> prev;
	m--;
	while (m--) {
		cin >> curr;
		if (prev != curr) {
			ll mn = min(prev, curr), mx = max(prev, curr);
			addTo(1, mn - 1, mx - mn);
			addTo(mx + 1, n, mx - mn);
			addTo(mn + 1, mx - 1, mx - mn - 1);
			addTo(mn, mn, mx - 1);
			addTo(mx, mx, mn);
		}
		prev = curr;
	}
	ll cum = 0;
	foru(i, 0, n) {
		cum += pref[i + 1];
		cout << cum << " ";
	}
	cout << endl;
	return 0;
}