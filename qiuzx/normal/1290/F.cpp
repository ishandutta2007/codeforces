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
#define CUR dp[stg][a][b][c][d][tp1][tp2]
using namespace std;
ll n,m,dp[35][25][25][25][25][2][2],dx[10],dy[10];
ll dfs(ll stg,ll a,ll b,ll c,ll d,ll tp1,ll tp2)
{
	if(CUR!=-1)
	{
		return CUR;
	}
	CUR=0;
	if(stg>=30)
	{
		if(a==0&&b==0&&c==0&&d==0&&tp1==0&&tp2==0)
		{
			return CUR=1;
		}
		return CUR;
	}
	ll mask,i,j,na,nb,nc,nd,bita,bitb,bitc,bitd,bitm=((m>>stg)&1);
	for(mask=0;mask<(1<<n);mask++)
	{
		na=a;
		nb=b;
		nc=c;
		nd=d;
		for(i=0;i<n;i++)
		{
			if(mask&(1<<i))
			{
				if(dx[i]>=0)
				{
					na+=dx[i];
				}
				else
				{
					nb+=(-dx[i]);
				}
				if(dy[i]>=0)
				{
					nc+=dy[i];
				}
				else
				{
					nd+=(-dy[i]);
				}
			}
		}
		bita=(na&1);
		bitb=(nb&1);
		bitc=(nc&1);
		bitd=(nd&1);
		if(bita!=bitb||bitc!=bitd)
		{
			continue;
		}
		CUR=(CUR+dfs(stg+1,na/2,nb/2,nc/2,nd/2,(bita!=bitm)?(bita>bitm):tp1,(bitc!=bitm)?(bitc>bitm):tp2))%mod;
	}
	return CUR;
}
int main(){
	ll i;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>dx[i]>>dy[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<(dfs(0,0,0,0,0,0,0)+mod-1)%mod<<endl;
	return 0;
}