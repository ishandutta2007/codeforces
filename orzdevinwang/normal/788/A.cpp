#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, m, f[N], a[N];
ll ans, mx = -1e18, mn = 1e18, q[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> f[i];
	L(i, 1, n - 1) {
		a[i] = abs(f[i] - f[i + 1]);
		if(i & 1) a[i] = - a[i];
	}
	L(i, 1, n - 1) q[i] = q[i - 1] + a[i];
	R(i, n - 1, 1) {
		mx = max(mx, q[i]), mn = min(mn, q[i]);
		if(i & 1) ans = max(ans, - (mn - q[i - 1]));
		else ans = max(ans, (mx - q[i - 1]));
	}
	cout << ans << "\n";
	return 0;
}