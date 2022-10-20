#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=705;
const ll p=1e9+7;

string a;
ll f[N][N][3][3],nxt[N];
ll dfs(ll l,ll r,ll lc,ll rc)
{
	if (~f[l][r][lc][rc]) return f[l][r][lc][rc];
	if (r-1==l) return f[l][r][lc][rc]=(lc>0)^(rc>0);
	if (nxt[l]==r)
	{
		if (!((lc>0)^(rc>0))) return f[l][r][lc][rc]=0;
		if (lc)
		return f[l][r][lc][rc]=(
			dfs(l+1,r-1,0,0)+
			dfs(l+1,r-1,0,1)+
			dfs(l+1,r-1,0,2)+
			dfs(l+1,r-1,3-lc,0)+
			dfs(l+1,r-1,3-lc,1)+
			dfs(l+1,r-1,3-lc,2))%p;
		else return f[l][r][lc][rc]=(
			dfs(l+1,r-1,0,0)+
			dfs(l+1,r-1,1,0)+
			dfs(l+1,r-1,2,0)+
			dfs(l+1,r-1,0,3-rc)+
			dfs(l+1,r-1,1,3-rc)+
			dfs(l+1,r-1,2,3-rc))%p;
	}
	else
	{
		ll ret=0;
		for (ll i=0;i<3;i++)
		for (ll j=0;j<3;j++)
		if (i!=j||(i==0&&j==0)) ret+=dfs(l,nxt[l],lc,i)*dfs(nxt[l]+1,r,j,rc)%p;
		return f[l][r][lc][rc]=ret%p;
	}
}

int main()
{
	memset(f,-1,sizeof(f));
	cin>>a;
	ll n=a.length(),ans=0;
	a=' '+a;
	for (ll i=1;i<=n;i++)
	for (ll j=i,top=0;j<=n;j++)
	{
		if (a[j]=='(') top++;
				  else top--;
		if (top==0)
		{
			nxt[i]=j;
			break;
		}
	}
	for (ll i=0;i<3;i++)
	for (ll j=0;j<3;j++) (ans+=dfs(1,n,i,j))%=p;
	printf("%lld",ans);

	return 0;
}