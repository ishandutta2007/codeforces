#include <bits/stdc++.h>

using namespace std;

long long n,d,as[1000069],pn[1000069][2];

int main()
{
	long long i,j,k,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<=d+1;i++)
	{
		pn[i][0]=-1;
		pn[i][1]=-1;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(pn[k][0]==-1)
		{
			pn[k][0]=i;
		}
		pn[k][1]=i;
		as[i]=k;
	}
	sort(as+1,as+n+1);
	as[n+1]=d+1;
	pn[0][0]=0;
	pn[0][1]=0;
	pn[d+1][0]=n+1;
	pn[d+1][1]=n+1;
	for(j=d+1;j>0&&(pn[j-1][1]==-1||pn[as[upper_bound(as,as+n+2,j-1)-as-1]][1]<=pn[as[lower_bound(as,as+n+2,j)-as]][0]);j--);
	for(i=0;i<d&&(pn[i][0]==-1||pn[as[upper_bound(as,as+n+2,i-1)-as-1]][1]<=pn[as[lower_bound(as,as+n+2,i)-as]][0]);i++)
	{
		for(;j<=d&&(j<=i+1||pn[as[lower_bound(as,as+n+2,j)-as]][0]<=pn[as[upper_bound(as,as+n+2,i)-as-1]][1]);)
		{
			j++;
		}
		z+=d+2-j;
	}
	printf("%lld\n",z);
}