#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, k, a, tot = 0, cnt = 0, saved = 0;

int main() {
	fast;
	cin >> n >> k;
	for (int i = 0; tot < k && i < n; i++, cnt++) {
		cin >> a;
		saved += a;
		tot += min(8, saved);
		saved = max(0, saved - 8);
	}
	if (tot < k)
		cout << -1 << endl;
	else
		cout << cnt << endl;
}