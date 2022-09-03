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

const int mod = 1e9+7;
const int maxn = 100111;
#define getcode(i,j) (((i)>>(j))&1)

const int SZ = 400;
std::unordered_map<unsigned, int> id;
inline unsigned add(unsigned msk, int add)
{
	int nmsk = msk;
	for(int i=0; i<32; i++) if(getcode(msk, i)) nmsk |= 1u << (i ^ add);
	return nmsk;
}
int tot, single[32];
unsigned vs[SZ], addv[SZ][32], merge[SZ][SZ];
void dfs(unsigned msk)
{
	if(id.find(msk)!=id.end()) return;
	id[msk] = tot;
	vs[tot] = msk;
	tot++;
	for(int i=0; i<32; i++) dfs(add(msk, i));
}

void prework()
{
	dfs(1);
	id[0] = tot;
	vs[tot++] = 0;
	for(int i=0; i<tot; i++)
	{
		for(int j=0; j<32; j++) addv[i][j] = id[add(vs[i], j)];
	}
	for(int i=0; i<tot; i++) for(int j=0; j<tot; j++)
	{
		int cur = i;
		for(int k=0; k<32; k++) if(getcode(vs[j],k)) cur = addv[cur][k];
		if((vs[i] & vs[j]) > 1) cur = id[0];
		if(vs[i] == 0 || vs[j] == 0) cur = id[0];
		merge[i][j] = cur;
	}
	single[0] = id[0];
	for(int i=1; i<32; i++) single[i] = id[1u<<i | 1];
}

int f[maxn], fv[maxn], bid[maxn];
int gf(int x)
{
	if(x == f[x]) return x;
	gf(f[x]);
	fv[x] ^= fv[f[x]];
	f[x] = f[f[x]];
	return f[x];
}

void un(int x, int y, int w)
{
	gf(x); gf(y);
	w ^= fv[x] ^ fv[y];
	x = f[x];
	y = f[y];
	if(x == y) bid[x] = merge[bid[x]][single[w]];
	else
	{
		f[x] = y;
		fv[x] = w;
		bid[y] = merge[bid[y]][bid[x]];
	}
}

int dp[SZ], ndp[SZ];
int n, m, eu[maxn], ev[maxn], ew[maxn];

std::vector<int> have[maxn];
int main()
{
	prework();
	get2(n, m);
	for(int i=1; i<=m; i++) get3(eu[i], ev[i], ew[i]);
	
	for(int i=1; i<=n; i++) f[i] = i;
	for(int i=1; i<=m; i++) if(eu[i]!=1 && ev[i]!=1) un(eu[i], ev[i], ew[i]);
	
	for(int i=1; i<=m; i++)
	{
		if(eu[i] > ev[i]) std::swap(eu[i], ev[i]);
		if(eu[i] == 1) have[gf(ev[i])].pb(i);
	}
	dp[0] = 1;
	for(int i=1; i<=n; i++) if(f[i] == i && have[i].size())
	{
		if(have[i].size() == 1)
		{
			int now = bid[i];
			memcpy(ndp, dp, sizeof(dp));
			for(int j=0; j<tot; j++)
			{
				ndp[merge[j][now]] += dp[j];
				if(ndp[merge[j][now]] >= mod) ndp[merge[j][now]] -= mod;
			}
			memcpy(dp, ndp, sizeof(dp));
		}
		else
		{
			int e1 = have[i][0], e2 = have[i][1];
			gf(ev[e1]);gf(ev[e2]);
			int now1 = bid[i], now2 = merge[now1][single[ew[e1] ^ ew[e2] ^ fv[ev[e1]] ^ fv[ev[e2]]]];
			
			memcpy(ndp, dp, sizeof(dp));
			for(int j=0; j<tot; j++)
			{
				ndp[merge[j][now1]] += dp[j];
				if(ndp[merge[j][now1]] >= mod) ndp[merge[j][now1]] -= mod;
				ndp[merge[j][now1]] += dp[j];
				if(ndp[merge[j][now1]] >= mod) ndp[merge[j][now1]] -= mod;
				ndp[merge[j][now2]] += dp[j];
				if(ndp[merge[j][now2]] >= mod) ndp[merge[j][now2]] -= mod;
			}
			memcpy(dp, ndp, sizeof(dp));
		}
	}
	int ans = 0;
	for(int i=0; i<tot; i++) if(vs[i])
	{
		ans += dp[i];
		if(ans >= mod) ans -= mod;
	}
	printendl(ans);
	return 0;
}