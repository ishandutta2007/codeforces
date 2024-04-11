#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=9e4+5;
const ll inf=1ll<<60;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
struct node
{
	ll x,y,val,pos;
	bool operator <(const node &a)const
	{
		if (x==a.x) return y<a.y;
		return x<a.x;
	}
	bool operator <=(const node &a)const
	{
		if (x==a.x) return y<=a.y;
		return x<a.x;
	}
};
vector<node>a[N][4];
vector<ll>dp[N];
ll t[N],n,m,k,c[N],cnt=0;
bool b[N];
void add(ll x,ll y)
{
	for (;x<=m;x+=x&-x)
	{
		if (!b[x])
		{
			b[x]=1;
			c[++cnt]=x;
		}
		t[x]=min(t[x],y);
	}
}
ll query(ll x)
{
	ll ret=inf;
	for (;x;x-=x&-x) ret=min(ret,t[x]);
	return ret;
}

int main()
{
	n=read();
	m=read();
	k=read();
	for (ll i=1;i<=k;i++)
	for (ll j=0;j<=3;j++) a[i][j].clear();
	for (ll i=1;i<=n;i++)
	for (ll j=1;j<=m;j++)
	{
		ll v=read();
		a[v][0].push_back((node){i,j,i+j-1,dp[v].size()});
		a[v][1].push_back((node){n-i+1,j,n-i+1+j-1,dp[v].size()});
		a[v][2].push_back((node){i,m-j+1,i+m-j+1-1,dp[v].size()});
		a[v][3].push_back((node){n-i+1,m-j+1,n-i+1+m-j+1-1,dp[v].size()});
		dp[v].push_back(inf);
	}
	for (ll i=1;i<=k;i++)
	for (ll j=0;j<=3;j++) sort(a[i][j].begin(),a[i][j].end());
	dp[0].push_back(-1);
	a[0][0].push_back((node){0,1,0,0});
	memset(b,0,sizeof(b));
	for (ll i=1;i<=m;i++) t[i]=inf;
	for (ll i=1;i<=k;i++)
	for (ll j=0;j<=3;j++)
	{
		ll l=0,r=0;
		for (ll ii=1;ii<=cnt;ii++) b[c[ii]]=0,t[c[ii]]=inf;
		cnt=0;
		while (l<a[i-1][j].size()&&r<a[i][j].size())
		if (a[i-1][j][l]<a[i][j][r])
		{
			add(a[i-1][j][l].y,dp[i-1][a[i-1][j][l].pos]-a[i-1][j][l].val);
			l++;
		}
		else
		{
			dp[i][a[i][j][r].pos]=min(dp[i][a[i][j][r].pos],query(a[i][j][r].y)+a[i][j][r].val);
			r++;
		}
		while (l<a[i-1][j].size())
		{
			add(a[i-1][j][l].y,dp[i-1][a[i-1][j][l].pos]-a[i-1][j][l].val);
			l++;
		}
		while (r<a[i][j].size())
		{
			dp[i][a[i][j][r].pos]=min(dp[i][a[i][j][r].pos],query(a[i][j][r].y)+a[i][j][r].val);
			r++;
		}
	}
	ll ans=inf;
//	for (ll i=0;i<=k;i++){
//	for (ll j=0;j<dp[i].size();j++) print(dp[i][j],' ');puts("");}
	for (ll i=0;i<dp[k].size();i++) ans=min(ans,dp[k][i]);
	print(ans);

	return 0;
}