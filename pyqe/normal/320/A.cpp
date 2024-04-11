#include <bits/stdc++.h>

using namespace std;

long long a[100069];

int main()
{
	long long ln,i,c=0;
	string s;
	
	cin>>s;
	ln=s.length();
	for(i=0;i<ln;i++)
	{
		a[i]=s[i]-'0';
	}
	for(i=0;i<ln;i++)
	{
		if((i==0&&a[i]!=1)||(i>0&&a[i]!=1&&a[i]!=4))
		{
			printf("NO\n");
			return 0;
		}
		if(a[i]==1)
		{
			c=0;
		}
		else if(a[i]==4)
		{
			c++;
			if(c>2)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
}