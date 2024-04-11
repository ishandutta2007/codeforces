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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	rep(i, n)
		cin >> a[i];
	sort(all(a));
	int l = 0, r = n / 2 + 1, m;
	while (r - l > 1) {
		m = (l + r) / 2;
		rep(i, m)
			if (a[n - m + i] - a[i] < x) {
				r = m;
				break;
			}
		if (r != m)
			l = m;
	}
	cout << l;
}