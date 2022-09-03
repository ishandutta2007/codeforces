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

const int maxn = 200111;

int n, a[maxn], mn[maxn], smn[maxn], cnt[maxn];
void add(int x)
{
	for(int i=2; i*i<=x; i++) if(x % i == 0)
	{
		int c = 0;
		while(x % i == 0)
		{
			c++;
			x /= i;
		}
		cnt[i]++;
		if(mn[i] > c)
		{
			smn[i] = mn[i];
			mn[i] = c;
		}
		else if(smn[i] > c) smn[i] = c;
	}
	if(x == 1) return;
	int c = 1;
	if(mn[x] > c)
	{
		smn[x] = mn[x];
		mn[x] = c;
	}
	else if(smn[x] > c) smn[x] = c;
	cnt[x]++;
}
int main()
{
	get1(n);
	memset(mn, inf, sizeof(mn));
	memset(smn, inf, sizeof(smn));
	for(int i=1; i<=n; i++)
	{
		get1(a[i]);
		add(a[i]);
	}
	
	LL ans = 1;
	for(int i=1; i<maxn; i++)
	{
		if(cnt[i] <= n - 2) continue;
		if(cnt[i] < n)
		{
			smn[i] = mn[i];
			mn[i] = 0;
		}
		while(smn[i]--) ans *= i;
	}
	printendl(ans);
	return 0;
}