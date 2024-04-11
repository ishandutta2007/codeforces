#include <bits/stdc++.h>

using namespace std;

const long long mm=26;
long long n,d;
bitset<mm> spc;

int main()
{
	long long t,rr,i,k;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		spc.reset();
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			k=ch-'a';
			for(;d&&k&&!spc[k];k--)
			{
				d--;
				spc[k]=1;
			}
			for(;spc[k];k--);
			printf("%c",(char)(k+'a'));
		}
		printf("\n");
	}
}