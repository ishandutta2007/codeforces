#include <bits/stdc++.h>

using namespace std;

long long n,d,fq[26];

int main()
{
	long long i,j,r;
	string s;
	
	scanf("%lld",&d);
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		fq[s[i-1]-'a']++;
	}
	for(i=0;i<26;i++)
	{
		if(fq[i]%d)
		{
			printf("-1\n");
			return 0;
		}
	}
	for(i=0;i<d;i++)
	{
		for(j=0;j<26;j++)
		{
			for(r=0;r<fq[j]/d;r++)
			{
				printf("%c",(char)j+'a');
			}
		}
	}
	printf("\n");
}