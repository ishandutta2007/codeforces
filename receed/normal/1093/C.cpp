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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n / 2)
		cin >> a[i];
	for (int i = 0; i * 2 < n; i++) {
		if (i > 0)
			b[i] = max(b[i - 1], a[i] - b[n - i]);
		b[n - 1 - i] = a[i] - b[i];
	}
	rep(i, n)
		cout << b[i] << ' ';
}