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

int n;
vector<ll> a, aa, b, bb;
int s;

int main() {
	fast;
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	if (*min_element(a.begin(), a.end()) == *max_element(a.begin(), a.end())) {
		if (a[0] == 0) {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) cout << "1 ";
			return 0;
		}
		finish("NO");
	}
	cout << "YES" << endl;
	aa.resize(n);
	for (int i = 0; i < n; i++) {
		if (a[i] < a[(i + 1) % n]) {
			s = i;
			break;
		}
	}
	for (int i = 0; i < n; i++)
		aa[i] = a[(i + s) % n];
	b.resize(n);
	b[1] = aa[1];
	b[0] = aa[1] * 1000000LL + aa[0];
	for (int i = n - 1; i > 1; i--)
		b[i] = aa[i] + b[(i + 1) % n];

	bb.resize(n);
	for (int i = 0; i < n; i++)
		bb[(i + s) % n] = b[i];
	for (const auto &i : bb) cout << i << " "; cout << endl;
}