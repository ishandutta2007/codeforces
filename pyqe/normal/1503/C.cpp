#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ttl=0;
pair<long long,long long> as[200069];

int main()
{
	long long i,k,l,w,c=0,sm=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		ttl+=l;
		as[i*2-1]={k,1};
		as[i*2]={k+l,-1};
	}
	sort(as+1,as+n*2+1);
	l=as[1].fr;
	for(i=1;i<=n*2;i++)
	{
		k=as[i].fr;
		w=as[i].sc;
		sm+=(k-l)*(c+2*!c);
		c+=w;
		l=k;
	}
	printf("%lld\n",(ttl+sm)/2);
}