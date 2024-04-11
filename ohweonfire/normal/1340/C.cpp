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

const int maxn = 10111;
int n, m, r, g, d[maxn];

int dp[maxn][1111];
bool vis[maxn][1111];
std::deque<pii> q;

void update(int x, int y, int d1, int d2)
{
	if(dp[x][y] > d1 + d2)
	{
		dp[x][y] = d1 + d2;
		if(d2 == 0) q.push_front(mp(x, y));
		else q.push_back(mp(x, y));
	}
}

int main()
{
	get2(n, m);
	for(int i=1; i<=m; i++) get1(d[i]);
	std::sort(d+1, d+m+1);
	get2(g, r);
	
	memset(dp, inf, sizeof(dp));
	dp[1][0] = 0; q.push_back(mp(1, 0));
	
	while(!q.empty())
	{
		int x = q.front().ff, y = q.front().ss; q.pop_front();
		if(vis[x][y]) continue;
		vis[x][y] = 1;
		
		if(x > 1 && d[x] - d[x-1] + y <= g) update(x-1, (y + d[x] - d[x-1]) % g, dp[x][y], (y + d[x] - d[x-1]) / g);
		if(x < m && d[x+1] - d[x] + y <= g) update(x+1, (y + d[x+1] - d[x]) % g, dp[x][y], (y + d[x+1] - d[x]) / g);
	}
	LL ans = Linf;
	for(int i=0; i<=g; i++) if(dp[m][i] != inf) ans = std::min(ans, i + 1ll * dp[m][i] * (r + g));
	for(int i=1; i<=m; i++) if(n - g == d[i] && dp[i][0] != inf) ans = std::min(ans, g + 1ll * dp[i][0] * (r + g));
	if(ans == Linf) ans = -1;
	printendl(ans);
	return 0;
}