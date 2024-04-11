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
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 100002;
int p[N], rc[N], ans[N];

int getp(int v) {
	if (v != p[v])
		p[v] = getp(p[v]);
	return p[v];
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, s = 0;
	cin >> n;
	vector<ll> x(n);
	for (int i = 0; i < n; i += 2) {
		cin >> x[i + 1];
		for (ll j = floor(sqrt(x[i + 1])); j > 0; j--) {
			if (x[i + 1] % j)
				continue;
			ll k = x[i + 1] / j;
			if ((j + k) % 2)
				continue;
			ll b = (j + k) / 2, a = (k - j) / 2;
			if (a > 0 && a * a > s) {
				x[i] = a * a - s;
				s = b * b;
				break;
			}
		}
		if (!x[i]) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes\n";
	for (ll i : x)
		cout << i << ' ';
}