#include <bits/stdc++.h>

using namespace std;

long long n[2],d,a[2][100069],sq[200069];

int main()
{
	long long t,rr,i,ii,p[2],e;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&d,n,n+1);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n[ii];i++)
			{
				scanf("%lld",&a[ii][i]);
			}
			p[ii]=1;
		}
		for(i=1;i<=n[0]+n[1];i++)
		{
			e=p[0]>n[0]||(p[1]<=n[1]&&a[1][p[1]]<a[0][p[0]]);
			if(a[e][p[e]]>d)
			{
				break;
			}
			sq[i]=a[e][p[e]];
			d+=!a[e][p[e]];
			p[e]++;
		}
		if(i>n[0]+n[1])
		{
			for(i=1;i<=n[0]+n[1];i++)
			{
				printf("%lld%c",sq[i]," \n"[i==n[0]+n[1]]);
			}
		}
		else
		{
			printf("-1\n");
		}
	}
}