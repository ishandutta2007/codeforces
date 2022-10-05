#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int f(int n) {
	int rtn = 1;
	while (n) {
		if (n % 10) rtn *= (n % 10);
		n /= 10;
	}
	return rtn;
}

int g[1000001];

int calc(int n) {
	if (g[n] != -1) return g[n];
	return g[n] = calc(f(n));
}

int q, l, r, k;
vector<int> a[10];

int bs(int at, int x) {
	static int lo, hi, mid;
	lo = 0, hi = a[at].size() - 1;
	while (lo < hi) {
		mid = lo + (hi - lo) / 2;
		if (a[at][mid] < x) lo = mid + 1;
		else hi = mid;
	}
	for (int i = max(0, lo - 2); i < min(lo + 3, (int)a[at].size()); i++)
		if (a[at][i] >= x) return i;
	return a[at].size();
}

int main() { 
	fast;
	for (int i = 1; i < 1000001; i++) g[i] = -1;
	for (int i = 1; i < 10; i++) g[i] = i;
	for (int i = 10; i < 1000001; i++) calc(i);
	for (int i = 1; i < 1000001; i++) a[g[i]].push_back(i);

	cin >> q;
	while (q--) {
		cin >> l >> r >> k;
		int v1 = bs(k, l), v2 = bs(k, r);
		if (v2 == a[k].size() || a[k][v2] > r) v2--;
		cout << v2 - v1 + 1 << endl;
	}
}