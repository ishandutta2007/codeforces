#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[1000069],faf[1000069],fq[1000069];

int main()
{
	long long i,j;
	string s;
	
	cin>>s;
	n=s.length();
	faf[0]=-1;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
		for(j=i-1;j&&a[faf[j]+1]!=a[i];j=faf[j]);
		faf[i]=faf[j]+1;
		fq[i]=1;
	}
	for(i=n;i;i--)
	{
		fq[faf[i]]+=fq[i];
	}
	for(i=n;i;i=faf[i])
	{
		if(fq[i]>=3)
		{
			for(j=1;j<=i;j++)
			{
				printf("%c",(char)a[j]+'a');
			}
			printf("\n");
			return 0;
		}
	}
	printf("Just a legend\n");
}