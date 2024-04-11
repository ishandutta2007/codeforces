#include <bits/stdc++.h>

using namespace std;

long long n,sq[2][50069];

int main()
{
	long long t,rr,i,ii,k;
	string s;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		cin>>s;
		bad=0;
		for(i=1;i<=n;i++)
		{
			k=s[i-1]-'0';
			if(!bad)
			{
				sq[0][i]=k-k/2;
				sq[1][i]=k/2;
				bad|=k==1;
			}
			else
			{
				sq[0][i]=0;
				sq[1][i]=k;
			}
		}
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				printf("%lld",sq[ii][i]);
			}
			printf("\n");
		}
	}
}