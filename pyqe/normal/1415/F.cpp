#include <bits/stdc++.h>

using namespace std;

long long n,ti[5069],a[5069],fh[5069],inf=1e18;
bitset<5069> spc;

int main()
{
	long long i,j;
	bool bad;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",ti+i,a+i);
		fh[i]=inf;
	}
	for(i=1;i<=n;i++)
	{
		fh[i]=min(fh[i],max(fh[i-1]+abs(a[i-1]-a[i]),ti[i-1]));
		if(spc[i-1])
		{
			fh[i]=min(fh[i],max(ti[i-2]+abs(a[i-2]-a[i]),ti[i-1]));
		}
		bad=0;
		for(j=i-1;j;j--)
		{
			if(abs(a[j-1]-a[j])<=ti[j]-fh[j-1]||(spc[j-1]&&abs(a[j-2]-a[j])<=ti[j]-ti[j-2]))
			{
				fh[i]=min(fh[i],ti[i-1]+abs(a[i-1]-a[i]));
				spc[i]=spc[i]||bad||abs(a[i]-a[j])<=ti[j]-max(fh[j-1]+abs(a[j-1]-a[i]),ti[j-1])||(spc[j-1]&&abs(a[i]-a[j])<=ti[j]-max(ti[j-2]+abs(a[j-2]-a[i]),ti[j-1]));
			}
			if(abs(a[j-1]-a[j])>ti[j]-ti[j-1])
			{
				break;
			}
			bad|=abs(a[i]-a[j])<=ti[j]-(ti[j-1]+abs(a[j-1]-a[i]));
		}
		if(fh[i]>ti[i])
		{
			fh[i]=inf;
		}
	}
	if(fh[n]<=ti[n]||spc[n])
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}