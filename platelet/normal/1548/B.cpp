#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int T, n; ll a[18][N];

void solve() {
	scanf("%d", &n), n--;
	rep(i, 0, n) scanf("%lld", &a[0][i]);
	per(i, n, 1) a[0][i] = llabs(a[0][i] -  a[0][i - 1]);
	rep(i, 1, 17) rep(j, 1, n - (1 << i) + 1)
		a[i][j] = __gcd(a[i - 1][j], a[i - 1][j + (1 << i - 1)]);
	int as = 1;
	rep(i, 1, n) {
		int j = i; ll g = 0;
		per(k, 17, 0) if(j + (1 << k) <= n + 1) {
			ll t = __gcd(g, a[k][j]);
			if(t > 1) g = t, j += 1 << k;
		}
		as = max(as, j - i + 1);
	}
	printf("%d\n", as);
}

int main() {
	for(cin >> T; T--;) solve();
}