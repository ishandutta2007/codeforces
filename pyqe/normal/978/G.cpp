#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,sq[1069];
pair<long long,long long> a[1069],as[1069];

int main()
{
	long long i,j,k,l,w,pz;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		a[i]={k,w};
		as[i]={l,i};
	}
	sort(as+1,as+m+1);
	for(i=1;i<=m;i++)
	{
		l=as[i].fr;
		pz=as[i].sc;
		k=a[pz].fr;
		w=a[pz].sc;
		for(j=k;j<l;j++)
		{
			if(!sq[j]&&w)
			{
				sq[j]=pz;
				w--;
			}
		}
		if(w)
		{
			printf("-1\n");
			return 0;
		}
		sq[l]=m+1;
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}