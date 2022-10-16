#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i;
	bool fq[3],bad;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=0;i<3;i++)
		{
			fq[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'a';
			if(a[i]<3)
			{
				fq[a[i]]=1;
			}
		}
		cin>>s;
		bad=s=="abc"&&fq[0]&&fq[1]&&fq[2];
		if(bad)
		{
			for(i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					a[i]=2;
				}
				else if(a[i]==2)
				{
					a[i]=1;
				}
			}
		}
		sort(a+1,a+n+1);
		if(bad)
		{
			for(i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					a[i]=2;
				}
				else if(a[i]==2)
				{
					a[i]=1;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%c",(char)(a[i]+'a'));
		}
		printf("\n");
	}
}