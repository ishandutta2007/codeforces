//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 300010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll ksm(ll x,ll y)
{
	ll ret=1;
	while(y>0)
	{
		if(y&1)
		{
			ret=(ret*x)%mod;
		}
		x=(x*x)%mod;
		y>>=1;
	}
	return ret;
}
ll n,k,a[N],dep[N],f[N][24],dp[N][2];
vector<ll> vt[N],colnd[N];
void dfs(ll x,ll lst,ll d)
{
	ll i;
	dep[x]=d;
	for(i=1;i<24;i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			f[vt[x][i]][0]=x;
			dfs(vt[x][i],x,d+1);
		}
	}
	return;
}
ll glca(ll x,ll y)
{
	if(x==y)
	{
		return x;
	}
	if(dep[x]<dep[y])
	{
		swap(x,y);
	}
	ll i;
	for(i=22;i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y])
		{
			x=f[x][i];
		}
	}
	if(x==y)
	{
		return x;
	}
	for(i=22;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
bool merg(ll x,ll fa,ll c)
{
	if(a[x]!=0&&a[x]!=c)
	{
		puts("0");
		exit(0);
	}
	if(a[fa]!=0&&a[fa]!=c)
	{
		puts("0");
		exit(0);
	}
	if(a[fa]==c)
	{
		a[x]=a[fa]=c;
		return true;
	}
	a[x]=a[fa]=c;
	return false;
}
void getdp(ll x,ll lst)
{
	ll pro=1,i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			getdp(vt[x][i],x);
			pro=(pro*(dp[vt[x][i]][0]+dp[vt[x][i]][1])%mod)%mod;
		}
	}
	if(a[x]==0)
	{
		dp[x][0]=pro;
		for(i=0;i<vt[x].size();i++)
		{
			if(vt[x][i]!=lst)
			{
				dp[x][1]=(dp[x][1]+(((pro*ksm((dp[vt[x][i]][0]+dp[vt[x][i]][1])%mod,mod-2))%mod)*dp[vt[x][i]][1])%mod)%mod;
			}
		}
	}
	else
	{
		dp[x][1]=pro;
	}
	return;
}
int main(){
	ll i,j,x,y,cnt;
	n=rint(),k=rint();
	for(i=0;i<n;i++)
	{
		a[i]=rint();
		if(a[i]>0)
		{
			colnd[a[i]].push_back(i);
		}
	}
	for(i=1;i<n;i++)
	{
		x=rint()-1,y=rint()-1;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	dfs(0,-1,0);
	for(i=1;i<=k;i++)
	{
		x=colnd[i][0];
		for(j=1;j<colnd[i].size();j++)
		{
			x=glca(x,colnd[i][j]);
		}
		for(j=0;j<colnd[i].size();j++)
		{
			y=colnd[i][j];
			while(y!=x)
			{
				if(merg(y,f[y][0],i))
				{
					break;
				}
				y=f[y][0];
			}
		}
	}
	getdp(0,-1);
	printf("%lld\n",dp[0][1]);
	return 0;
}