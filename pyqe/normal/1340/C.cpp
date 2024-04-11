#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long ln,n,d,d2,a[10069],nr[10069][1069],inf=1e9;
deque<pair<long long,long long>> dq;

int main()
{
	long long i,j,u,k,kk,w,l,ww,z=inf;
	
	scanf("%lld%lld",&ln,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	scanf("%lld%lld",&d,&d2);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<d;j++)
		{
			nr[i][j]=inf;
		}
	}
	dq.push_back({1,0});
	nr[1][0]=0;
	for(;!dq.empty();)
	{
		k=dq.front().fr;
		kk=dq.front().sc;
		dq.pop_front();
		w=nr[k][kk];
		for(u=-1;u<=1;u+=2)
		{
			if(k+u&&k+u<=n)
			{
				l=kk+abs(a[k+u]-a[k]);
				if(l<=d)
				{
					ww=w+l/d;
					if(ww<nr[k+u][l%d])
					{
						if(ww==w)
						{
							dq.push_front({k+u,l%d});
						}
						else
						{
							dq.push_back({k+u,l%d});
						}
						nr[k+u][l%d]=ww;
					}
				}
			}
		}
	}
	for(i=0;i<d;i++)
	{
		z=min(z,nr[n][i]*(d+d2)+i-d2*!i);
	}
	if(z==inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
}