#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,st,d,inf=1e18;

int main()
{
	long long i,k,l,p;
	pair<long long,long long> mxe;
	
	srand(time(NULL));
	scanf("%lld%lld%lld",&n,&st,&d);
	mxe={-inf,st};
	for(i=0;i<1000;i++)
	{
		p=((rand()<<15)|rand())%n+1;
		printf("? %lld\n",p);
		fflush(stdout);
		scanf("%lld%lld",&k,&l);
		if(k<=d)
		{
			mxe=max(mxe,{k,p});
		}
	}
	p=mxe.sc;
	for(i=0;i<999&&p!=-1;i++)
	{
		printf("? %lld\n",p);
		fflush(stdout);
		scanf("%lld%lld",&k,&l);
		if(k>=d)
		{
			printf("! %lld\n",k);
			fflush(stdout);
			return 0;
		}
		p=l;
	}
	printf("! -1\n");
	fflush(stdout);
}