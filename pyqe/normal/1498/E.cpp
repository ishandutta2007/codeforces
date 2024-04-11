#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,a[569];
pair<long long,long long> as[125069];

bool cmp(pair<long long,long long> x,pair<long long,long long> y)
{
	return a[x.sc]-a[x.fr]>a[y.sc]-a[y.fr];
}

int main()
{
	long long i,j,k,l;
	string s;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			k=i;
			l=j;
			if(a[k]>a[l])
			{
				swap(k,l);
			}
			nn++;
			as[nn]={k,l};
		}
	}
	sort(as+1,as+nn+1,cmp);
	for(i=1;i<=nn;i++)
	{
		k=as[i].fr;
		l=as[i].sc;
		printf("? %lld %lld\n",l,k);
		fflush(stdout);
		cin>>s;
		if(s[0]=='Y')
		{
			printf("! %lld %lld\n",k,l);
			fflush(stdout);
			return 0;
		}
	}
	printf("! 0 0\n");
	fflush(stdout);
}