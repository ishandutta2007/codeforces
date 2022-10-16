#include <bits/stdc++.h>

using namespace std;

long long n,d,ps[100069];

int main()
{
	long long t,rr,i,k,z,sm,u;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		cin>>s;
		for(i=1;i<=n;i++)
		{
			k=-(s[i-1]-'0')*2+1;
			ps[i]=ps[i-1]+k;
		}
		sm=ps[n];
		z=0;
		if(sm)
		{
			u=(sm>0)*2-1;
			for(i=0;i<n;i++)
			{
				if(ps[i]*u<=d*u&&(ps[i]%abs(sm)+abs(sm))%abs(sm)==(d%abs(sm)+abs(sm))%abs(sm))
				{
					z++;
				}
			}
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(ps[i]==d)
				{
					z=-1;
					break;
				}
			}
		}
		printf("%lld\n",z);
	}
}