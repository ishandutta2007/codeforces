#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[1000069],nn=1;
pair<long long,long long> cx[1000069];

int main()
{
	long long i,j,sm=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		sm+=a[i];
		for(;nn>1&&(sm-cx[nn].fr)*(i-cx[nn-1].sc)<=(sm-cx[nn-1].fr)*(i-cx[nn].sc);nn--);
		nn++;
		cx[nn]={sm,i};
	}
	for(j=1,i=1;i<=n;i++)
	{
		for(;cx[j].sc<i;j++);
		printf("%.9lf\n",(double)(cx[j].fr-cx[j-1].fr)/(cx[j].sc-cx[j-1].sc));
	}
}