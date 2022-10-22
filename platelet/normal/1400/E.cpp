#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define upd(a, b) (a = min(a, b))

using namespace std;
const int N = 5005;
int n, A[N], f[N][N]; 

int main() {
	mem(f, 63);
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &A[i]);
	f[0][0] = 0;
	rep(i, 1, n) rep(j, 0, i - 1) {
		if(A[j] <= A[i]) upd(f[i][j], f[i - 1][j] + 1);
		upd(f[i][i], f[i - 1][j] + max(A[i] - A[j], 0));
	}
	int ans = 1e9;
	rep(i, 0, n) upd(ans, f[n][i]);
	cout << ans;
	return 0;
}