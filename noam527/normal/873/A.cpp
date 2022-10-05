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
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, k, x, ans = 0;
vector<int> a;

int main() {
	fast;
	cin >> n >> k >> x;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = n - 1; i > n - 1 - k; i--) ans += x;
	for (int i = n - 1 - k; i >= 0; i--) ans += a[i];
	cout << ans << endl;
}