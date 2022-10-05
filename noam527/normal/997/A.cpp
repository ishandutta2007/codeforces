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

ll n, x, y;
string s;

int main() {
	fast;
	cin >> n >> x >> y;
	cin >> s;

	ll c = 0;
	for (int i = 1; i < n; i++) {
		if (s[i - 1] == '0' && s[i] == '1') c++;
	}
	if (s.back() == '0') c++;
	if (c == 0) finish(0);
	cout << min(c * y, (c - 1) * x + y) << endl;
}