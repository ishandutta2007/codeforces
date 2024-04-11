#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dsu[100069];
pair<long long,pair<long long,long long>> a[1000069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long i,j,kp,lp,k,l,w;
	
	scanf("%lld%lld%lld%lld%lld",&n,&m,&kp,&lp,&w);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=0;i<m-1;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		a[i]={w,{k,l}};
	}
	sort(a,a+m-1);
	for(i=0;i<m-1;i++)
	{
		k=a[i].sc.fr;
		l=a[i].sc.sc;
		w=a[i].fr;
		dsu[fd(l)]=fd(k);
		if(fd(kp)==fd(lp))
		{
			printf("%lld\n",w);
			return 0;
		}
	}
	printf("1000000000\n");
}