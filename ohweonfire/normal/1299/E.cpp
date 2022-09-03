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

int query(const std::vector<int> &v)
{
	if(v.size() == 1) return 1;
	printf("? %u", v.size());
	for(int i=0; i<v.size(); i++) printf(" %d",v[i]);
	puts("");
	fflush(stdout);
	int ret;
	get1(ret);
	return ret;
}

const int maxn = 1111;
int n, pos[maxn], a[maxn];
int MOD, rem[maxn];

void ASK(int l, int r)
{
	std::vector<int> all;
	for(int i=1; i<=n; i++) if(!a[i]) all.pb(i);
	if(l == 1 && r == n)
	{
		for(int i=1; i<=n; i++)
		{
			std::vector<int> tmp = all;
			tmp.erase(std::find(tmp.begin(), tmp.end(), i));
			if(query(tmp))
			{
				if(!pos[l])
				{
					a[i] = l;
					pos[l] = i;
				}
				else
				{
					a[i] = r;
					pos[r] = i;
				}
				
			}
			if(pos[l] && pos[r]) return;
		}
	}
	for(int i=0; i<(int)all.size(); i++) if(rem[all[i]] == l % MOD)
	{
		std::vector<int> tmp = all;
		tmp.erase(std::find(tmp.begin(), tmp.end(), all[i]));
		if(query(tmp))
		{
			pos[l] = all[i];
			a[all[i]] = l;
			break;
		}
	}
	for(int i=0; i<(int)all.size(); i++) if(rem[all[i]] == r % MOD)
	{
		std::vector<int> tmp = all;
		tmp.erase(std::find(tmp.begin(), tmp.end(), all[i]));
		if(query(tmp))
		{
			pos[r] = all[i];
			a[all[i]] = r;
			break;
		}
	}
}

int main()
{
	get1(n);
	if(n <= 2)
	{
		printf("!");for(int i=1; i<=n; i++)printf(" %d", i);
		puts("");
		fflush(stdout);
		return 0;
	}
	
	ASK(1, n);
	MOD = 2;
	for(int i=1; i<=n; i++) if(!a[i]) rem[i] = query({pos[1], i});
	for(int i=2; i<=n/2; i++)
	{
		ASK(i, n-i+1);
		if(i == MOD)
		{
			int sum = 0;
			std::vector<int> all, tmp;
			for(int j=1; j<=n; j++) if(a[j])
			{
				sum += a[j];
				all.pb(j);
			}
			for(int j=1; j<=n; j++) if(!a[j])
			{
				int P1 = rem[j], P2 = rem[j] + MOD;
				P1 = (sum + P1) % (MOD * 2);
				P2 = (sum + P2) % (MOD * 2);
				if(1 <= P1 && P1 <= MOD)
				{
					std::vector<int> tmp = all;
					*std::find(tmp.begin(), tmp.end(), pos[P1]) = j;
					if(!query(tmp)) rem[j] += MOD;
				}
				else
				{
					assert(1 <= P2 && P2 <= MOD);
					std::vector<int> tmp = all;
					*std::find(tmp.begin(), tmp.end(), pos[P2]) = j;
					if(query(tmp)) rem[j] += MOD;
				}
			}
			MOD <<= 1;
		}
	}
	if(a[1] > n/2) for(int i=1; i<=n; i++) a[i] = n - a[i] + 1;
	printf("!");for(int i=1; i<=n; i++) printf(" %d", a[i]); puts("");
	fflush(stdout);
	return 0;
}