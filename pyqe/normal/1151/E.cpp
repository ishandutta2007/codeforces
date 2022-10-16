#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[100069],ps[100069];
pair<long long,long long> pst[100069];
bitset<100069> vtd;

int main()
{
	long long i,j,ii,k=0,p,ng=0,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<=n+1;i++)
	{
		pst[i]={a[i],i};
	}
	sort(pst+0,pst+n+2);
	for(j=n+1,i=n+1;i;i--)
	{
		for(;j>=0&&pst[j].fr>=i;j--)
		{
			k++;
			p=pst[j].sc;
			vtd[p]=1;
			for(ii=p-1;ii<=p+1;ii+=2)
			{
				k-=vtd[ii];
			}
		}
		ps[i]=ps[i+1]+k;
	}
	vtd.reset();
	k=0;
	for(j=0,i=0;i<n;i++)
	{
		for(;j<=n+1&&pst[j].fr<=i;j++)
		{
			k++;
			p=pst[j].sc;
			vtd[p]=1;
			for(ii=p-1;ii<=p+1;ii+=2)
			{
				if(ii>=0&&ii<=n+1)
				{
					k-=vtd[ii];
					if(vtd[ii])
					{
						ng-=a[p]-i-1;
					}
					else
					{
						ng+=a[ii]-i-1;
					}
				}
			}
		}
		z+=(k-1)*(n-i)+ps[i+2]-ng;
		ng-=k*2-2;
	}
	printf("%lld\n",z);
}