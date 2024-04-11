#include <bits/stdc++.h>

using namespace std;

long long n,a[5069];
bool bad;

int main()
{
	long long i,j;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		a[i]=s[i]-'a';
	}
	for(i=1;i<n/2;i++)
	{
		if(a[i]!=a[i-1])
		{
			i=-1;
			break;
		}
	}
	if(i!=-1)
	{
		printf("Impossible\n");
		return 0;
	}
	for(i=1;i<n;i++)
	{
		bad=0;
		for(j=0;j<n;j++)
		{
			if(a[(i+j)%n]!=a[(i+n-1-j)%n])
			{
				j=-1;
				break;
			}
			bad|=a[(i+j)%n]!=a[j];
		}
		if(j!=-1&&bad)
		{
			printf("1\n");
			return 0;
		}
	}
	printf("2\n");
}