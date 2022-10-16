#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,sq[1000069],pwk,dv=998244353;
pair<long long,pair<long long,long long>> a[1000069];

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

int main()
{
	long long i,j,ii,k,ys,xs,y,x,ttl=0,sm[2]={0,0},sm2[2]={0,0};
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&k);
			a[(i-1)*m+j]={k,{i,j}};
		}
	}
	sort(a+1,a+n*m+1);
	scanf("%lld%lld",&ys,&xs);
	for(j=0,i=1;i<=n*m;i++)
	{
		k=a[i].fr;
		y=a[i].sc.fr;
		x=a[i].sc.sc;
		sq[i]=ttl;
		for(ii=0;ii<2;ii++)
		{
			sq[i]=(sq[i]+y*y*j+sm2[ii]+dv-y*sm[ii]*2%dv)%dv;
			swap(y,x);
		}
		sq[i]=sq[i]*pw(j,dv-2)%dv;
		if(y==ys&&x==xs)
		{
			break;
		}
		if(k<a[i+1].fr)
		{
			for(;j<i;)
			{
				j++;
				ttl=(ttl+sq[j])%dv;
				y=a[j].sc.fr;
				x=a[j].sc.sc;
				for(ii=0;ii<2;ii++)
				{
					sm[ii]=(sm[ii]+y)%dv;
					sm2[ii]=(sm2[ii]+y*y)%dv;
					swap(y,x);
				}
			}
		}
	}
	printf("%lld\n",sq[i]);
}