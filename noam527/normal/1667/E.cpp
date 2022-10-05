#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

const int mxn = 200005;

void ext_gcd(ll a, ll &x, ll b, ll &y) {
	if (b == 0) {
		x = 1, y = 0;
		return;
	}
	ext_gcd(b, x, a % b, y);
	ll tmp = x - y * (a / b);
	x = y;
	y = tmp;
}
ll inv(int value) {
	ll x, y;
	ext_gcd(value, x, md, y);
	x = (x % md + md) % md;
	return x;
}

ll work(int x) {
	ll res = 1;
	for (int i = 2; i <= x; i++) {
		res = res * i % md;
	}
	return res;
}

int n;
ll P[mxn];

void solve() {
	cin >> n;
	int halfn = n / 2;
	P[0] = 1;
	P[1] = inv(2);
	for (int i = 2; i <= n / 2; i++) {
		P[i] = P[i - 1];
		P[i] = (P[i] * (halfn - i + 1)) % md;
		P[i] = (P[i] * inv(n - i)) % md;
	}

	ll cursum = 0;
	vector<ll> ans;
	ans.push_back(P[halfn]);
	for (int i = halfn - 1; i >= 0; i--) {
		cursum = cursum - inv(i + 1) * P[i + 1];
		cursum %= md;
		cursum += md;
		cursum %= md;
		ans.push_back((P[i] + cursum) % md);
	}
	ll tmp = work(n - 1);
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] * tmp % md << " ";
	}
	for (int i = 0; i < halfn; i++) cout << "0 ";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}