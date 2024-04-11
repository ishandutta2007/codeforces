#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
const int N = 105;
int n, K, p[N], a[N], A[N], b[N], B[N], ok[N][N*2];
void mul(int b[]) {
	rep(i, 1, n) A[i] = a[b[i]];
	memcpy(a, A, sizeof a);
}
int dfs(int i, int j) {
	if(i > K) return 0;
	if(~ok[i][j]) return ok[i][j];
	if(!memcmp(a, p, sizeof a)) return ok[i][j] = i == K;
	ok[i][j] = 0;
	mul(b), ok[i][j] |= dfs(i + 1, j + 1), mul(B);
	mul(B), ok[i][j] |= dfs(i + 1, j - 1), mul(b); 
	return ok[i][j];
}
int main() {
	cin >> n >> K;
	rep(i, 1, n) scanf("%d", &b[i]), B[b[i]] = i;
	rep(i, 1, n) scanf("%d", &p[a[i] = i]);
	mem(ok, -1), puts(dfs(0, n) ? "YES" : "NO");
	return 0;
}