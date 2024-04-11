#include <bits/stdc++.h>

using namespace std;

long long ma=100,nn=0,pri[69];
bitset<100069> vtd;

int main()
{
	long long i,j;
	string s;
	
	for(i=2;i<=ma;i++)
	{
		if(!vtd[i])
		{
			nn++;
			pri[nn]=i;
			for(j=i*i;j<=ma;j+=i)
			{
				vtd[j]=1;
			}
		}
	}
	for(i=1;i<=4;i++)
	{
		printf("%lld\n",pri[i]);
		fflush(stdout);
		cin>>s;
		if(s[0]=='y')
		{
			for(j=i;pri[i]*pri[j]<=ma;j++)
			{
				printf("%lld\n",pri[i]*pri[j]);
				fflush(stdout);
				cin>>s;
				if(s[0]=='y')
				{
					printf("composite\n");
					fflush(stdout);
					return 0;
				}
			}
			printf("prime\n");
			fflush(stdout);
			return 0;
		}
	}
	printf("prime\n");
	fflush(stdout);
}