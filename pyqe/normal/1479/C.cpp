#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n=22,m=0,lb,rb;
pair<pair<long long,long long>,long long> sq[100069];

void ae(long long x,long long y,long long w)
{
	m++;
	sq[m]={{x,y},w};
}

int main()
{
	long long i,j,k,l,w;
	
	scanf("%lld%lld",&lb,&rb);
	for(i=2;i<n;i++)
	{
		for(j=1;j<i;j++)
		{
			ae(j,i,1ll<<max(j-2,0ll));
		}
	}
	ae(1,n,lb);
	lb++;
	for(i=19;i+1;i--)
	{
		if(1ll<<i<=rb-lb+1)
		{
			ae(i+2,n,lb-1);
			lb+=1ll<<i;
		}
	}
	printf("YES\n%lld %lld\n",n,m);
	for(i=1;i<=m;i++)
	{
		k=sq[i].fr.fr;
		l=sq[i].fr.sc;
		w=sq[i].sc;
		printf("%lld %lld %lld\n",k,l,w);
	}
}