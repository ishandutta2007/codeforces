#include <bits/stdc++.h>

using namespace std;

long long n,d,fq[2][26];

int main()
{
	long long t,rr,i,ii,k;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(ii=0;ii<2;ii++)
		{
			for(i=0;i<26;i++)
			{
				fq[ii][i]=0;
			}
			for(i=0;i<n;i++)
			{
				scanf(" %c",&ch);
				k=ch-'a';
				fq[ii][k]++;
			}
		}
		for(i=25;i+1;i--)
		{
			if(i<25)
			{
				for(ii=0;ii<2;ii++)
				{
					fq[ii][i]+=fq[ii][i+1];
				}
			}
			if(fq[0][i]%d!=fq[1][i]%d||fq[0][i]>fq[1][i])
			{
				i=-2;
				break;
			}
		}
		if(i!=-2)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}