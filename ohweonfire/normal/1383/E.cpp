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

const int mod = 1e9 + 7;
const int maxn = 1000111;
int qpow(int x, int y)
{
	int ret = 1;
	while(y)
	{
		if(y & 1) ret = 1ll * ret * x % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return ret;
}

int n, dp[maxn], pre[maxn];
char s[maxn];
int stk[maxn], top, sum[maxn], ways[maxn];
int main()
{
	scanf("%s", s+1);
	n = strlen(s + 1);
	int s_ones = 0, last = 0, num = 0;
	int good = 1;
	while(s[good] == '0' && good <= n) good++;
	if(good > n)
	{
		printendl(n);
		return 0;
	}
	for(int i=1; i<=n; i++)
	{
		if(s[i] == s[i-1]) pre[i] = pre[i-1];
		else pre[i] = i;
		
		if(s[i] == '0' && s[i+1] != '0')
		{
			int len = i - pre[i] + 1;
			while(top && stk[top] <= len) top--;
			
			stk[++top] = len;
			sum[top] = sum[top - 1];
			ways[top] = s_ones;
			if(top > 1) sum[top] = (sum[top - 1] + 1ll * (stk[top-1] - stk[top]) * ways[top-1]) % mod;
			
			dp[i] = (sum[top] + 1ll * stk[top] * ways[top] + good - 1) % mod;
		}
		else if(s[i] == '1') s_ones = (s_ones + dp[pre[i] - 1] + 1) % mod;
	}
	int ans = (s_ones + (s[n] == '0' ? 1ll * ways[top] * stk[top] : 0)) % mod;
	printendl(ans);
	return 0;
}