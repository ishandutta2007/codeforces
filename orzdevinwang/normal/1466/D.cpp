#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mkp make_pair 
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch= getchar();
	return x * f;
}
const int N = 1e6 + 7;
int n, m, a[N], f[N], deg[N], tot;
void Min(int &x, int y) {
	if(x > y) x = y;
}
ll sum;
void Main() {
	sum = 0;
	n = read();
	tot = 0;
	L(i, 1, n) deg[i] = 0;
	L(i, 1, n) scanf("%d", &a[i]), sum += a[i];
	L(i, 1, n - 1) {
		int u, v; scanf("%d%d", &u, &v);
		deg[u] ++, deg[v] ++; 
	}
	L(i, 1, n) {
		L(j, 1, deg[i] - 1) f[++tot] = a[i];
	}
	sort(f + 1, f + tot + 1, [&](int x, int y) { return x > y; });
	L(i, 1, n - 1) {
		printf("%lld ", sum);
		sum += f[i];
	}
	puts("");
}
int main() {
	int T = read(); 
	while(T--) Main(); 
	return 0;
}