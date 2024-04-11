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
int n, a[maxn], cnt[maxn];
int mex() { int ret = 0; while(cnt[ret]) ret++; return ret; }
std::vector<int> ans;
void op(int x)
{
	int tmp = mex();
	cnt[a[x]]--;
	a[x] = tmp;
	cnt[a[x]]++;
	ans.pb(x);
}

void solve()
{
	memset(cnt, 0, sizeof(cnt));
	get1(n);
	for(int i=1; i<=n; i++)
	{
		get1(a[i]);
		cnt[a[i]]++;
	}
	
	ans.clear();
	for(int i=1; i<=n; i++) if(cnt[a[i]] > 1) op(i);
	// for(int i=1; i<=n; i++) printf("%d ", a[i]);
	
	static int b[maxn], use[maxn];
	a[0] = mex();
	for(int i=0; i<=n; i++) b[i] = a[i], use[i] = 0;
	
	for(int i=0; i<=n; i++) if(!use[i])
	{
		int tmp = i;
		std::vector<int> qq;
		while(!use[tmp])
		{
			qq.pb(tmp);
			use[tmp] = 1;
			tmp = b[tmp];
		}
		if(qq.size() == 1) continue;
		if(i == 0)
		{
			for(auto v : qq) if(v)
				op(v);
		}
		else
		{
			for(auto v : qq) op(v);
			op(i);
		}
			
	}
	printf("%d\n", ans.size());
	for(int i=0; i<ans.size(); i++) printf("%d ", ans[i]);
	puts("");
}

int main()
{
	int tc;
	get1(tc);
	while(tc--) solve();
	return 0;
}