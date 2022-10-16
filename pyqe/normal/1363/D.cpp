#include <bits/stdc++.h>

using namespace std;

long long n,m,sz[1069],a[1069],sq[1069];

int main()
{
	long long t,rr,i,j,k,mx,lh,rh,md,zz;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			a[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%lld",sz+i);
			for(j=0;j<sz[i];j++)
			{
				scanf("%lld",&k);
				a[k]=i;
			}
		}
		printf("? %lld",n);
		for(i=1;i<=n;i++)
		{
			printf(" %lld",i);
		}
		printf("\n");
		fflush(stdout);
		scanf("%lld",&mx);
		for(lh=1,rh=n;lh<=rh;)
		{
			md=(lh+rh)/2;
			printf("? %lld",md);
			for(i=1;i<=md;i++)
			{
				printf(" %lld",i);
			}
			printf("\n");
			fflush(stdout);
			scanf("%lld",&k);
			if(k==mx)
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		for(i=1;i<=m;i++)
		{
			if(a[zz]!=i)
			{
				sq[i]=mx;
			}
			else
			{
				printf("? %lld",n-sz[i]);
				for(j=1;j<=n;j++)
				{
					if(a[j]!=i)
					{
						printf(" %lld",j);
					}
				}
				printf("\n");
				fflush(stdout);
				scanf("%lld",sq+i);
			}
		}
		printf("!");
		for(i=1;i<=m;i++)
		{
			printf(" %lld",sq[i]);
		}
		printf("\n");
		cin>>s;
	}
}