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

int n, a[maxn], val[maxn];
LL k;

int getbound(int a, LL x) // a - 3i^2 + 3i - 1
{
	int l = 0, r = a + 1, mid;
	while(l < r - 1)
	{
		mid = (l + r) / 2;
		if(a - 3ll * mid * mid + 3ll * mid - 1 > x) l = mid;
		else r = mid;
	}
	return l;
}
LL check(LL x)
{
	LL ret = 0;
	for(int i=1; i<=n; i++)
	{
		val[i] = getbound(a[i], x);
		ret += val[i];
	}
	return ret;
}

int main()
{
	get2(n, k);
	for(int i=1; i<=n; i++) get1(a[i]);
	LL lb = -4000000000000000000ll, rb = 10000000000ll, mid;
	
	while(lb < rb - 1)
	{
		mid = (lb + rb) / 2;
		if(check(mid) < k) rb = mid;
		else lb = mid;
	}
	
	for(int i=1; i<=n; i++)
	{
		val[i] = getbound(a[i], rb);
		k -= val[i];
	}
	for(int i=1; i<=n; i++)
	{
		int nv = getbound(a[i], lb) - val[i];
		val[i] += std::min(nv + 0ll, k);
		k = std::max(0ll, k - nv);
		printf("%d ", val[i]);
	}
	return 0;
}