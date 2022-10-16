#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n&&s[i-1]=='a';i++);
		if(i>n)
		{
			printf("NO\n");
			continue;
		}
		z=n+1-i+(i<=n/2);
		printf("YES\n");
		for(i=1;i<=n+1;i++)
		{
			if(i==z)
			{
				printf("a");
			}
			if(i<=n)
			{
				printf("%c",s[i-1]);
			}
		}
		printf("\n");
	}
}