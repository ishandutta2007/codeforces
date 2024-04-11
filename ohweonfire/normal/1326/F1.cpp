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

#define getcode(i,j) (((i)>>(j))&1)
void FMT(LL *a, int n) { for(int i=0; i<n; i++) for(int j=0; j<(1<<n); j++) if(getcode(j, i)) a[j] += a[j^(1<<i)]; }
void iFMT(LL *a, int n) { for(int i=0; i<n; i++) for(int j=0; j<(1<<n); j++) if(getcode(j, i)) a[j] -= a[j^(1<<i)]; }

const int N = 18;

int con[N][N], n;
LL dp[1<<N][N], ways[N+1][1<<N], tmp[N+1][1<<N], ans[1<<N], fac[N+1], hsx[1<<N];

int a[N+1];
void dfs(int cur, int sum, int last, uLL hsy)
{
	if(sum == 0)
	{
		LL sum = 0;
		for(int i=0; i<(1<<n); i++)
		{
			if((n - __builtin_popcount(i)) & 1) sum -= tmp[cur][i];
			else sum += tmp[cur][i];
		}
		for(int i=0; i<(1<<n-1); i++) if(hsx[i] == hsy) ans[i] = sum;
		return;
	}
	for(int i=1; i<=last && i<=sum; i++)
	{
		a[cur] = i;
		for(int j=0; j<(1<<n); j++) tmp[cur+1][j] = tmp[cur][j] * ways[i][j];
		dfs(cur+1, sum-i, i, hsy * 99 + i);
	}
}

int main()
{
	get1(n);
	for(int i=0; i<n; i++)
	{
		char s[100];
		scanf("%s", s); for(int j=0; j<n; j++) con[i][j] = s[j] - '0';
	}
	for(int i=0; i<n; i++) dp[1<<i][i] = 1;
	for(int i=0; i<(1<<n); i++) for(int j=0; j<n; j++) if(getcode(i, j))
	{
		for(int k=0; k<n; k++) if(con[j][k] && !getcode(i, k))
			dp[i|(1<<k)][k] += dp[i][j];
	}
	for(int i=0; i<(1<<n); i++) for(int j=0; j<n; j++) if(getcode(i, j)) ways[__builtin_popcount(i)][i] += dp[i][j];
	for(int i=0; i<=n; i++) FMT(ways[i], n);
	
	fac[0] = 1; for(int i=1; i<=n; i++) fac[i] = fac[i-1] * i;
	for(int i=0; i<(1<<n); i++) tmp[0][i] = 1;
	for(int i=0; i<(1<<n-1); i++)
	{
		std::vector<int> vs;
		int last = -1;
		for(int j=0; j<n; j++) if(j == n-1 || !getcode(i, j))
		{
			vs.pb(j - last);
			last = j;
		}
		std::sort(vs.begin(), vs.end(), std::greater<int>());
		for(int j=0; j<vs.size(); j++) hsx[i] = hsx[i] * 99 + vs[j];
	}
	dfs(0, n, n, 0);
	for(int i=0; i<n; i++) for(int j=0; j<(1<<n); j++) if(getcode(j, i)) ans[j^(1<<i)] -= ans[j];
	for(int i=0; i<(1<<n-1); i++) printf("%lld ", ans[i]);
	return 0;
}