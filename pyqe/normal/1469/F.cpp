#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069],ps[400069],inf=1e18;

int main()
{
	long long i,j,k,lh,rh,md,zz=-1,c;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		a[i]--;
	}
	sort(a+1,a+n+1,greater<long long>());
	for(lh=0,rh=inf;lh<=rh;)
	{
		md=(lh+rh)/2;
		c=1;
		for(i=0;i<=n*2;i++)
		{
			ps[i]=0;
		}
		ps[0]++;
		ps[1]--;
		for(j=0,i=1;i<=n;i++)
		{
			for(;!ps[j];j++,ps[j]+=ps[j-1]);
			k=max(min((md-(j+1))*2,a[i]),0ll);
			if(k<1)
			{
				break;
			}
			c+=k-1;
			ps[j]--;
			ps[j+1]++;
			ps[j+2]+=2;
			ps[min(j+2+k/2,n*2+1)]--;
			ps[min(j+2+(k+1)/2,n*2+1)]--;
		}
		if(c>=d)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld\n",zz);
}