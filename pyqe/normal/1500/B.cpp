#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n[2],d,nn,nm=0,pst[2][1000069],a[1000069];

pair<long long,long long> xeu(long long x,long long y)
{
	if(!y)
	{
		return {1,0};
	}
	pair<long long,long long> tmp=xeu(y,x%y);
	return {tmp.sc,tmp.fr-x/y*tmp.sc};
}

int main()
{
	long long i,ii,k,l,gd,lm,z;
	pair<long long,long long> tmp;
	
	scanf("%lld%lld%lld",n,n+1,&d);
	nn=max(n[0],n[1])*2;
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=nn;i++)
		{
			pst[ii][i]=-1;
		}
		for(i=0;i<n[ii];i++)
		{
			scanf("%lld",&k);
			pst[ii][k]=i;
		}
	}
	gd=__gcd(n[0],n[1]);
	tmp=xeu(n[0],n[1]);
	lm=n[0]/gd*n[1];
	for(i=1;i<=nn;i++)
	{
		k=pst[0][i];
		l=pst[1][i];
		if(k+1&&l+1&&(k-l)%gd==0)
		{
			k=(((l-k)/gd*tmp.fr*n[0]+k)%lm+lm)%lm;
			nm++;
			a[nm]=k;
		}
	}
	sort(a+1,a+nm+1);
	z=(d-1)/(lm-nm)*lm;
	d=(d-1)%(lm-nm)+1;
	a[0]=-1;
	a[nm+1]=lm;
	for(i=1;i<=nm+1;i++)
	{
		if(d>a[i]-a[i-1]-1)
		{
			d-=a[i]-a[i-1]-1;
			z+=a[i]-a[i-1];
		}
		else
		{
			z+=d;
			break;
		}
	}
	printf("%lld\n",z);
}