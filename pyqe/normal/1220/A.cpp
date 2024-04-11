#include <bits/stdc++.h>

using namespace std;

long long fq[2];

int main()
{
	long long i,ln,ii;
	string s;
	
	scanf("%lld",&ln);
	cin>>s;
	for(i=0;i<ln;i++)
	{
		if(s[i]=='z')
		{
			fq[0]++;
		}
		else if(s[i]=='n')
		{
			fq[1]++;
		}
	}
	for(ii=1;ii>=0;ii--)
	{
		for(i=0;i<fq[ii];i++)
		{
			printf("%lld%c",ii," \n"[!ii&&i==fq[ii]-1]);
		}
	}
}