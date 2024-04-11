#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,zs=0;
pair<long long,long long> a[1069],sq[1000069];
map<pair<long long,long long>,long long> fq;
map<pair<long long,long long>,map<pair<long long,long long>,bool>> vtd;

void sim(long long &x,long long &y)
{
	long long gd;
	
	gd=__gcd(x,y);
	x/=gd;
	y/=gd;
	if(y<0)
	{
		x*=-1;
		y*=-1;
	}
	if(x<0)
	{
		x*=-1;
		y*=-1;
	}
}

int main()
{
	long long i,j,sm=0,z=0;
	pair<long long,long long> m,c;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].fr,&a[i].sc);
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			m.fr=a[i].fr-a[j].fr;
			m.sc=a[i].sc-a[j].sc;
			sim(m.fr,m.sc);
			if(m.sc)
			{
				c.fr=a[i].fr*m.sc-a[i].sc*m.fr;
				c.sc=m.sc;
				sim(c.fr,c.sc);
			}
			else
			{
				c.fr=a[i].sc;
				c.sc=0;
			}
			if(!vtd[m][c])
			{
				if(!fq[m])
				{
					zs++;
					sq[zs]=m;
				}
				fq[m]++;
				vtd[m][c]=1;
			}
		}
	}
	for(i=1;i<=zs;i++)
	{
		z+=fq[sq[i]]*sm;
		sm+=fq[sq[i]];
	}
	printf("%lld\n",z);
}