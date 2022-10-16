#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,sm,c;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		if(n%2)
		{
			printf("NO\n");
			continue;
		}
		sm=0;
		c=0;
		for(i=1;i<=n;i++)
		{
			k=(s[i-1]=='(')-(s[i-1]==')');
			if(!k)
			{
				c++;
				k=(long long)(c<=n/2-1)*2-1;
			}
			sm+=k;
			if(sm<0)
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