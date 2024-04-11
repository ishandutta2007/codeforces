#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
const ll S=1<<7;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
bool have(ll x,ll y) {return (x>>y)&1;}
void up(ll &x,ll y) {x=max(x,y);}
struct node
{
	ll x,s[7];
	bool operator <(const node &a)const
	{
		return x>a.x;
	}
}a[N];
ll dp[N][S],popcount[S];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll n=read(),p=read(),k=read();
	for (ll i=1;i<=n;i++) a[i].x=read();
	for (ll i=1;i<=n;i++)
	for (ll j=0;j<p;j++) a[i].s[j]=read();
	sort(a+1,a+1+n);
	ll ans=0;
	for (ll i=1;i<=k;i++) ans+=a[i].x;
	memset(dp,0xc0,sizeof(dp));
	dp[0][0]=0;
	for (ll s=0;s<(1<<p);s++) popcount[s]=__builtin_popcount(s);
	for (ll i=1;i<=n;i++)
	for (ll s=0;s<(1<<p);s++)
	{
		up(dp[i][s],dp[i-1][s]);
		for (ll j=0;j<7;j++)
		if (!have(s,j))
		{
			if (i<=k+popcount[s]) up(dp[i][s|(1<<j)],dp[i-1][s]-a[i].x+a[k+popcount[s]+1].x+a[i].s[j]);
							 else up(dp[i][s|(1<<j)],dp[i-1][s]+a[i].s[j]);
		}
	}
	print(ans+=dp[n][(1<<p)-1]);
	
	return 0;
}