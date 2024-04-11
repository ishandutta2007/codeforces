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

int ans = 0;

void go(int l, int r, vector<int> &a) {
	int f = 0;
	for (int i = l; i < r - 1; i++)
		if (a[i] > a[i + 1])
			f = 1;
	if (!f) {
		ans = max(ans, r - l);
		return;
	}
	go(l, (l + r) / 2, a);
	go((l + r) / 2, r, a);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n)
		cin >> a[i];
	go(0, n, a);
	cout << ans;
}