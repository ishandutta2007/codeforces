#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 5005;
typedef long long ll;
const ll P = 1e9 + 7;
int n, f[N][N * 2]; ll a[N], b[N], cnt[N];
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	cnt[1] = 1;
	rep(i, 1, n - 1) {
		scanf("%lld", &a[i]);
		cnt[i + 1] = cnt[i] * a[i] % P, b[i] = a[i] * a[i] % P;
	}
	per(i, n, 1) {
		f[i][0] = 2;
		rep(j, 1, n - i) f[i][j] = f[i][j - 1] * a[i + j - 1] % P;
		f[i][0] = 1;
		rep(j, 2, (n - i) * 2) {
			f[i][j] += b[i] * f[i + 1][j - 2] % P;
			if(f[i][j] >= P) f[i][j] -= P;
		}
	}
	rep(k, 1, n * 2 - 2) {
		ll ans = 0;
		rep(i, 1, n) (ans += (f[i][k] + (k > 1 && i > 1 ? P - f[i][k - 2] : 0)) * cnt[i]) %= P;
		printf("%lld ", ans * 500000004 % P);
	}
	return 0;
}