#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
int n, K;
double p[20], f[1 << 20];
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n >> K;
	For(i, 0, n) scanf("%lf", &p[i]);
	For(i, 0, n) {
		if(p[i] == 0) { puts("0"); continue; }
		f[0] = p[i];
		double ans = p[i];
		For(S, 1, 1 << n) if((~S >> i & 1) && __builtin_popcount(S) < K) {
			f[S] = 0;
			double su = 0;
			For(j, 0, n) if(S >> j & 1)
				su += p[j], f[S] += p[j] * f[S ^ 1 << j];
			ans += f[S] /= 1 - su;
		}
		printf("%lf\n", ans);
	}
	return 0;
}