#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, x, p = 0, a[2][50], ans = 0, at = 1;

int main() {
	fast;
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> a[0][i] >> a[1][i];
	while (p < n) {
		if (at + x <= a[0][p]) at += x;
		else ans += a[1][p] - at + 1, at = a[1][p] + 1, p++;
	}
	cout << ans << endl;
}