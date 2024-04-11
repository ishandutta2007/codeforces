#include <bits/stdc++.h>

using namespace std;

long long n,fq[2],zs=0;
bitset<100069> a;
vector<long long> sq;

int main()
{
	long long i,ii;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]=='B';
		fq[a[i]]++;
	}
	for(ii=0;ii<2;ii++)
	{
		if(fq[ii]%2==0)
		{
			for(i=1;i<=n;i++)
			{
				if(a[i]==ii)
				{
					sq.push_back(i);
					zs++;
					a[i]=!a[i];
					a[i+1]=!a[i+1];
				}
			}
			printf("%lld\n",zs);
			for(i=0;i<zs;i++)
			{
				printf("%lld%c",sq[i]," \n"[i==zs-1]);
			}
			return 0;
		}
	}
	printf("-1\n");
}