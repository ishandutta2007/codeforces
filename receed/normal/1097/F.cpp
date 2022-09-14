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
 
typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 7001, M = 100007;
bitset<N> a[M], pr[N], rp[N], pp, dc;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q, t, x, y, z;
	cin >> n >> q;
	pp[1] = 1;
	for (int i = 2; i < N; i++) {
		if (pp[i])
			continue;
		for (int j = i * 2; j < N; j += i) {
			if (j % (i * i) == 0)
				dc[j] = 1;
			pp[j] = 1;
		}
	}
	for (int i = 1; i < N; i++)
		for (int j = i; j < N; j += i) {
			pr[j][i] = 1;
			if (!dc[j / i])
				rp[i][j] = 1;
		}
	rep(i, q) {
		cin >> t >> x >> y;
		if (t == 1) {
			a[x] = pr[y];
		}
		else if (t == 2) {
			cin >> z;
			a[x] = a[y] ^ a[z];
		}
		else if (t == 3) {
			cin >> z;
			a[x] = a[y] & a[z];
		}
		else if (t == 4) {
			cout << (a[x] & rp[y]).count() % 2;
		}
	}
}