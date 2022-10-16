#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,fq[200069];
pair<long long,long long> a[400069];

int main()
{
	long long i,k,l,w,c=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		a[i*2-1]={k,1};
		a[i*2]={l+1,-1};
	}
	sort(a+1,a+n*2+1);
	l=0;
	for(i=1;i<=n*2;i++)
	{
		k=a[i].fr;
		w=a[i].sc;
		fq[c]+=k-l;
		c+=w;
		l=k;
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",fq[i]," \n"[i==n]);
	}
}