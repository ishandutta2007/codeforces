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
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int powmod(ll b, ll e) {
	int rtn = 1;
	while (e) {
		if (e & 1) rtn = rtn * b % md;
		b = b * b % md, e /= 2;
	}
	return rtn;
}

ll n, m, k;

int main() {
	fast;
	cin >> n >> m >> k;
	if (k == -1 && n % 2 != m % 2) finish(0);
	cout << powmod(powmod(2, n - 1), m - 1) << endl;
}