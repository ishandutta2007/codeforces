#include <bits/stdc++.h>

using namespace std;

long long n,d,ma=20;
bitset<1ll<<20> a,vtd;

int main()
{
	long long t,rr,i,j,k,sm,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<=n-d+1;i++)
		{
			vtd[i]=0;
		}
		sm=0;
		for(j=1,i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=!(ch-'0');
			sm=(sm<<1|a[i])%(1ll<<min(d,ma));
			for(j=max(j,i-d+1);j<=i&&!a[j];j++);
			if(i>=d&&i-j<ma)
			{
				vtd[sm]=1;
			}
		}
		for(z=0;vtd[z];z++);
		if(d>=ma||z<1ll<<d)
		{
			printf("YES\n");
			for(i=d-1;i+1;i--)
			{
				if(i<ma)
				{
					k=z>>i&1;
				}
				else
				{
					k=0;
				}
				printf("%lld",k);
			}
			printf("\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}