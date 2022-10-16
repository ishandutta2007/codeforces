#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,nn[2],nr[100069],sbt[100069],a[2][3000069],inf=1e18;
vector<pair<long long,pair<long long,long long>>> al[100069];

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,w,ky;
	bool lf=1;
	
	sbt[x]=0;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc.fr;
		ky=al[x][i].sc.sc;
		if(nr[x]+w<nr[l])
		{
			nr[l]=nr[x]+w;
			dfs(l);
			sbt[x]+=sbt[l];
			lf=0;
			for(;w;w/=2)
			{
				nn[ky]++;
				a[ky][nn[ky]]=(w-w/2)*sbt[l];
			}
		}
	}
	d+=nr[x]*lf;
	sbt[x]+=lf;
}

int main()
{
	long long t,rr,i,ii,k,l,w,ky,e,z;
	pair<long long,long long> mxe;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			nr[i]=inf;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld%lld%lld",&k,&l,&w,&ky);
			ky--;
			al[k].push_back({l,{w,ky}});
			al[l].push_back({k,{w,ky}});
		}
		d*=-1;
		for(ii=0;ii<2;ii++)
		{
			nn[ii]=0;
		}
		nr[1]=0;
		dfs(1);
		for(ii=0;ii<2;ii++)
		{
			sort(a[ii]+1,a[ii]+nn[ii]+1);
		}
		z=0;
		for(;d>0;)
		{
			if(d-a[0][nn[0]]<=0)
			{
				z++;
				d-=a[0][nn[0]];
				nn[0]--;
			}
			else
			{
				mxe={-inf,-1};
				if(nn[0]>=2)
				{
					mxe={a[0][nn[0]]+a[0][nn[0]-1],0};
				}
				if(nn[1])
				{
					mxe=max(mxe,{a[1][nn[1]],1});
				}
				e=mxe.sc;
				d-=a[e][nn[e]];
				nn[e]--;
				z+=e+1;
			}
		}
		printf("%lld\n",z);
	}
}