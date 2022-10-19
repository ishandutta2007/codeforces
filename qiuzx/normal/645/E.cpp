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
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 28
using namespace std;
struct Matrix{
	ll n,v[N][N],nv[N][N];
	void init(ll _n)
	{
		n=_n;
		memset(v,0,sizeof(v));
		return;
	}
	void tms(Matrix a)
	{
		ll i,j,k;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				nv[i][j]=0;
				for(k=0;k<n;k++)
				{
					nv[i][j]=(nv[i][j]+v[i][k]*a.v[k][j])%mod;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				v[i][j]=nv[i][j];
			}
		}
		return;
	}
};
ll n,m,k,f[N],coef[N][N],lst[N],ord[N],sum=0;
bool cmp(ll x,ll y)
{
	return (lst[x]<lst[y]);
}
Matrix ksm(Matrix x,ll y)
{
	ll i;
	Matrix ret;
	ret.init(k+1);
	for(i=0;i<=k;i++)
	{
		ret.v[i][i]=1;
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
char buf[1000010];
int main(){
	ll i,j,l,x;
	scanf("%lld%lld",&m,&k);
	scanf("%s",&buf);
	n=strlen(buf);
	memset(f,0,sizeof(f));
	memset(lst,0,sizeof(lst));
	for(i=0;i<n;i++)
	{
		x=buf[i]-'a';
		lst[x]=i+1;
		ll ns=(sum+mod-f[x])%mod;
		f[x]=(sum+1)%mod;
		sum=(ns+f[x])%mod;
	}
	for(i=0;i<k;i++)
	{
		ord[i]=i;
	}
	f[k]=1;
	sort(ord,ord+k,cmp);
	for(i=0;i<=k;i++)
	{
		coef[i][i]=1;
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<=k;j++)
		{
			for(l=0;l<k;l++)
			{
				if(l!=ord[i])
				{
					coef[j][ord[i]]=(coef[j][ord[i]]+coef[j][l])%mod;
				}
			}
		}
		coef[k][ord[i]]=(coef[k][ord[i]]+1)%mod;
	}
	Matrix pre;
	pre.init(k+1);
	for(i=0;i<=k;i++)
	{
		for(j=0;j<=k;j++)
		{
			pre.v[i][j]=coef[i][j];
		}
	}
	pre=ksm(pre,m/k);
	Matrix val;
	val.init(k+1);
	for(i=0;i<=k;i++)
	{
		val.v[i][i]=f[i];
	}
	val.tms(pre);
	memset(f,0,sizeof(f));
	for(i=0;i<=k;i++)
	{
		for(j=0;j<k;j++)
		{
			f[j]=(f[j]+val.v[i][j])%mod;
		}
	}
	sum=0;
	for(i=0;i<k;i++)
	{
		sum=(sum+f[i])%mod;
	}
	for(i=0;i<m%k;i++)
	{
		ll ns=(sum+mod-f[ord[i]])%mod;
		f[ord[i]]=(sum+1)%mod;
		sum=(ns+f[ord[i]])%mod;
	}
	printf("%lld\n",(sum+1)%mod);
	return 0;
}