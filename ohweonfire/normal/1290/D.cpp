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

void reset()
{
	puts("R");
	fflush(stdout);
}
int count;
int query(int c)
{
	static char s[5];
	count++;
	printf("? %d\n", c);
	fflush(stdout);
	scanf("%s",s);
	if(s[0] == 'Y') return 1;
	else return 0;
}

const int maxn = 1111;
int n, k;
bool alive[maxn];

int main()
{
	get2(n, k);
	
	int Block = std::max(1, k/2), BlockN = n / Block;
	for(int i=1; i<=n; i++) alive[i] = 1;
	for(int dltB=1; dltB<BlockN; dltB++)
	{
		for(int stB=1; stB <= dltB && stB + dltB <= BlockN; stB++)
		{
			reset();
			for(int b=stB; b <= BlockN; b+=dltB)
			{
				for(int i=0; i<Block; i++)
				{
					int cur = (b - 1) * Block + i + 1;
					if(query(cur)) alive[cur] = 0;
				}
			}
		}
	}
	int ans = 0;
	for(int i=1; i<=n; i++) ans += alive[i];
	printf("! %d\n", ans);
	return 0;
}