#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,d2,ls[200069],dv=1e9+7,inf=2e9;
pair<long long,long long> as[200069];

int main()
{
	long long i,k,l,w,c=0,z=0;
	
	scanf("%lld%lld%lld",&n,&d,&d2);
	d-=d2;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		as[i*2-1]={k,-1};
		as[i*2]={l,1};
		ls[i]=-inf;
	}
	sort(as+1,as+n*2+1);
	for(i=1;i<=n*2;i++)
	{
		k=as[i].fr;
		w=-as[i].sc;
		if(w==-1)
		{
			z=(z+d2*(k-ls[c]+1))%dv;
			ls[c]=k;
		}
		c+=w;
		if(w==1)
		{
			z=(z+min(d,d2*(k-ls[c]-1)))%dv;
			ls[c]=k;
		}
	}
	printf("%lld\n",z);
}