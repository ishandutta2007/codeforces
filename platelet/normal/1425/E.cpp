#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int n, k, a[N], d[N];
int main() {
	cin >> n >> k;
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) scanf("%d", &d[i]);
	ll ans = 0;
	if(k == 0) {
		ll su = 0;
		per(i, n, 1) su += a[i], ans = max(ans, su - d[i]);
	} else if(k == 1) {
		ll su = 0; int mi = 1e9;
		rep(i, 1, n - 1) su += a[i], mi = min(mi, d[i]);
		ans = max(ans, su - mi);
		su = 0, mi = 1e9;
		per(i, n, 2) su += a[i], ans = max(ans, su - d[i]), mi = min(mi, a[i]);
		ans = max(ans, su + a[1] - mi - d[1]);
		sort(d + 1, d + n + 1);
		ans = max(ans, su + a[1] - d[1] - d[2]);
	} else {
		ll su = 0; int mi = 1e9;
		rep(i, 1, n - 1) su += a[i], mi = min(mi, d[i]);
		ans = max(ans, max(0LL + a[n] - d[n], su + a[n] - mi));
	}
	cout << ans;
	return 0;
}