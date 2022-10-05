#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
using namespace std;

ll n, k, st = 0, sz;
vector<ll> a;

bool ps(vector<ll> &b, int st) {
	for (int i = st + 1; i < b.size(); i++) {
		b[i] += b[i - 1];
		if (b[i] >= k) return true;
	}
	return false;
}

int main() {
	fast;
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (auto i : a)
		if (i >= k) {
			cout << 0 << endl;
			return 0;
		}
	while (!a[st]) st++;
	sz = n - st;
	if (sz < 4) {
		cout.precision(20);
		if (sz == 2) {
			cout << (k - a[st + 1] + a[st] - 1) / a[st] << endl;
			return 0;
		}
		ll d = a[st], e = a[st + 1], f = a[st + 2];
		ldb ans = (ldb(-d - 2 * e) / (2 * d));
		//cout << (pow(d + 2 * e, 2) / ldb(4 * d * d)) / 1e14 - (2 * f - 2 * k) / ldb(d) / 1e14 << endl;
		ans += ldb(sqrt((pow(d + 2 * e, 2) / ldb(4 * d * d)) / 1e10 - (2 * f - 2 * k) / ldb(d) / 1e10)) * 1e5;
		//if (abs(ans - round(ans)) <= 1e-10) ans = round(ans);
		cout << ceil(ans) << endl;
		return 0;
	}
	int op = 0;
	while (!ps(a, st)) op++;
	cout << op + 1 << endl;
}