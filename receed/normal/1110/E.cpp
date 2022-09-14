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

using namespace std;
using ll = long long;
using ld = long double;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<vector<ll>> a(2, vector<ll>(n)), b(2, vector<ll>(n - 1));
	rep(i, 2) {
		rep(j, n) {
			cin >> a[i][j];
			if (j > 0)
				b[i][j - 1] = a[i][j] - a[i][j - 1];
		}
		sort(all(b[i]));
	}
	if (b[0] == b[1] && a[0][0] == a[1][0] & a[0][n - 1] == a[1][n - 1])
		cout << "Yes";
	else
		cout << "No";
}