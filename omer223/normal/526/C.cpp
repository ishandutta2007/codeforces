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

ll c, hb, hr, wb, wr;
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> c >> hr >> hb >> wr >> wb;
	if (wb > sqrtl(c) + 1) {
		ll bst = 0;
		for (ll amt = 0; amt * wb <= c; amt++) bst = max(bst, amt*hb + ((c - amt * wb) / wr)*hr);
		cout << bst << endl;
	}
	else if (wr > sqrtl(c) + 1) {
		ll bst = 0;
		for (ll amt = 0; amt * wr <= c; amt++) bst = max(bst, amt*hr + ((c - amt * wr) / wb)*hb);
		cout << bst << endl;
	}
	else {
		if (hb*wr > wb*hr) {
			swap(hb, hr);
			swap(wb, wr);
		}
		ll bst = 0;
		for (ll amt = 0; amt * amt <= c; amt++) {
			bst = max(bst, amt*hb + ((c - amt * wb) / wr)*hr);
		}
		cout << bst << endl;
	}
	return 0;
}