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
#define N 510
using namespace std;
double eps=1e-10;
ll n,m,p,a[N],deg[N],ed[N][N];
double f[N][N],g[N][N],coef[110][110],ans[110][110],ret[110][110];
vector<ll> gd;
void tms(double v[110][110],double b[110][110])
{
	ll i,j,k;
	for(i=0;i<110;i++)
	{
		for(j=0;j<110;j++)
		{
			ret[i][j]=0;
		}
	}
	for(i=0;i<110;i++)
	{
		for(j=0;j<110;j++)
		{
			for(k=0;k<110;k++)
			{
				ret[i][j]+=v[i][k]*b[k][j];
			}
		}
	}
	for(i=0;i<110;i++)
	{
		for(j=0;j<110;j++)
		{
			v[i][j]=ret[i][j];
		}
	}
	return;
}
void ksm(double v[110][110],double bas[110][110],ll x)
{
	while(x)
	{
		if(x&1)
		{
			tms(v,bas);
		}
		tms(bas,bas);
		x>>=1;
	}
	return;
}
int main(){
	ll i,j,k,x,y;
	scanf("%lld%lld%lld",&n,&m,&p);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i])
		{
			gd.push_back(i);
		}
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--,y--;
		ed[x][y]++,ed[y][x]++;
		deg[x]++,deg[y]++;
	}
	for(i=0;i<n;i++)
	{
		g[i][i]=1;
		for(j=0;j<n;j++)
		{
			f[i][j]=(double)(i==j)-(double)(a[i]==0)*(double)(ed[i][j])/(double)deg[i];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(f[j][i]>=eps)
			{
				break;
			}
		}
		for(k=0;k<n;k++)
		{
			swap(f[j][k],f[i][k]);
			swap(g[j][k],g[i][k]);
		}
		double dv=f[i][i];
		for(j=0;j<n;j++)
		{
			f[i][j]/=dv,g[i][j]/=dv;
		}
		for(j=0;j<n;j++)
		{
			if(j!=i)
			{
				dv=f[j][i];
				for(k=0;k<n;k++)
				{
					f[j][k]-=dv*f[i][k];
					g[j][k]-=dv*g[i][k];
				}
			}
		}
	}
	for(i=0;i<gd.size();i++)
	{
		for(j=0;j<gd.size();j++)
		{
			for(k=0;k<n;k++)
			{
				coef[i][j]=coef[i][j]+g[k][gd[j]]*(double)ed[gd[i]][k]/(double)deg[gd[i]];
			}
		}
	}
	for(i=0;i<gd.size();i++)
	{
		ans[i][i]=1;
	}
	ksm(ans,coef,p-2);
	double res=0;
	for(i=0;i<gd.size();i++)
	{
		res+=g[0][gd[i]]*ans[i][gd.size()-1];
	}
	printf("%.10lf\n",res);
	return 0;
}