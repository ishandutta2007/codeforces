#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,df;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		cin>>s;
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'a';
		}
		for(i=1;i<=n+1-i;i++)
		{
			df=abs(a[i]-a[n+1-i]);
			if(df&&df!=2)
			{
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}