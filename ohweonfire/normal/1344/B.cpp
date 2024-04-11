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

int n, m;
char s[maxn][maxn];
bool use[maxn][maxn];

void dfs(int x, int y)
{
	if(use[x][y]) return;
	if(s[x][y] != '#') return;
	use[x][y] = 1;
	dfs(x-1, y);
	dfs(x, y-1);
	dfs(x+1, y);
	dfs(x, y+1);
}

int main()
{
	get2(n, m);
	for(int i=1; i<=n; i++) scanf("%s", s[i] + 1);
	
	int e1 = 0, e2 = 0;
	for(int i=1; i<=n; i++)
	{
		int bad = 0, cnt = 0;
		for(int j=1; j<=m; j++) cnt += (s[i][j] == '#');
		if(cnt == 0) e1++;
		for(int j=2; j<=m; j++)
		{
			if(s[i][j-1] == '#' && s[i][j] == '.') bad = 1;
			else if(s[i][j-1] == '.' && s[i][j] == '#' && bad)
			{
				puts("-1");
				return 0;
			}
		}
	}
	for(int j=1; j<=m; j++)
	{
		int bad = 0, cnt = 0;
		for(int i=1; i<=n; i++) cnt += (s[i][j] == '#');
		if(cnt == 0) e2++;
		for(int i=1; i<=n; i++)
		{
			if(s[i-1][j] == '#' && s[i][j] == '.') bad = 1;
			else if(s[i-1][j] == '.' && s[i][j] == '#' && bad)
			{
				puts("-1");
				return 0;
			}
		}
	}
	
	if((e1 == 0) ^ (e2 == 0))
	{
		puts("-1");
		return 0;
	}
	
	int cnt = 0;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) if(!use[i][j] && s[i][j] == '#')
	{
		cnt++;
		dfs(i, j);
	}
	printendl(cnt);
	return 0;
}