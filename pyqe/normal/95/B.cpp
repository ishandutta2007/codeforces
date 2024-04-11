#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],sq[100069];

int main()
{
	long long i,k,c=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	if(n%2)
	{
		n++;
		for(i=n;i;i--)
		{
			a[i]=a[i-1];
		}
	}
	for(i=1;i<=n;i++)
	{
		k=4+3*(i<=n/2);
		if(a[i]>k)
		{
			i=-1;
			break;
		}
		else if(a[i]<k)
		{
			break;
		}
	}
	if(i==-1)
	{
		n+=2;
		for(i=n;i;i--)
		{
			a[i]=a[max(i-2,0ll)];
		}
	}
	for(i=1;i<=n;i++)
	{
		sq[i]=4;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]>7)
		{
			sq[i]=7;
			for(;sq[i]==7;sq[i]=4,i--);
			sq[i]=7;
			break;
		}
		else if(a[i]!=4&&a[i]!=7)
		{
			sq[i]=4+3*(a[i]>4);
			break;
		}
		sq[i]=a[i];
	}
	for(i=1;i<=n;i++)
	{
		c+=sq[i]==4;
	}
	if(c<n/2)
	{
		k=0;
		for(i=n;i;i--)
		{
			if(k)
			{
				if(sq[i]==4)
				{
					sq[i]=7;
					k=0;
				}
				else
				{
					sq[i]=4;
					c++;
				}
			}
			if(sq[i]==7&&c<n/2)
			{
				sq[i]=4;
				k=1;
			}
		}
	}
	if(c>n/2)
	{
		for(i=n;i;i--)
		{
			if(sq[i]==4&&c>n/2)
			{
				sq[i]=7;
				c--;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld",sq[i]);
	}
	printf("\n");
}