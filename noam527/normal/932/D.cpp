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

const int mxn = 4e5 + 1;

int q, p[20][mxn], lst[mxn], va[mxn], dep[mxn], nxt = 2;
ll s[mxn];

void add(int par, int val) {
	int tmp = par;
	while (tmp >= 0 && tmp != p[0][tmp] && va[tmp] < val) tmp = p[0][tmp];
	if (va[tmp] < val) p[0][nxt] = nxt, dep[nxt] = 1;
	else p[0][nxt] = tmp, dep[nxt] = dep[tmp] + 1;
	s[nxt] = s[tmp] + val;
	va[nxt] = val;

	for (int i = 1; i < 20; i++)
		p[i][nxt] = p[i - 1][p[i - 1][nxt]];

	nxt++;

//	cout << "parent of " << nxt - 1 << " is " << p[0][nxt - 1] << endl;
//	cout << "depth of " << nxt - 1 << " is " << dep[nxt - 1] << endl;
	/*
	p[0][nxt] = par;
	s[nxt] = s[par] + val;
	va[nxt] = val;
	dep[nxt] = dep[par] + 1;

	for (int i = 1; i < 20; i++)
		p[i][nxt] = p[i - 1][p[i - 1][nxt]];

	if (val <= va[par]) lst[nxt] = lst[par];
	else lst[nxt] = nxt;

	nxt++;
	*/
}

int climb(int v, int am) {
	for (int i = 0; i < 20; i++)
		if (am & (1 << i)) v = p[i][v];
	return v;
}

int query(int v, ll x) {
	static int lo, hi, mid, ver;
	lo = 0, hi = 1e6;
	while (lo < hi) {
		mid = lo + (hi - lo) / 2;
		ver = climb(v, mid);
		if (ver < lst[v] || s[v] - s[ver] + va[ver] > x) hi = mid;
		else lo = mid + 1;
	}
	for (int i = lo + 2; i >= 0 && i >= lo - 2; i--) {
		ver = climb(v, i);
		if (ver >= lst[v] && s[v] - s[ver] + va[ver] <= x) return i;
	}
	return -1;
}

int main() { 
	fast;
	s[0] = 0, lst[0] = 0, dep[0] = 0, va[0] = 0;
	s[1] = 0, lst[1] = 1, dep[1] = 1, va[1] = 0;
	for (int i = 0; i < 20; i++) p[i][1] = 1, p[i][0] = 0;

	int last = 0;

	cin >> q;
	ll para[3];
	while (q--) {
		cin >> para[0] >> para[1] >> para[2];
		para[1] ^= last;
		para[2] ^= last;
//		cout << para[1] << " " << para[2] << endl;
		if (para[0] == 1)
			add(para[1], para[2]);
		else {
			int tmp = query(para[1], para[2]);
			last = min(dep[para[1]], 1 + tmp);
			cout << last << endl;
		}
	}
}