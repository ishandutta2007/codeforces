#include <bits/stdc++.h>

namespace IO
{
char gc()
{
#ifdef FREAD
	static char buf[1<<21], *P1 = buf, *P2 = buf;
	if(P1 == P2)
	{
		P1 = buf;
		P2 = buf + fread(buf, 1, 1<<21, stdin);
		if(P1 == P2) return EOF;
	}
	return *(P1++);
#else
	return getchar();
#endif
}
template<typename Tp> bool get1(Tp &x)
{
	bool neg = 0;
	char c = gc();
	while( c != EOF && (c < '0' || c > '9') && c != '-' ) c = gc();
	if(c == '-') c = gc(), neg = 1;
	if(c == EOF) return false;
	x = 0;
	for(; c>='0' && c<='9'; c = gc()) x = x*10 + c - '0';
	if(neg) x = -x;
	return true;
}
template<typename Tp> void printendl(Tp x)
{
	if(x<0)putchar('-'),x=-x;
	static short a[40], sz;
	sz = 0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
	puts("");
}
} // namespace IO
using IO::get1;
using IO::printendl;
#define get2(x,y) get1(x) && get1(y)
#define get3(x,y,z) get2(x,y) && get1(z)
#define get4(x,y,z,w) get3(x,y,z) && get1(w)
#define pb push_back
#define mp std::make_pair
#define ff first
#define ss second
typedef long long LL;
typedef unsigned long long uLL;
typedef std::pair<int,int> pii;
const int inf = 0x3f3f3f3f;
const LL Linf = 1ll<<61;

const int maxn = 111;
int n, q1, q2, a[maxn], b[maxn], c[maxn], ans[maxn];

int d[maxn];

void getv(int id)
{
	for(int i=1; i<=n; i++) a[id] += d[i] * (d[i]-1) * (d[i]-2) / 6;
	for(int i=1; i<=n-2; i++) b[id] += d[i] * d[i+1] * d[i+2];
}
int main()
{
	get1(n); get2(a[0], b[0]);
	for(int i=1; i<=n; i++)
	{
		c[i] = (i < n ? i : 1);
		printf("+ %d\n", c[i]);
		fflush(stdout);
		get2(a[i], b[i]);
	}
	for(int i=n; i>=1; i--)
	{
		a[i] -= a[i-1];
		b[i] -= b[i-1];
	}
	
	memset(ans, -1, sizeof(ans));
	ans[1] = (a[n] - a[1]);
//	printf("a= %d %d\n", a[n], a[1]);
	for(int i=2; i<n; i++) if(a[i])
	{
		ans[i] = 0;
		while(ans[i] * (ans[i] - 1) / 2 < a[i]) ans[i]++;
	}
	
	if(ans[3] == -1) ans[3] = (b[2] > 0);
	if(ans[2] == -1) ans[2] = b[n] / (ans[3]+1) - 1;
	for(int i=3; i<n-1; i++)
	{
		b[i] -= (ans[i-1]+1) * (ans[i-2]+1);
		if(ans[i+1] == -1) ans[i+1] = (b[i] > 0);
	}
	ans[n] = (b[n-1] - (ans[n-2]+1) * (ans[n-3]+1)) / (ans[n-2] + 1);
	
	printf("!");for(int i=1; i<=n; i++) printf(" %d", ans[i]); puts("");
	return 0;
}