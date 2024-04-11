#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,long long> a[100069];
map<pair<pair<long long,long long>,pair<long long,long long>>,long long> fq;

pair<long long,long long> sim(long long x,long long y)
{
	long long gd=__gcd(abs(x),abs(y));
	
	x/=gd;
	y/=gd;
	if(x<0||(!x&&y<0))
	{
		x*=-1;
		y*=-1;
	}
	return {x,y};
}

pair<pair<long long,long long>,pair<long long,long long>> val(long long p,long long p2)
{
	pair<long long,long long> sl,wg;
	
	sl=sim(a[p].fr-a[p2].fr,a[p].sc-a[p2].sc);
	if(sl.sc)
	{
		wg=sim(a[p].fr*sl.sc-a[p].sc*sl.fr,sl.sc);
	}
	else
	{
		wg={a[p].sc,0};
	}
	return {sl,wg};
}

int main()
{
	long long i,j,y,x,e,e2=0;
	pair<pair<long long,long long>,pair<long long,long long>> w,z,z2={{0,0},{0,0}};
	
	scanf("%lld",&n);
	if(n<=4)
	{
		printf("YES\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&y,&x);
		a[i]={y,x};
	}
	for(j=0,i=1;i<=4&&j!=-1;i++)
	{
		fq.clear();
		for(j=i+1;j<=n;j++)
		{
			w=val(i,j);
			fq[w]++;
			if(fq[w]==2)
			{
				j=-1;
				break;
			}
		}
	}
	if(j!=-1)
	{
		printf("NO\n");
		return 0;
	}
	z=w;
	e=i-1;
	for(i=1;i<=n;i++)
	{
		if(i!=e&&val(e,i)!=z)
		{
			if(!e2)
			{
				e2=i;
			}
			else if(z2.fr==mp(0ll,0ll))
			{
				z2=val(e2,i);
			}
			else if(val(e2,i)!=z2)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
}