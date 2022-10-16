#include <bits/stdc++.h>

using namespace std;

long long n,m,d,nn=0,a[20069],pst[20069],sq[20069];

int main()
{
	long long i,j,k,l,w,c=0;
	bool bad=0;
	char ch;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(j=0,i=1;i<=n;i++)
	{
		scanf("%lld %c%lld %c%lld",&k,&ch,&l,&ch,&w);
		a[i]=((k*60)+l)*60+w;
		for(;a[j+1]+d-1<a[i];)
		{
			j++;
			c-=pst[sq[j]]==j;
		}
		nn+=c<m;
		sq[i]=nn;
		pst[nn]=i;
		c+=c<m;
		bad|=c==m;
	}
	if(!bad)
	{
		printf("No solution\n");
		return 0;
	}
	printf("%lld\n",nn);
	for(i=1;i<=n;i++)
	{
		printf("%lld\n",sq[i]);
	}
}