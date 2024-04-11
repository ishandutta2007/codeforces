#include <bits/stdc++.h>

using namespace std;

long long d,n=0,a[100069];

int main()
{
	long long i,ln,c=0,z=0;
	stringstream ss;
	string s;
	char ch;
	
	scanf("%lld",&d);
	getline(cin,s);
	getline(cin,s);
	ss<<s;
	for(;ss>>s;)
	{
		ln=s.length();
		c+=ln+1;
		ch=s[ln-1];
		if(ch=='.'||ch=='?'||ch=='!')
		{
			n++;
			a[n]=c-1;
			c=0;
			if(a[n]>d)
			{
				printf("Impossible\n");
				return 0;
			}
		}
	}
	c=-1;
	for(i=1;i<=n;i++)
	{
		if(c+a[i]+1>d)
		{
			z++;
			c=-1;
		}
		c+=a[i]+1;
	}
	z+=c>-1;
	printf("%lld\n",z);
}