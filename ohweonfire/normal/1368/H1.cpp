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

const int maxn = 100111;
int n, m, q;
char left[maxn], right[maxn], up[maxn], down[maxn];

int solve()
{
	const char s[] = "BR";
	int dp[2] = {0, 0}, ndp[2];
	
	for(int i=0; i<n; i++)
	{
		dp[0] += (left[i] != s[0]);
		dp[1] += (left[i] != s[1]);
	}
	
	for(int i=0; i<m; i++)
	{
		int val[2] = {0, 0};
		if(up[i] == s[1]) val[0]++;
		else val[1]++;
		if(down[i] == s[1]) val[0]++;
		else val[1]++;
		
		ndp[0] = std::min(dp[0] + val[0], dp[1] + val[0] + n);
		ndp[1] = std::min(dp[1] + val[1], dp[0] + val[1] + n);
		
		std::swap(dp, ndp);
	}
	
	for(int i=0; i<n; i++)
	{
		dp[0] += (right[i] != s[0]);
		dp[1] += (right[i] != s[1]);
	}
	return std::min(dp[0], dp[1]);
}

int main()
{
	get3(n, m, q);
	scanf("%s%s%s%s", left, right, up, down);
	
	int ans = solve();
	std::swap(left, up);
	std::swap(right, down);
	std::swap(n, m);
	ans = std::min(ans, solve());
	printendl(ans);
	return 0;
}