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

using std::cin;

const std::string val[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int can[2333][10], n, k, pre[2333][2333];
bool dp[2333][2333];

void work(int i, int j)
{
	if(i > n) return;
	putchar('0' + pre[i][j]);
	work(i+1, j-can[i][pre[i][j]]);
}

int main()
{
	cin >> n >> k;
	for(int i=1; i<=n; i++)
	{
		std::string now;
		cin >> now;
		for(int j=0; j<10; j++)
		{
			can[i][j] = 0;
			for(int k=0; k<7; k++)
			{
				if(now[k] == '1' && val[j][k] == '0')
				{
					can[i][j] = -1;
					break;
				}
				if(now[k] == '1') can[i][j]--;
				if(val[j][k] == '1') can[i][j]++;
			}
		}
	}
	dp[n+1][0] = 1;
	for(int i=n; i>=1; i--) for(int j=0; j<=k; j++)
	{
		for(int nxt=9; nxt>=0; nxt--) if(can[i][nxt] != -1 && j >= can[i][nxt] && dp[i+1][j - can[i][nxt]])
		{
			dp[i][j] = 1;
			pre[i][j] = nxt;
			break;
		}
	}
	if(dp[1][k]) work(1, k);
	else puts("-1");
	return 0;
}