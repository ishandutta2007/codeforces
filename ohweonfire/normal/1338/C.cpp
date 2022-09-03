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

LL num[] = {2,3,8,12,32,48,128,192,512,768,2048,3072,8192,12288,32768,49152,131072,196608,524288,786432,2097152,3145728,8388608,12582912,33554432,50331648,134217728,201326592,536870912,805306368,2147483648,3221225472,8589934592,12884901888,34359738368,51539607552,137438953472,206158430208,549755813888,824633720832,2199023255552,3298534883328,8796093022208,13194139533312,35184372088832,52776558133248,140737488355328,211106232532992,562949953421312,844424930131968,2251799813685248,3377699720527872,9007199254740992,13510798882111488,36028797018963968,54043195528445952,144115188075855872,216172782113783808,576460752303423488,864691128455135232,2305843009213693952,3458764513820540928};
LL nimProd(LL y)
{
	LL ret = 0;
	for(int i=0; i<60; i++) if((y >> i) & 1) ret ^= num[i];
	return ret;
}
LL n;
void solve()
{
	get1(n);
	int nn = 0;
	while(1ll << (nn + nn) <= n) nn++;
	nn--;
	LL base = 1ll << (nn + nn);
	int tp = (n - 1) % 3;
	n = (n - base) / 3;
	LL q[3];
	q[0] = base + n;
	q[1] = base + base + nimProd(n);
	q[2] = q[0] ^ q[1];
	printf("%lld\n", q[tp]);
}

int main()
{
	int tc;
	get1(tc);
	while(tc--) solve();
	return 0;
}