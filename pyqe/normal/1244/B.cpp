#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,ft,ls;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		cin>>s;
		ft=-1;
		for(i=0;i<n;i++)
		{
			if(s[i]=='1')
			{
				if(ft==-1)
				{
					ft=i;
				}
				ls=i;
			}
		}
		if(ft==-1)
		{
			printf("%lld\n",n);
		}
		else
		{
			printf("%lld\n",2*(n-min(ft,n-1-ls)));
		}
	}
}