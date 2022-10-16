#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn,nm,a[2000069],dp[2000069],sq[2000069],zs=0,inf=1e18;
vector<long long> vl[2000069];

int main()
{
	long long t,rr,i,j,ii,k,p[2],e,sz,z;
	pair<long long,long long> mne;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		nn=(1ll<<n)-1;
		nm=(1ll<<m)-1;
		z=0;
		for(i=1;i<=nn;i++)
		{
			scanf("%lld",a+i);
			z+=a[i];
		}
		zs=0;
		for(i=nn;i;i--)
		{
			vl[i].clear();
			dp[i]=-inf;
			if(i*2<=nn)
			{
				sz=vl[i*2].size()-1;
				for(ii=0;ii<2;ii++)
				{
					p[ii]=0;
				}
				for(;min(p[0],p[1])<sz;)
				{
					mne=min(mp(vl[i*2][p[0]],0),{vl[i*2+1][p[1]],1});
					e=mne.sc;
					vl[i].push_back(vl[i*2+e][p[e]]);
					p[e]++;
				}
			}
			vl[i].push_back(a[i]);
			if(i<=nm)
			{
				k=upper_bound(vl[i].begin(),vl[i].end(),max(dp[i*2],dp[i*2+1]))-vl[i].begin();
				dp[i]=vl[i][k];
				sz=vl[i].size();
				for(j=k;j<sz-1;j++)
				{
					vl[i][j]=vl[i][j+1];
				}
				vl[i].pop_back();
			}
			vl[i].push_back(inf);
		}
		for(i=0;i<nn-nm;i++)
		{
			z-=vl[1][i];
		}
		for(i=1;i<=nn;i++)
		{
			sz=vl[i].size()-1;
			for(j=0;j<sz;j++)
			{
				if(vl[i][j]>=max(dp[i],vl[1][0])&&(i==1||vl[i][j]<dp[i/2]))
				{
					zs++;
					sq[zs]=i;
				}
			}
		}
		printf("%lld\n",z);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}