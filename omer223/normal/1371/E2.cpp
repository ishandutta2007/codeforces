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

const int sz = 2e5 + 5;
ll a[sz], n, p;

bool amt(int x) {
	ll iter = 0, curr = 0, day=0, perm=0;
	ll res = 1;
	while (iter < n || day < n) {
		while (iter < n&&a[iter] <= x + day) {
			iter++;
			curr++;
		}
		res *= (curr - day);
		res %= p;
		day++;
	}
	return (res%p);
}

ll mnval() {
	ll mn = a[0];
	foru(i, 1, n) {
		if (mn + i < a[i]) mn = a[i] - i;
	}
	return mn;
}

int main() {

	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n >> p;
	foru(i, 0, n)cin >> a[i];
	sort(a, a + n);
	ll s = mnval();
	ll l = mnval(), r = 1e9, mid, mn = l, mx = -1;
	if (!amt(l)) {
		cout << 0 << endl << endl;
		return 0;
	}
	while (l <= r) {
		mid = (l + r + 1) / 2;
		if (amt(mid)) {
			mx = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << mx - mn + 1 << endl;
	foru(i, mn, mx + 1) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}