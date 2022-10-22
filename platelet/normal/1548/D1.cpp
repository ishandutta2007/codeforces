#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 6005;

int n, a[2][2];
ll as;

int main() {
	// for(cin >> T; T--;) solve();
	cin >> n;
	int x, y;
	rep(i, 1, n) scanf("%d%d", &x, &y), a[x / 2 % 2][y / 2 % 2]++;
	rep(i, 0, 1) rep(j, 0, 1)
		as += a[i][j] * (a[i][j] - 1ll) * (a[i][j] - 2ll) / 6 + a[i][j] * (a[i][j] - 1ll) / 2 * (n - a[i][j]);
	cout << as;
}