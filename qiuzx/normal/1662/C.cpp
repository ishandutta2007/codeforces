//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 210
using namespace std;
struct Matrix{
	ll v[N][N],nv[N][N];
	void tms(Matrix x)
	{
		ll i,j,k;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				nv[i][j]=0;
				for(k=0;k<N;k++)
				{
					nv[i][j]=(nv[i][j]+v[i][k]*x.v[k][j])%mod;
				}
			}
		}
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				v[i][j]=nv[i][j];
			}
		}
		return;
	}
};
Matrix ksm(Matrix x,ll y)
{
	Matrix ret;
	ll i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			ret.v[i][j]=(i==j);
		}
	}
	while(y)
	{
		if(y&1)
		{
			ret.tms(x);
		}
		x.tms(x);
		y>>=1;
	}
	return ret;
}
Matrix trs,res1,res2;
ll n,m,k,deg[N];
int main(){
	ll i,j,x,y;
	scanf("%lld%lld%lld",&n,&m,&k);
	memset(trs.v,0,sizeof(trs.v));
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--,y--;
		deg[x]++,deg[y]++;
		trs.v[x+n][y+n]=trs.v[y+n][x+n]=1;
	}
	for(i=0;i<n;i++)
	{
		trs.v[i+n][i]=1;
		trs.v[i][i+n]=(mod-deg[i]+1)%mod;
	}
	res1=res2=ksm(trs,k-1);
	res2.tms(trs);
	ll ans=0;
	for(i=0;i<n;i++)
	{
		ans=(ans+(res2.v[i+n][i]+res2.v[i+n][i+n]+mod-res1.v[i+n][i]+mod-res1.v[i+n][i+n])%mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}