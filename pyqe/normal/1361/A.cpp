#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,mx[500069];
vector<long long> al[500069];
pair<long long,long long> a[500069];

int main()
{
	long long i,j,k,l,w,sz;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]={k,i};
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		w=a[i].fr;
		k=a[i].sc;
		if(mx[k]+1!=w)
		{
			printf("-1\n");
			return 0;
		}
		sz=al[k].size();
		for(j=0;j<sz;j++)
		{
			l=al[k][j];
			mx[l]+=mx[l]==w-1;
		}
	}
	for(i=1;i<=n;i++)
	{
		k=a[i].sc;
		printf("%lld%c",k," \n"[i==n]);
	}
}