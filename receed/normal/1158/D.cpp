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

	pt operator-(pt p) {
		return {x - p.x, y - p.y};
	}
	ll operator*(pt p) {
		return x * p.y - y * p.x;
	}
	ll operator<(pt p) {
		return tie(x, y) < tie(p.x, p.y);
	}
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<pair<pt, int>> a(n);
	rep(i, n) {
		cin >> a[i].first.x >> a[i].first.y;
		a[i].second = i + 1;
		if (a[i].first < a[0].first)
			swap(a[0], a[i]);
	}
	string s;
	cin >> s;
	rep(i, n - 2) {
		for (int j = i + 1; j < n; j++) {
			if ((a[j].first - a[i].first) * (a[i + 1].first - a[i].first) > 0 == (s[i] == 'L'))
				swap(a[i + 1], a[j]);
		}
	}
	rep(i, n)
		cout << a[i].second << ' ';
}