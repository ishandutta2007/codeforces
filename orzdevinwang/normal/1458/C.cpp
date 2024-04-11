#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1007;
const int M = 1e5 + 7;
int n, m, f[5], to[5], g[5], a[N][N], ans[N][N];
char s[M];
int fix(int x) {
	x %= n;
	if(x <= 0) return x + n; return x;
}
void Main() {
	scanf("%d%d", &n, &m);
	f[1] = f[2] = f[3] = 0, to[1] = 1, to[2] = 2, to[3] = 3;
	L(i, 1, n) L(j, 1, n) scanf("%d", &a[i][j]);
	scanf("%s", s + 1);
	L(i, 1, m) {
		if(s[i] == 'L') f[2] --;
		if(s[i] == 'R') f[2] ++;
		if(s[i] == 'D') f[1] ++;
		if(s[i] == 'U') f[1] --;
		if(s[i] == 'I') swap(f[2], f[3]), swap(to[2], to[3]);
		if(s[i] == 'C') swap(f[1], f[3]), swap(to[1], to[3]);
	}
	L(i, 1, n) L(j, 1, n) g[1] = i, g[2] = j, g[3] = a[i][j], ans[fix(g[to[1]] + f[1])][fix(g[to[2]] + f[2])] = fix(g[to[3]] + f[3]);
	L(i, 1, n) L(j, 1, n) printf("%d%s", ans[i][j], j == n ? "\n" : " ");
}
int main() {
	int T; scanf("%d", &T);
	while(T--) Main();
	return 0;
}