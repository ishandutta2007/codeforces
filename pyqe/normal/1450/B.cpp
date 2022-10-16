#include <bits/stdc++.h>

using namespace std;

long long n,d,vy[169],vx[169];

int main()
{
	long long t,rr,i,j,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",vy+i,vx+i);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(abs(vy[i]-vy[j])+abs(vx[i]-vx[j])>d)
				{
					j=-1;
					break;
				}
			}
			if(j!=-1)
			{
				i=-1;
				break;
			}
		}
		z=(i==-1)*2-1;
		printf("%lld\n",z);
	}
}