#include <bits/stdc++.h>

using namespace std;

long long ma=1000;
bitset<1069> fq;

int main()
{
	long long i,k,l;
	bool ft=1;
	char ch=',';
	
	for(;ch==',';)
	{
		scanf("%lld%c",&k,&ch);
		fq[k]=1;
	}
	for(i=1;i<=ma;i++)
	{
		if(fq[i]&&!fq[i-1])
		{
			l=i;
		}
		if(fq[i]&&!fq[i+1])
		{
			if(!ft)
			{
				printf(",");
			}
			printf("%lld",l);
			if(l<i)
			{
				printf("-%lld",i);
			}
			ft=0;
		}
	}
	printf("\n");
}