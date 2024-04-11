#include <bits/stdc++.h>

using namespace std;

long long n[2],a[2][1069],zs;

int main()
{
	long long t,rr,i,ii;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			cin>>s;
			n[ii]=s.length();
			for(i=0;i<n[ii];i++)
			{
				a[ii][i]=s[i]-'a';
			}
		}
		zs=n[0]/__gcd(n[0],n[1])*n[1];
		for(i=0;i<zs;i++)
		{
			if(a[0][i%n[0]]!=a[1][i%n[1]])
			{
				break;
			}
		}
		if(i==zs)
		{
			for(i=0;i<zs;i++)
			{
				printf("%c",(char)(a[0][i%n[0]]+'a'));
			}
			printf("\n");
		}
		else
		{
			printf("-1\n");
		}
	}
}