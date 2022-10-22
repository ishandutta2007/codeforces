#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
const int N = 1005;
int n, vis[N];
double p[N][N], A[N], B[N];
double dis(int u) {
	return B[u] < 1 ? A[u] / (1 - B[u]) : 1e9;
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	rep(i, 1, n) rep(j, 1, n) scanf("%lf", &p[i][j]), p[i][j] /= 100;
	rep(i, 0, n) A[i] = 1, B[i] = 1;
	A[n] = B[n] = 0;
	rep(i, 1, n) {
		int u = 0;
		rep(j, 1, n) if(!vis[j] && dis(j) < dis(u)) u = j;
		vis[u] = 1;
		rep(j, 1, n) if(!vis[j]) A[j] += p[j][u] * dis(u) * B[j], B[j] *= 1 - p[j][u];
	}
	printf("%.15lf\n", dis(1));
	return 0;
}