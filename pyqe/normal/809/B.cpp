#include <bits/stdc++.h>

using namespace std;

long long n,d;

long long slv(long long lb,long long rb)
{
	long long lh,rh,md;
	string s;
	
	if(lb>rb)
	{
		swap(lb,rb);
	}
	for(lh=lb,rh=rb;lh<rh;)
	{
		md=(lh+rh)/2;
		printf("1 %lld %lld\n",md,md+1);
		fflush(stdout);
		cin>>s;
		if(s[0]=='T')
		{
			rh=md;
		}
		else
		{
			lh=md+1;
		}
	}
	return lh;
}

int main()
{
	long long i,ii,u,p;
	string s;
	
	scanf("%lld%lld",&n,&d);
	p=slv(1,n);
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(i=0;p+(1ll<<i)*u>0&&p+(1ll<<i)*u<=n;i++)
		{
			printf("1 %lld %lld\n",p+(1ll<<i)*u,p+((1ll<<i)-1)*u);
			fflush(stdout);
			cin>>s;
			if(s[0]=='T')
			{
				printf("2 %lld %lld\n",p,slv(p+(1ll<<i)*u,1+(n-1)*!ii));
				return 0;
			}
		}
	}
}