#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<200069> a[2];

int main()
{
	long long t,rr,ii,i,u;
	string s;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			cin>>s;
			for(i=1;i<=n;i++)
			{
				a[ii][i]=s[i-1]>'2';
			}
		}
		u=0;
		bad=0;
		for(i=1;i<=n;i++)
		{
			if(a[u][i])
			{
				u^=1;
				if(!a[u][i])
				{
					bad=1;
					break;
				}
			}
		}
		if(!u||bad)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}