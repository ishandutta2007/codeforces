#include <bits/stdc++.h>

using namespace std;

long long n,a[10069],pst[10069],sq[10069];

int main()
{
	long long i,j,r,k;
	char ch;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	for(i=0;i<3;i++)
	{
		printf("? ");
		for(j=1;j<=n;j++)
		{
			for(r=0,k=j-1;r<i;k/=26,r++);
			printf("%c",(char)(k%26+'a'));
		}
		printf("\n");
		fflush(stdout);
		for(j=1;j<=n;j++)
		{
			scanf(" %c",&ch);
			k=ch-'a';
			for(r=0;r<i;r++)
			{
				k*=26;
			}
			pst[j]+=k;
		}
	}
	for(i=1;i<=n;i++)
	{
		sq[pst[i]+1]=a[i];
	}
	printf("! ");
	for(i=1;i<=n;i++)
	{
		printf("%c",(char)(sq[i]+'a'));
	}
	printf("\n");
	fflush(stdout);
}