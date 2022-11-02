#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <string>
#include <queue>
#include <time.h>
#include <chrono>
#include <random>
#include <iomanip>
#include <map>
#include <numeric>
#include <complex>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef pair<ld, ld> pld;
typedef pair<ll, pair<pii, int>> einf;

pll p[3];

ll dist(pll a, pll b) {
	return abs(a.ff - b.ff) + abs(a.ss - b.ss);
}

ll calc(vector<int> v) {
	ll tot = 0;
	foru(i, 0, 2)tot += dist(p[v[i]], p[v[i + 1]]);
	return tot;
}

void draw(vector<pair<pll, pll>>& pts, pll a, pll b) {
	if (a == b)return;
	if (a.ff == b.ff || a.ss == b.ss)pts.push_back({ a,b });
	else{
		pts.push_back({ a,{ a.ff,b.ss } });
		pts.push_back({ {a.ff,b.ss},b });
	}
}

int main() {
	fast;
	foru(i, 0, 3)cin >> p[i].ff >> p[i].ss;
	sort(p, p + 3);
	bool is = 1;
	foru(i, 0, 2) {
		if (p[i].ff != p[i + 1].ff)is = 0;
	}
	if (is) {
		cout << 1 << '\n';
		cout << p[0].ff << ' ' << p[0].ss << ' ' << p[2].ff << ' ' << p[2].ss << '\n';
		return 0;
	}
	is = 1;
	foru(i, 0, 2) {
		if (p[i].ff != p[i + 1].ff)is = 0;
	}
	if (is) {
		cout << 1 << '\n';
		cout << p[0].ff << ' ' << p[0].ss << ' ' << p[2].ff << ' ' << p[2].ss << '\n';
		return 0;
	}
	vector<ll> xs{ p[0].ff,p[1].ff,p[2].ff }, ys{ p[0].ss,p[1].ss,p[2].ss };
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	ll xm = xs[1], ym = ys[1];
	vector<pair<pll, pll>> seg;
	foru(i, 0, 3)draw(seg, { xm,ym }, p[i]);
	cout << seg.size() << '\n';
	for (auto ii : seg)cout << ii.ff.ff << ' ' << ii.ff.ss << ' ' << ii.ss.ff << ' ' << ii.ss.ss << '\n';
	return 0;
}