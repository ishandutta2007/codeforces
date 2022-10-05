#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

ll n, k;

int main() {
	fast;
	cin >> n >> k;
	if (k > n + n - 1) finish(0);
	if (k == 1) finish(0);
	if (k > n + 1) k = 2 * n + 2 - k;
	if (k % 2 == 0) finish(k / 2 - 1);
	finish(k / 2);
}