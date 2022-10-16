#include <bits/stdc++.h>

using namespace std;

long long n,m,as[100069];

inline long long dis(long long y,long long x,long long y2,long long x2)
{
	return abs(y-y2)+abs(x-x2);
}

int main()
{
	long long t,rr,i,j;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				as[(i-1)*m+j]=max({dis(i,j,1,1),dis(i,j,1,m),dis(i,j,n,1),dis(i,j,n,m)});
			}
		}
		sort(as+1,as+n*m+1);
		for(i=1;i<=n*m;i++)
		{
			printf("%lld%c",as[i]," \n"[i==n*m]);
		}
	}
}