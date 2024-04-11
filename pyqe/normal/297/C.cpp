#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sq[2][100069];
pair<long long,long long> a[100069];

int main()
{
	long long i,ii,k,l,e;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]={k,i};
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		k=a[i].fr;
		l=a[i].sc;
		sq[i%2][l]=max((i-n/3)/2,0ll);
		sq[(i+1)%2][l]=k-sq[i%2][l];
	}
	printf("YES\n");
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[ii][i]," \n"[i==n]);
		}
	}
}