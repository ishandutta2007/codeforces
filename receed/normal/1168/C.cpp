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

const int N = 300002, L = 19;
int a[N], d[L][N], md[L][N];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	rep(i, n)
		cin >> a[i];
	rep(i, L) {
		d[i][n] = n;
		md[i][n] = n;
	}
	for (int i = n - 1; i >= 0; i--) {
		rep(j, L)
			md[j][i] = n;
		rep(j, L) {
			if (a[i] & (1 << j)) {
				rep(k, L)
					md[k][i] = min(md[k][i], md[k][d[j][i + 1]]);
				d[j][i] = i;
				md[j][i] = i;
			}
			else
				d[j][i] = d[j][i + 1];
		}
	}
	int x, y, v;
	rep(z, q) {
		cin >> x >> y;
		x--; y--;
		int f = 0;
		rep(i, L)
			if ((a[y] & (1 << i)) && md[i][x] <= y) {
				f = 1;
				break;
			}
		if (f)
			cout << "Shi\n";
		else
			cout << "Fou\n";
	}
}