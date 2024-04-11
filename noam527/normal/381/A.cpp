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

int n, a[1001], ans[2] = { 0, 0 }, p1, p2, t = 0;

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	p1 = 0, p2 = n - 1;
	while (p1 <= p2) {
		if (a[p1] > a[p2]) ans[t] += a[p1++];
		else ans[t] += a[p2--];
		t ^= 1;
	}
	cout << ans[0] << " " << ans[1] << endl;
}