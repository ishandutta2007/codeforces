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

int n, k;
ldb divi;
ll a[300000], s = 0;

int main() {
	fast;
	cout.precision(8);
	cin >> n >> k;
	for (int i = 0; i < (1 << n); i++) {
		cin >> a[i];
		s += a[i];
	}
	divi = ldb(1 << n);

	int i, v;
	cout << s / divi << endl;
	while (k--) {
		cin >> i >> v;
		s -= a[i];
		a[i] = v;
		s += a[i];
		cout << s / divi << endl;
	}
}