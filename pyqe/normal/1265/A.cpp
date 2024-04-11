#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,j;
	string s;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			if(s[i-1]=='?')
			{
				a[i]=-1;
			}
			else
			{
				a[i]=s[i-1]-'a';
			}
		}
		bad=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]==-1)
			{
				for(j=0;j<3;j++)
				{
					if(a[i-1]!=j&&a[i+1]!=j)
					{
						a[i]=j;
						break;
					}
				}
			}
			if(i>1&&a[i]==a[i-1])
			{
				bad=1;
				break;
			}
		}
		if(bad)
		{
			printf("-1\n");
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				printf("%c",a[i]+'a');
			}
			printf("\n");
		}
	}
}