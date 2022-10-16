#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<1069> vtd[1069];

int main()
{
	long long t,rr,i,j,ii,jj,y,x,yy,xx;
	
	scanf("%lld%lld",&n,&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&y,&x);
		vtd[y][x]=1;
		for(j=0,i=0;i<3&&j!=-1;i++)
		{
			for(j=0;j<3;j++)
			{
				for(jj=0,ii=0;ii<3&&jj!=-1;ii++)
				{
					for(jj=0;jj<3;jj++)
					{
						yy=y-i+ii;
						xx=x-j+jj;
						if(yy<=0||xx<=0||yy>n||xx>n||!vtd[yy][xx])
						{
							jj=-1;
							break;
						}
					}
				}
				if(jj!=-1)
				{
					j=-1;
					break;
				}
			}
		}
		if(j==-1)
		{
			printf("%lld\n",rr);
			return 0;
		}
	}
	printf("-1\n");
}