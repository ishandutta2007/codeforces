#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

ll c2(ll x) {
	return x * (x - 1) / 2;
}

int n, k, p;
vector<int> a;

int main() {
	fast;
	cin >> n >> k;
	p = (1 << k);
	a.resize(n);
	for (auto &i : a) cin >> i;
	
	n++;
	a.insert(a.begin(), 0);
	for (int i = 1; i < n; i++)
		a[i] ^= a[i - 1];
	map<int, ll> M;
	for (int i = 0; i < n; i++) {
		M[max(a[i], p - 1 - a[i])]++;
	}
	ll ans = 0, cc;
	for (auto &i : M) {
		cc = i.second;
		ans += c2(cc / 2);
		ans += c2((cc + 1) / 2);
	}
	cout << c2(n) - ans << endl;
}