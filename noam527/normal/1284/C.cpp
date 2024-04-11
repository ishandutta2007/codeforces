#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

ll n, m;
ll fac[300003];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	fac[0] = 1;
	for (int i = 1; i < 300003; i++)
		fac[i] = fac[i - 1] * i % m;
	ll ans = 0;
	for (int k = 1; k <= n; k++) {
		ans = (ans + ((ll)(n - k + 1) * fac[k] % m * fac[n - k] % m * (n - k + 1) % m)) % m;
	}
	finish(ans);
}