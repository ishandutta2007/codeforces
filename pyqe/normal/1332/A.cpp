#include <bits/stdc++.h>

using namespace std;

long long a[4];

int main()
{
	long long t,rr,i,ii,ys,xs,y,x,y2,x2;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<4;i++)
		{
			scanf("%lld",a+i);
		}
		scanf("%lld%lld%lld%lld%lld%lld",&ys,&xs,&y,&x,&y2,&x2);
		bad=0;
		for(ii=0;ii<2;ii++)
		{
			bad|=a[ii*2]+a[ii*2+1]&&y==y2;
			ys+=a[ii*2+1]-a[ii*2];
			swap(ys,xs);
			swap(y,x);
			swap(y2,x2);
		}
		if(!bad&&ys>=y&&ys<=y2&&xs>=x&&xs<=x2)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}