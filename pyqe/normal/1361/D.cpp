#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,nn=0;
pair<pair<long long,long long>,long long> as[500069];
vector<long long> vl[500069];
double sq[500069];

int main()
{
	long long i,j,k,y,x,gd,sz,ls,sm;
	double w,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&y,&x);
		gd=__gcd(abs(y),abs(x));
		if(gd)
		{
			y/=gd;
			x/=gd;
		}
		as[i]={{y,x},gd};
	}
	sort(as+1,as+n+1);
	for(i=1;i<=n;i++)
	{
		if(i==1||as[i].fr>as[i-1].fr)
		{
			ls=i;
		}
		vl[ls].push_back(as[i].sc);
	}
	for(i=1;i<=n;i++)
	{
		sort(vl[i].begin(),vl[i].end());
		y=as[i].fr.fr;
		x=as[i].fr.sc;
		w=sqrt(y*y+x*x);
		sz=vl[i].size();
		for(j=0;j<sz&&j*2<d-1;j++)
		{
			k=vl[i][sz-1-j];
			nn++;
			sq[nn]=w*(k*(d-1-j*2));
		}
		ls=sz-1-j;
		sm=0;
		for(j=0;j<=ls;j++)
		{
			k=vl[i][j];
			nn++;
			sq[nn]=w*(-sm*2-k*((d-1)%2));
			sm+=k;
		}
	}
	sort(sq+1,sq+n+1,greater<double>());
	for(i=1;i<=d;i++)
	{
		z+=sq[i];
	}
	printf("%.8lf\n",z);
}