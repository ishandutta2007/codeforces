#include <bits/stdc++.h>

using namespace std;

long long n,m,sq[100069],zs;

int main()
{
	long long t,rr,i,j;
	bool bad;
	char ch;
	string s,s2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s>>s2;
		n=s.length();
		m=s2.length();
		zs=0;
		for(j=m-1,i=n-1;i>=0||j>=0;i--,j--)
		{
			ch='0';
			if(i>=0)
			{
				ch=s[i];
			}
			if(j<0)
			{
				break;
			}
			if(s2[j]>=ch)
			{
				zs++;
				sq[zs]=s2[j]-ch;
			}
			else
			{
				zs++;
				sq[zs]=s2[j]-ch+10;
				j--;
				if(j<0||s2[j]!='1')
				{
					break;
				}
			}
		}
		if(i<0)
		{
			bad=0;
			for(i=zs;i;i--)
			{
				if(sq[i])
				{
					bad=1;
				}
				if(bad)
				{
					printf("%lld",sq[i]);
				}
			}
			printf("\n");
		}
		else
		{
			printf("-1\n");
		}
	}
}