#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],sq[100069],zs=0;
bitset<100069> spc;

int main()
{
	long long i;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
		zs++;
		sq[zs]=a[i];
		if(i>=3&&a[i]==14&&a[i-1]==6&&a[i-2]==14)
		{
			zs-=2;
			if(!spc[i-2])
			{
				sq[zs]=-1;
			}
			spc[i]=1;
		}
	}
	for(i=1;i<=zs;i++)
	{
		if(sq[i]==-1)
		{
			printf("***");
		}
		else
		{
			printf("%c",(char)sq[i]+'a');
		}
	}
	printf("\n");
}