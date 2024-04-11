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

const int maxn = 1111;

int n, m, dist[maxn][maxn];
char s[maxn][maxn];
std::queue<pii> q;

void update(int x, int y, int d)
{
	if(x == 0 || y == 0 || x > n || y > m) return;
	if(dist[x][y] > d)
	{
		dist[x][y] = d;
		q.emplace(x, y);
	}
}

int t;
int main()
{
	get3(n, m, t);
	for(int i=1; i<=n; i++) scanf("%s", s[i]+1);
	
	memset(dist, inf, sizeof(dist));
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++)
	{
		if(s[i-1][j] == s[i][j] || s[i+1][j] == s[i][j] || s[i][j-1] == s[i][j] || s[i][j+1] == s[i][j])
		{
			q.emplace(i, j);
			dist[i][j] = 0;
		}
	}
	while(!q.empty())
	{
		int x = q.front().ff, y = q.front().ss;
		q.pop();
		update(x+1, y, dist[x][y]+1);
		update(x, y+1, dist[x][y]+1);
		update(x-1, y, dist[x][y]+1);
		update(x, y-1, dist[x][y]+1);
	}
	int x, y; LL p;
	while(t--)
	{
		get3(x, y, p);
		if(dist[x][y] != inf && p >= dist[x][y])
		{
			printf("%d\n", (s[x][y] - '0') ^ ((p - dist[x][y]) & 1));
		}
		else printf("%d\n", s[x][y] - '0');
	}
	return 0;
}