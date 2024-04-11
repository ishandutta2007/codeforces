#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

ll a, b, c;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> a >> b >> c;
	ll ans = 2 * c;
	if (abs(a - b) <= 1) ans += a + b;
	else ans += 2 * min(a, b) + 1;
	finish(ans);
}