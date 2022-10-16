#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,mn;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'0';
		}
		mn=a[1];
		for(i=1;i<=n;i++)
		{
			if(a[i]<mn)
			{
				mn--;
				break;
			}
			else if(a[i]>mn)
			{
				break;
			}
		}
		printf("%lld\n",(n-1)*9+mn);
	}
}