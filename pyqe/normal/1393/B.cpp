#include <bits/stdc++.h>

using namespace std;

long long n,fq[100069],fqq[100069];

void ins(long long x)
{
	fq[x]++;
	fqq[fq[x]]++;
}

void ers(long long x)
{
	fqq[fq[x]]--;
	fq[x]--;
}

int main()
{
	long long t,rr,i,k;
	char ch;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		ins(k);
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf(" %c%lld",&ch,&k);
		if(ch=='+')
		{
			ins(k);
		}
		else
		{
			ers(k);
		}
		if((fqq[4]&&fqq[2]>=3)||fqq[4]>=2||(fqq[6]&&fqq[2]>=2)||fqq[8])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}