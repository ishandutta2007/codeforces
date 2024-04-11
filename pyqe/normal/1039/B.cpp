#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long lh,rh,md,z;
	string s;
	
	srand(time(NULL));
	scanf("%lld%lld",&n,&d);
	for(lh=1,rh=n;lh<=rh;)
	{
		if(rh-lh+1>d*4+1)
		{
			md=(lh+rh)/2;
			printf("%lld %lld\n",lh,md);
			fflush(stdout);
			cin>>s;
			if(s[0]=='Y')
			{
				rh=md;
			}
			else
			{
				lh=md+1;
			}
		}
		else
		{
			z=lh+rand()%(rh-lh+1);
			printf("%lld %lld\n",z,z);
			fflush(stdout);
			cin>>s;
			if(s[0]=='Y')
			{
				break;
			}
		}
		lh=max(lh-d,1ll);
		rh=min(rh+d,n);
	}
}