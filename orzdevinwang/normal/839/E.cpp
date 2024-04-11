#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 44;
const db pi = acos(-1);
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar();
	return x * f;
}
int n, k, f[N], d[N][N], cnt[N], ans;
bool dfs(int x, int now) {
	f[now] = x;
	if(now > ans) return ans = now, true;
	L(y, x + 1, n) {
		if(now + cnt[y] <= ans) continue;
		int i = 1; 
		for(; i <= now; i++) if(!d[y][f[i]]) break;
		if(i == now + 1 && dfs(y, now + 1)) return true; 
	}
	return false;
}
int main() {
	n = read(), k = read();
	L(i, 1, n) L(j, 1, n) d[i][j] = read();
	R(i, n, 1) dfs(i, 1), cnt[i] = ans;
	printf("%.10lf\n", 1. * (ans - 1) * k * k / 2 / ans);
	return 0;
}