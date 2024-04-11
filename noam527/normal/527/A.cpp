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

ll a, b, ans = 0;

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	ans += x / y;
	return gcd(y, x % y);
}

int main() {
	fast;
	cin >> a >> b;
	gcd(a, b);
	cout << ans << endl;
}