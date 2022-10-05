#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n;
vector<int> a;

ll calc(ll x, ll y) {
	if (x > y) swap(x, y);
	return x * (y - x) + (y - x) * (n + 1 - y);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	ll ans = 0;
	ans += calc(a[0], n + 1);
	ans += calc(a.back(), n + 1);
	for (int i = 0; i + 1 < n; i++)
		ans += calc(a[i], a[i + 1]);
	finish(ans / 2);
}