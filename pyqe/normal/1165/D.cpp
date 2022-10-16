#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,fq[1000069],mxa=1e6;
vector<pair<long long,long long>> fz[1000069];
bitset<1000069> vtd;

int main()
{
	long long t,rr,i,j,k,l,w,c,sz,mx,sm,z;
	
	for(i=2;i<=mxa;i++)
	{
		if(!vtd[i])
		{
			for(j=i;j<=mxa;j+=i)
			{
				vtd[j]=1;
				for(c=0,k=j;k%i==0;k/=i,c++);
				fz[j].push_back({i,c});
			}
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=mxa;i++)
		{
			fq[i]=0;
		}
		c=0;
		mx=-1e18;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			sz=fz[k].size();
			for(j=0;j<sz;j++)
			{
				l=fz[k][j].fr;
				w=fz[k][j].sc;
				c+=!fq[l];
				fq[l]=max(fq[l],w);
			}
			mx=max(mx,k);
		}
		sm=1;
		for(i=1;i<=mxa;i++)
		{
			if(c==1&&fq[i])
			{
				fq[i]++;
			}
			sm*=fq[i]+1;
			if(sm>n+2)
			{
				break;
			}
		}
		if(sm!=n+2)
		{
			printf("-1\n");
			continue;
		}
		z=1;
		for(i=1;i<=mxa;i++)
		{
			for(j=0;j<fq[i];j++)
			{
				z*=i;
			}
		}
		if(z==mx)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}