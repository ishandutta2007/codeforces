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

const int maxn = 400111;

LL n, k, p[maxn], q[maxn];
int m;

void solve()
{
	get3(n, m, k);
	for(int i=1; i<=m; i++) get1(p[i]);
	p[0] = 0; p[++m] = n;
	for(int i=1; i<=m; i++) q[i] = p[i] - p[i-1]; k += m;
	
	LL L, U, lb, ub, mid;
	
	lb = 1; ub = n+1;
	while(lb < ub - 1)
	{
		mid = (lb + ub) >> 1;
		LL sum = 0;
		for(int i=1; i<=m; i++) sum += q[i] / mid;
		if(k <= sum) lb = mid;
		else ub = mid;
	}
	L = lb;
	
	lb = 0; ub = n;
	while(lb < ub - 1)
	{
		mid = (lb + ub) >> 1;
		LL sum = 0;
		for(int i=1; i<=m; i++) sum += (q[i] + mid - 1) / mid;
		if(k >= sum) ub = mid;
		else lb = mid;
	}
	U = ub;
	// printf("L= %lld U= %lld\n", L, U);
	std::vector<std::pair<LL, LL> > vs;
	vs.emplace_back(L, Linf);
	vs.emplace_back(-Linf, U);
	for(int i=1; i<=m; i++)
	{
		// printf("q= %lld\n", q[i]);
		LL ql = q[i] / L, qr = (q[i] + U - 1) / U;
		if(ql >= qr) continue;
		vs.emplace_back(q[i] / qr, ql == 0 ? Linf : (q[i] + ql - 1) / ql);
		// printf("hehe %lld %lld ql= %lld qr= %lld q=%lld\n", vs.back().ff, vs.back().ss, ql, qr, q[i]);
	}
	std::sort(vs.begin(), vs.end());
	LL ans = Linf, mx = U;
	for(int i=1; i<vs.size(); i++)
	{
		ans = std::min(ans, mx - vs[i].ff);
		mx = std::max(mx, vs[i].ss);
	}
	printf("%lld\n", ans);
}

int main()
{
	int tc;
	get1(tc);
	while(tc--) solve();
	return 0;
}