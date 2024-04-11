#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <fstream>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, a[200002], d[200002], cnt = 0;
bool inc;
set<int> sqr;

bool isqr(int x) {
	return sqr.find(x) != sqr.end();
}

int main() {
	fast;
	cin >> n;
//	n = 200000;
	for (int i = 0; i < n; i++) cin >> a[i];
//	for (int i = 0; i < n; i++) a[i] = 1e9;
	for (int i = 0; i * i <= 2e9; i++) sqr.insert(i * i);

	for (int i = 0; i < n; i++)
		if (isqr(a[i])) cnt++;
	if (cnt == n / 2) finish(0);
	if (cnt > n / 2) inc = false;
	else inc = true;

	cnt = abs(cnt - n / 2);

	if (inc) {
		for (int i = 0, mn; i < n; i++) {
			auto it = sqr.upper_bound(a[i]), it2 = it;
			it2--;
			mn = 1e9;
			mn = min(mn, *it - a[i]);
			mn = min(mn, a[i] - *it2);
			d[i] = mn;
		}
	}
	else {
		for (int i = 0; i < n; i++)
			if (!isqr(a[i])) d[i] = 0;
			else if (a[i] == 0) d[i] = 2;
			else d[i] = 1;
	}

	sort(d, d + n);
	
	ll p = 0, ans = 0;
	while (d[p] == 0) p++;
	for (int i = 0; i < cnt; i++, p++) ans += d[p];
	cout << ans << endl;
}