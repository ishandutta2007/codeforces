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
const ldb eps = 1e-7, pi = acos(-1);
using namespace std;

ll simpleans(ll n, ll cost = 1) {
	if (n == 1) return 0;
	return simpleans(n / 2, cost * 2) + (n / 2) * cost;
}

ll n, nn;
ll ans = 0;
vector<ll> b;

int main() {
	fast;
	cin >> n;
	nn = n;
	while (n) {
		ans += simpleans(n & -n);
		n -= (n & -n);
		b.push_back(n);
	}
	n = nn;
	for (int i = 0; i < b.size() - 1; i++)
		ans += (b[i] ^ b[i + 1]);
	cout << ans << endl;
}