#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,j,mk;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		if(s[i-1]=='.')
		{
			a[i]=0;
		}
		else
		{
			a[i]=s[i-1]-'A'+1;
		}
	}
	for(i=1;i<=n-2;i++)
	{
		mk=0;
		for(j=i;j<=i+2;j++)
		{
			mk|=1ll<<a[j];
		}
		if(mk==14)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}