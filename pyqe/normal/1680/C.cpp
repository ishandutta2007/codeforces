#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,ps[200069];

int main()
{
	long long t,rr,i,w,w2,lh,rh,md,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			ps[i]=ps[i-1]+s[i-1]-'0';
		}
		z=inf;
		for(i=1;i<=n;i++)
		{
			for(lh=0,rh=i;lh<=rh;)
			{
				md=(lh+rh)/2;
				w=i-md-(ps[i]-ps[md]);
				w2=ps[n]-(ps[i]-ps[md]);
				z=min(z,max(w,w2));
				if(w>=w2)
				{
					lh=md+1;
				}
				else
				{
					rh=md-1;
				}
			}
		}
		printf("%lld\n",z);
	}
}