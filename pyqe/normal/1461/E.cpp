#include <bits/stdc++.h>

using namespace std;

long long st,lb,rb,n,d,d2,pr[1000069],wg[1000069],inf=1e18;
bitset<1000069> vtd;

void yes()
{
	printf("Yes\n");
	exit(0);
}

void no()
{
	printf("No\n");
	exit(0);
}

int main()
{
	long long i,k,z;
	
	scanf("%lld%lld%lld%lld%lld%lld",&st,&lb,&rb,&n,&d,&d2);
	rb-=d;
	d2-=d;
	if(!d2)
	{
		if(st-(st-lb)/d*d<=rb)
		{
			yes();
		}
		else
		{
			no();
		}
	}
	else
	{
		if(d2<0)
		{
			d2*=-1;
			k=(max(st-(rb+d2),0ll)+d-1)/d;
			if(k+(st-d*k-lb)/d2>=n)
			{
				yes();
			}
			else
			{
				no();
			}
		}
		else
		{
			for(i=0;i<d;i++)
			{
				k=(max(d2-i,0ll)+d-1)/d;
				pr[i]=i+d*k-d2;
				wg[i]=k+1;
			}
			k=(max(st-rb,0ll)+d-1)/d-(max(rb-d+1-st,0ll)+d-1)/d;
			z=k;
			for(st-=k*d;1;st=rb-pr[rb-st])
			{
				if(vtd[rb-st])
				{
					yes();
				}
				vtd[rb-st]=1;
				if(rb-pr[rb-st]-d2<lb)
				{
					break;
				}
				z+=wg[rb-st];
			}
			z+=(st-lb)/d;
			if(z>=n)
			{
				yes();
			}
			else
			{
				no();
			}
		}
	}
}