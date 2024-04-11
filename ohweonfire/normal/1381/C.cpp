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

const int maxn = 200111;

int n, x, y, a[maxn], cnt[maxn], b[maxn];

void solve()
{
	get3(n, x, y);
	for(int i=1; i<=n; i++) get1(a[i]);
	
	for(int i=1; i<=n+1; i++) cnt[i] = b[i] = 0;
	std::vector<pii> ord;
	for(int i=1; i<=n; i++)
	{
		cnt[a[i]]++;
		ord.pb(mp(cnt[a[i]], i));
	}
	std::sort(ord.begin(), ord.end(), std::greater<pii>());
	for(int i=0; i<x; i++) b[ord[i].ss] = a[ord[i].ss];
	
	int other = 1;
	while(cnt[other]) other++;
	for(int i=1; i<=n+1; i++) cnt[i] = 0;
	// for(int i=1; i<=n; i++) printf("%d ", b[i]);
	// puts("");
	
	std::set<pii> sl, sr;
	std::set<pii> st;
	for(int i=1; i<=n; i++) if(!b[i])
	{
		cnt[a[i]] += 2;
		sl.insert(mp(a[i], i));
		sr.insert(mp(a[i], i));
	}
	for(int i=1; i<= n - y; i++)
	{
		cnt[other] += 2;
		sl.insert(mp(other, i + n));
		sr.insert(mp(other, i + n));
	}
	for(int i=1; i<=n+1; i++) st.insert(mp(cnt[i], i));
	
	while(true)
	{
		int large = st.rbegin() -> ss, lp;
		if(st.rbegin() -> ff == 0) break;
		auto it = sl.lower_bound(mp(large, 0));
		if(it != sl.end() && it -> ff == large)
		{
			lp = it -> ss;
			int small, sp;
			if(large != sr.begin() -> ff) small = sr.begin() -> ff, sp = sr.begin() -> ss;
			else if(large != sr.rbegin() -> ff) small = sr.rbegin() -> ff, sp = sr.rbegin() -> ss;
			else
			{
				puts("NO");
				return;
			}
			sl.erase(mp(large, lp));
			sr.erase(mp(small, sp));
			b[lp] = small;
			// printf("large1= %d %d %d %d\n", large, lp, small, sp);
			
			st.erase(mp(cnt[large], large));
			st.erase(mp(cnt[small], small));
			cnt[large]--;
			cnt[small]--;
			st.insert(mp(cnt[large], large));
			st.insert(mp(cnt[small], small));
		}
		else
		{
			it = sr.lower_bound(mp(large, 0));
			lp = it -> ss;
			
			int small, sp;
			if(large != sl.begin() -> ff) small = sl.begin() -> ff, sp = sl.begin() -> ss;
			else if(large != sl.rbegin() -> ff) small = sl.rbegin() -> ff, sp = sl.rbegin() -> ss;
			else
			{
				puts("NO");
				return;
			}
			sr.erase(mp(large, lp));
			sl.erase(mp(small, sp));
			b[sp] = large;
			// printf("large2= %d %d %d %d\n", large, lp, small, sp);
			
			st.erase(mp(cnt[large], large));
			st.erase(mp(cnt[small], small));
			cnt[large]--;
			cnt[small]--;
			st.insert(mp(cnt[large], large));
			st.insert(mp(cnt[small], small));
		}
	}
	
	puts("YES");
	for(int i=1; i<=n; i++) printf("%d ", b[i]);
	puts("");
}

int main()
{
	int tc;
	get1(tc);
	while(tc--) solve();
	return 0;
}