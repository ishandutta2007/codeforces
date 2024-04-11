#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define rint register int
inline int rf(){int r;int s=0,c;for(;!isdigit(c=getchar());s=c);for(r=c^48;isdigit(c=getchar());(r*=10)+=c^48);return s^45?r:-r;}
int Wu[4096], f[64][64][104], g[4096][104], w[16], m, n, q, E, K, B = 6, L = 63, H = 4032; char _[16];
int main()
{
	m = rf();
	n = rf();
	q = rf();
	generate(w,w+m,rf);
	E = 1<<m;
	for(rint S = 0, j; S < E; S++)
	{
		for(j = 0; j < m; j++)
			S&1<<j?:Wu[S]+=w[j];
		Wu[S] = min(Wu[S],101);
	}
	for(rint i = 1, j, S; i <= n; i++)
	{
		scanf("%s",_+1);
		for(S = 0, j = m; j; j--)
			S = S<<1|(_[j]^'0');
		for(j = 0; j < 64; j++)
			++f[(S&H)>>B][j][Wu[((j^(S&L))|H)&~-E]];
	}
	for(rint S = 0, a, b, j; S < E; S++)
	{
		for(j = 0; j < 64; j++)
			for(a = 0, b = Wu[(((j<<B)^(S&H))|L)&~-E]; b <= 100; a++, b++)
				g[S][b] += f[j][S&L][a];
		partial_sum(g[S],g[S]+101,g[S]);
	}
	for(rint i = 1, j, S; i <= q; i++)
	{
		scanf("%s",_+1);
		for(S = 0, j = m; j; j--)
			S = S<<1|(_[j]^'0');
		printf("%d\n",g[S][rf()]);
	}
	return 0;
}