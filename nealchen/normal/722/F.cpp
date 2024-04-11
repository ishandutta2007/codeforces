#include <cstdio>
#include <string.h>
int F() {
	register int a, b, c;
	while(c = getchar(), c < '-');
	b = c == '-';
	for(a = b ? 0 : c - '0'; c = getchar(), c > '-'; a = a * 10 + c - '0');
	return b ? -a : a;
}
const int N = 1e5 + 1, M = 2e5, K = 20;
struct CRT {long long r, m;} nul = (CRT){0, 0};
int n, m, k[N];
int head[N], row[M], col[M], next[M], cnt;
CRT sol[K][N];
long long exgcd(register long long a, register long long b, register long long &x, register long long &y) {
	if(!b) {x = 1, y = 0; return a;}
	register long long ret = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return ret;
}
CRT cat(const CRT &a, const CRT &b) {
	if(!a.m || !b.m) return nul;
	register long long x, y, g = exgcd(a.m, b.m, x, y);
	if(((b.r - a.r) % g)) return nul;
	x *= (b.r - a.r) / g;
	x %= (b.m / g);
	if(x < 0) x += (b.m / g);
	return (CRT){a.r + x * a.m, a.m / g * b.m};
}
int main() {
	register int i, j;
	n = F(), m = F();
	memset(head + 1, -1, m * sizeof(int));
	for(i = 1; i <= n; ++i) {
		k[i] = F();
		for(j = 0; j < k[i]; ++j) {
			register int x = F();
			row[cnt] = i;
			col[cnt] = j;
			next[cnt] = head[x];
			head[x] = cnt++;
		}
	}
	for(i = 1; i <= m; ++i) {
		register int top = -1, bot = -1, ans = 0;
		for(j = head[i]; ~j; j = next[j]) {
			register int t, at;
			if(top != row[j] + 1) bot = row[j];
			top = row[j];
			sol[0][top] = (CRT){col[j], row[j][k]};
			for(t = 1; top + (1 << t) - 1 <= bot; ++t) {
				sol[t][top] = cat(sol[t-1][top], sol[t-1][top+(1<<(t-1))]);
			}
			at = top;
			register CRT now = (CRT){0, 1};
			while(t--) {
				if(at + (1 << t) - 1 <= bot) {
					register CRT tmp = cat(now, sol[t][at]);
					if(tmp.m) at += (1 << t), now = tmp;
				}
			}
			if(at - top > ans) ans = at - top;
		}
		printf("%d\n", ans);
	}
	return 0;
}