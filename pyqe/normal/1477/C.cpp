#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d=2,pr[5069][5][5][1ll<<4];
pair<long long,long long> a[5069];

long long ds(long long x,long long y)
{
	long long lx=a[x].fr-a[y].fr,ly=a[x].sc-a[y].sc;
	
	return lx*lx+ly*ly;
}

bool chk(long long x,long long x2,long long y)
{
	return x<=0||ds(x,y)-ds(x,x2)<ds(x2,y);
}

int main()
{
	long long i,j,r,x,y,mk,p,e,e2;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&y);
		a[i]={x,y};
	}
	pr[0][0][0][(1ll<<d)-1]=1;
	for(i=1;i<=n;i++)
	{
		for(j=-d;j<=d;j++)
		{
			for(r=-d;r<=d;r++)
			{
				for(mk=0;mk<1ll<<d*2;mk++)
				{
					if(pr[i-1][j+d][r+d][mk])
					{
						for(p=-d;p<=d;p++)
						{
							if(i+p>0&&i+p<=n&&!(mk>>p+d&1)&&((mk&1)||p==-d)&&chk(i-2+j,i-1+r,i+p))
							{
								pr[i][r+d][p+d][(mk|1ll<<p+d)>>1]=i-2+j;
							}
						}
					}
				}
			}
		}
	}
	mk=3;
	for(i=-d;i<=d;i++)
	{
		for(j=-d;j<=d;j++)
		{
			if(pr[n][i+d][j+d][(1ll<<d)-1])
			{
				e2=j;
				e=i;
				break;
			}
		}
		if(j<=d)
		{
			break;
		}
	}
	printf("%lld %lld",n+e2,n-1+e);
	for(i=n-2;i;i--)
	{
		p=pr[i+2][e+d][e2+d][mk]-i;
		mk=(mk<<1|1)^1ll<<e2+d;
		e2=e;
		e=p;
		printf(" %lld",i+e);
	}
	printf("\n");
}