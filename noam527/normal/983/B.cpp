#include <bits/stdc++.h>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
#define yesno(X) cout << ((X) ? "YES" : "NO") << endl
#define noyes(X) cout << ((X) ? "NO" : "YES") << endl
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

const int mxn = 5005;

int n, a[mxn];
int f[mxn][mxn], ans[mxn][mxn];

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) f[i][i] = a[i];
	for (int d = 1; d < n; d++)
		for (int i = 0; i + d < n; i++)
			f[i][i + d] = f[i][i + d - 1] ^ f[i + 1][i + d];

	for (int i = 0; i < n; i++) ans[i][i] = f[i][i];
	for (int d = 1; d < n; d++)
		for (int i = 0; i + d < n; i++)
			ans[i][i + d] = max({ ans[i][i + d - 1], ans[i + 1][i + d], f[i][i + d] });

	int q, l, r;
	cin >> q;
	while (q--) {
		cin >> l >> r;
		cout << ans[--l][--r] << endl;
	}
}