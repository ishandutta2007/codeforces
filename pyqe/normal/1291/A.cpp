#include <bits/stdc++.h>

using namespace std;

long long n,sq[2],zs;

int main()
{
	long long t,rr,i,k;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		cin>>s;
		zs=0;
		for(i=1;i<=n;i++)
		{
			k=s[i-1]-'0';
			if(k%2)
			{
				sq[zs]=k;
				zs++;
				if(zs==2)
				{
					break;
				}
			}
		}
		if(zs==2)
		{
			printf("%lld%lld\n",sq[0],sq[1]);
		}
		else
		{
			printf("-1\n");
		}
	}
}