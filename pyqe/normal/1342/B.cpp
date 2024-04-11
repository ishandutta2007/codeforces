#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];

int main()
{
	long long t,rr,i,ii;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(ii=0;ii<2;ii++)
		{
			fq[ii]=0;
		}
		for(i=0;i<n;i++)
		{
			fq[s[i]-'0']++;
		}
		if(!fq[0]||!fq[1])
		{
			for(i=0;i<n;i++)
			{
				printf("%lld",(long long)!!fq[1]);
			}
			printf("\n");
		}
		else
		{
			for(i=0;i<n;i++)
			{
				printf("01");
			}
			printf("\n");
		}
	}
}