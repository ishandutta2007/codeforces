#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];
bitset<100069> a;

int main()
{
	long long t,rr,i,ii,u;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		cin>>s;
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'0';
		}
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			fq[ii]=0;
			for(i=1+(n-1)*ii;i&&i<=n&&a[i]==ii;i+=u)
			{
				fq[ii]++;
			}
		}
		for(ii=0;ii<2;ii++)
		{
			for(i=0;i<fq[ii];i++)
			{
				printf("%lld",ii);
			}
			if(!ii&&n-fq[0]-fq[1])
			{
				printf("0");
			}
		}
		printf("\n");
	}
}