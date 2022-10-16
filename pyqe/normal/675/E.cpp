#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,pr[100069],dp[100069],ss=0;
pair<long long,long long> sk[100069];

int main()
{
	long long i,k,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld",pr+i);
	}
	pr[n]=n;
	for(i=n;i;i--)
	{
		if(i<n)
		{
			k=-(*lower_bound(sk+1,sk+ss+1,mp(-pr[i],0ll))).fr;
			dp[i]=dp[k]+n-i-pr[i]+k;
		}
		for(;ss&&sk[ss].sc<=pr[i];ss--);
		ss++;
		sk[ss]={-i,pr[i]};
		z+=dp[i];
	}
	printf("%lld\n",z);
}