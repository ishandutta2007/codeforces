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

int n, q, p1, p2, p3;

int main() {
	fast;
	cin >> n;
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i], b[i] = a[i];
	for (int i = 1; i < n; i++) a[i] += a[i - 1];
	sort(b.begin(), b.end());
	for (int i = 1; i < n; i++) b[i] += b[i - 1];

	cin >> q;
	while (q--) {
		cin >> p1 >> p2 >> p3;
		--p2, --p3;
		if (p1 == 1) {
			if (p2 == 0) cout << a[p3] << endl;
			else cout << a[p3] - a[p2 - 1] << endl;
		}
		else {
			if (p2 == 0) cout << b[p3] << endl;
			else cout << b[p3] - b[p2 - 1] << endl;
		}
	}
}