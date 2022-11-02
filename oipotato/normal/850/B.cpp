#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int c[2000010],x,y,z,n,maxnum;
long long ans,d[2000010];
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&z);
		maxnum=max(maxnum,z);
		c[z]++;
		d[z]+=z;
	}
	for(int i=1;i<=2000000;i++)
	{
		c[i]+=c[i-1];
		d[i]+=d[i-1];
	}
	ans=1ll*n*x;
	if(maxnum==1)
		ans=min(ans,1ll*n*y);
	for(int i=2;i<=maxnum;i++)
	{
		int p=i;
		long long tans=0;
		for(;p-i<maxnum;p+=i)
		{
			int k=floor(p-1.0*x/y);
			if(k>=p-i+1)
				tans+=1ll*(c[k]-c[p-i])*x+1ll*y*(1ll*(c[p]-c[k])*p-(d[p]-d[k]));
			else
				tans+=1ll*y*(1ll*(c[p]-c[p-i])*p-(d[p]-d[p-i]));
		}
		ans=min(ans,tans);
	}
	cout<<ans<<endl;
	return 0;
}