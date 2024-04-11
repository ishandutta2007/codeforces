#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define putsl puts("")
using namespace std;
const int N = 1e3 + 7;
const db eps = 1e-12;
template<typename T> inline void read(T &x) {
	x = 0; T f = 1; char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch - '0');
	x *= f;
}
template<typename T> inline void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) print(x / 10);
	putchar(x % 10 + '0');
}
int n, m;
db f[N][N], ans, now[N], sum[N], p[N];
bool vis[N];
int main() {
	read(n);
	L(i, 1, n) L(j, 1, n) {
		int x; 
		read(x), f[i][j] = 0.01 * x;
	}
	L(i, 1, n - 1) now[i] = 1;
	int T = n;
	while(T--) {
		int mn = 0;
		if(T == n - 1) mn = n;
		else L(i, 1, n) if(!vis[i]) p[i] = (sum[i] + 1) / (1 - now[i] + eps);
		L(i, 1, n) if(!vis[i] && (!mn || p[i] < p[mn])) mn = i;
		vis[mn] = 1;
		L(i, 1, n) if(!vis[i]) sum[i] += now[i] * p[mn] * f[i][mn], now[i] *= 1. - f[i][mn];
	}
	printf("%.10lf\n", p[1]);
	return 0;
}