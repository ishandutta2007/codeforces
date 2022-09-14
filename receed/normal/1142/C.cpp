#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

struct pt {
	ll x, y;
	pt() : x(0), y(0) {}
	pt(ll x, ll y) : x(x), y(y) {}

	bool operator<(const pt &p) const {
		if (x == p.x)
			return y < p.y;
		return x < p.x;
	}

	pt operator-(pt p) {
		return {x - p.x, y - p.y};
	}
	ll operator*(pt p) {
		return x * p.y - y * p.x;
	}
};

bool td(pt p1, pt p2, pt p3) {
	return (p2 - p1) * (p3 - p1) >= 0;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<pt> a(n), st;
	rep(i, n) {
		cin >> a[i].x >> a[i].y;
		a[i].y -= a[i].x * a[i].x;
	}
	sort(all(a));
	for (pt p : a) {
		while (!st.empty() && st.back().x == p.x)
			st.pop_back();
		while (st.size() > 1 && td(st[st.size() - 2], st.back(), p))
			st.pop_back();
		st.push_back(p);
	}
	cout << st.size() - 1;
}