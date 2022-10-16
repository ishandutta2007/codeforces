#include <bits/stdc++.h>

using namespace std;

long long n,nn[2],a[200069],as[2][200069];

int main()
{
	long long t,rr,i,ii,u,k,p;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(ii=0;ii<2;ii++)
		{
			nn[ii]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			k=ch=='R';
			nn[k]++;
			as[k][nn[k]]=a[i];
		}
		p=1;
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			sort(as[ii]+1,as[ii]+nn[ii]+1);
			for(i=1;i<=nn[ii];i++)
			{
				if(as[ii][i]*u<p*u)
				{
					break;
				}
				p++;
			}
			if(i<=nn[ii])
			{
				break;
			}
		}
		if(ii>=2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}