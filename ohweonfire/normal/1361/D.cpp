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

const int maxn = 500111;

int n, k, x[maxn], y[maxn], st;

int main()
{
	get2(n, k);
	std::map<pii, std::vector<double> > dir;
	for (int i = 1; i <= n; i++)
	{
		get2(x[i], y[i]);
		if (x[i] == 0 && y[i] == 0)
			st = i;
		else
		{
			int g = std::__gcd(abs(x[i]), abs(y[i]));
			dir[mp(x[i] / g, y[i] / g)].push_back(sqrt(1.0 * x[i] * x[i] + 1.0 * y[i] * y[i]));
		}
	}
	
	std::vector<double> ds;
	ds.push_back(0);
	for(auto v : dir)
	{
		std::vector<double> d = v.second;
		std::sort(d.begin(), d.end());
		for(int i=0; i<d.size(); i++)
		{
			int rest = d.size() - i - 1;
			if(rest >= k / 2)
			{
				int num = k - k / 2 - (n - d.size());
				if(num < 0 || num <= i) ds.push_back(-1e100);
				else
				{
					rest = k / 2 + num - i - 1;
					ds.push_back(d[i] * (k - 1 - rest - rest));
				}
				
			}
			else ds.push_back(d[i] * (k - 1 - rest - rest));
		}
	}
	std::sort(ds.begin(), ds.end(), std::greater<double>());
	
	double ans = 0;
	for(int i=0; i<k; i++) ans += ds[i];
	printf("%.10lf\n", ans);
	return 0;
}