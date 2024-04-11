#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define fi first
#define se second
#define mp make_pair

using namespace std;
const int N = 2e5 + 5;
int n, A[N], in[N];
pair <int, int> f[N][2], ans;
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	rep(i, 1, n) scanf("%d", &A[i]);
	f[1][0].fi = N, f[1][1].fi = -1;
	rep(i, 2, n) {
		f[i][0].fi = -1, f[i][1].fi = N;
		if(A[i - 1] < A[i]) f[i][0] = {f[i - 1][0].fi, 0};
		if(A[i - 1] > A[i]) f[i][1] = {f[i - 1][1].fi, 1};
		if(f[i - 1][1].fi < A[i]) f[i][0] = max(f[i][0], mp(A[i - 1], 1));
		if(f[i - 1][0].fi > A[i]) f[i][1] = min(f[i][1], mp(A[i - 1], 0));
	}
	if(~f[n][0].fi || f[n][1].fi < N) {
		puts("YES");
		in[n] = ~f[n][0].fi ? 0 : 1;
		per(i, n, 2) in[i - 1] = f[i][in[i]].se;
		rep(i, 1, n) printf("%d ", in[i]);
	} else puts("NO");
	return 0;
}