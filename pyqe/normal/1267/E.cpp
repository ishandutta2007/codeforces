#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,sm[169],mn=1e18;
pair<long long,long long> a[169][169];
vector<long long> sq,v;

int main()
{
	long long i,j,k;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<n;j++)
		{
			scanf("%lld",&a[j][i].fr);
			a[j][i].sc=i;
		}
		scanf("%lld",&k);
		for(j=1;j<n;j++)
		{
			a[j][i].fr-=k;
			sm[j]+=a[j][i].fr;
		}
	}
	for(i=1;i<n;i++)
	{
		sort(a[i]+1,a[i]+m+1);
		k=0;
		v.clear();
		for(j=1;sm[i]-k<0;j++)
		{
			k+=a[i][j].fr;
			v.push_back(a[i][j].sc);
		}
		if(j-1<mn)
		{
			mn=j-1;
			sq=v;
		}
	}
	printf("%lld\n",mn);
	for(i=0;i<mn;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==mn-1]);
	}
}