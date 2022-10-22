#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define upd(a, b) (a = min(a, b))

using namespace std;
const int N = 2005;
typedef long long ll;
int n, K;
int l[N], r[N], a[N];
ll f[N];
int main() {
	mem(f, 63), f[0] = 0;
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> K;
	rep(i, 1, n) scanf("%d%d%d", &l[i], &r[i], &a[i]);
	rep(i, 0, n - 1) {
		int nw = K;
		rep(j, i + 1, n) {
			int t = (a[j] - nw + K - 1) / K;
			if(t > r[j] - l[j]) break;
			nw += t * K - a[j];
			f[i] += a[j];
			if(j == n) upd(f[j], f[i]);
			else if(t < l[j + 1] - l[j]) upd(f[j], f[i] + nw);
		}
	}
	if(f[n] < 0x3f3f3f3f3f3f3f3f) cout << f[n];
	else puts("-1");
	return 0;
}