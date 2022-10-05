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
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

ll calc(ll ind, ll lo, ll hi) {
//	cout << "ind " << ind << " lo " << lo << " hi " << hi << endl;
	if (ind & 1) return ind / 2 + 1;
	ll nlo = hi + 1;
	lo += (lo & 1);
	hi -= (hi & 1);
	ll nhi = nlo + (hi - lo) / 2;
	ind = nlo + (ind - lo) / 2;
	return calc(ind, nlo, nhi);
}

ll n, x;
int q;

int main() {
	fast;
	cin >> n >> q;
	while (q--) {
		cin >> x;
		cout << calc(x, 1, n) << endl;
	}
}