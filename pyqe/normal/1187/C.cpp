#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,z[100069],mx;
pair<long long,long long> a[100069],qq[100069];

int main()
{
	long long i,j,ky,k,l,c1=0,c2=0,d=100000;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		if(ky)
		{
			a[c1]={k,l};
			c1++;
		}
		else
		{
			qq[c2]={k,l};
			c2++;
		}
	}
	sort(a,a+c1);
	mx=0;
	for(j=0,i=1;i<=n;i++)
	{
		for(;j<c1&&a[j].fr==i;j++)
		{
			mx=max(mx,a[j].sc);
		}
		z[i]=d;
		if(i>=mx)
		{
			d--;
		}
	}
	for(i=0;i<c2;i++)
	{
		if(z[qq[i].fr]==z[qq[i].sc])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",z[i]," \n"[i==n]);
	}
}