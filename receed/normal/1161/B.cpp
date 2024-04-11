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
	int n, m, x, y;
	cin >> n >> m;
	vector<vector<int>> a(n);
	rep(i, m) {
		cin >> x >> y;
		x--; y--;
		if ((y - x + n) % n > (x - y + n) % n)
			swap(x, y);
		int d = (y - x + n) % n;
		a[x].push_back(d);
		if ((y - x + n) % n == (x - y + n) % n)
			a[y].push_back(d);
	}
	rep(i, n)
		sort(all(a[i]));
	for (int i = 1; i < n; i++) {
		if (n % i)
			continue;
		int f = 1;
		rep(j, n)
			if (a[j] != a[(i + j) % n]) {
				f = 0;
				break;
			}
		if (f) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}