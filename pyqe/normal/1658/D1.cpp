#include <bits/stdc++.h>

using namespace std;

const long long mm=17;
long long d,d2,n,a[200069],fq[2][mm],ca[200069];

int main()
{
	long long t,rr,i,j,ii,jj,k,e,e2,c[2],z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&d,&d2);
		n=d2-d+1;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		if(d==d2)
		{
			printf("%lld\n",d^a[1]);
			continue;
		}
		for(i=mm-1;i>=0;i--)
		{
			if((d>>i&1)!=(d2>>i&1))
			{
				break;
			}
		}
		e=i;
		for(ii=0;ii<2;ii++)
		{
			for(jj=0;jj<2;jj++)
			{
				c[jj]=0;
				for(i=0;i<e;i++)
				{
					fq[jj][i]=0;
				}
			}
			for(i=1;i<=n;i++)
			{
				e2=(a[i]>>e&1)^ii;
				c[e2]++;
				for(j=0;j<e;j++)
				{
					fq[e2][j]+=a[i]>>j&1;
				}
				if(e2)
				{
					k=a[i];
				}
			}
			z=(d2^k)>>e<<e;
			for(i=0;i<e;i++)
			{
				z|=(long long)(fq[1][i]>c[1]-fq[1][i]||c[0]-fq[0][i]>fq[0][i])<<i;
			}
			for(i=1;i<=n;i++)
			{
				ca[i]=a[i]^z;
			}
			sort(ca+1,ca+n+1);
			if(ca[1]==d&&ca[n]==d2)
			{
				break;
			}
		}
		printf("%lld\n",z);
	}
}