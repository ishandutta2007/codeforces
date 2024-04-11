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

ll n, ans = 1;

bool chk(ll x) {
	if (x < 0) x = -x;
	while (x) {
		if (x % 10 == 8) return true;
		x /= 10;
	}
	return false;
}

int main() {
	fast;
	cin >> n;
	n++;
	while (!chk(n)) n++, ans++;
	cout << ans << endl;
}