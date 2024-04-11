#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,nn[3];
pair<long long,long long> as[4][2][3][33369];

bool cmp(pair<long long,long long> x,pair<long long,long long> y)
{
	return mp(x.sc,x.fr)<mp(y.sc,y.fr);
}

int main()
{
	long long i,ii,jj,im,k,l,p,e,x,y,w,c,lh,rh,md,zz;
	pair<long long,long long> tmp;
	bool bad;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&w);
		w--;
		nn[w]++;
		as[0][0][w][nn[w]]={x,y};
	}
	for(im=0;im<4;im++)
	{
		for(ii=0;ii<3;ii++)
		{
			for(i=1;i<=nn[ii];i++)
			{
				if(im)
				{
					tmp=as[im-1][0][ii][i];
					as[im][0][ii][i]={-tmp.sc,tmp.fr};
				}
				as[im][1][ii][i]=as[im][0][ii][i];
			}
			sort(as[im][0][ii]+1,as[im][0][ii]+nn[ii]+1);
			sort(as[im][1][ii]+1,as[im][1][ii]+nn[ii]+1,cmp);
		}
	}
	for(lh=1,rh=n/3;lh<=rh;)
	{
		md=(lh+rh)/2;
		bad=0;
		for(im=0;im<4&&!bad;im++)
		{
			if(im<2)
			{
				for(ii=0;ii<3&&!bad;ii++)
				{
					k=as[im][0][ii][md].fr;
					for(jj=0;jj<2&&!bad;jj++)
					{
						e=(ii+1+jj)%3;
						p=upper_bound(as[im][0][e]+1,as[im][0][e]+nn[e]+1,mp(k,inf))-as[im][0][e];
						if(p+md-1>nn[e])
						{
							continue;
						}
						l=as[im][0][e][p+md-1].fr;
						e=(ii+1+!jj)%3;
						p=upper_bound(as[im][0][e]+1,as[im][0][e]+nn[e]+1,mp(l,inf))-as[im][0][e];
						bad|=p+md-1<=nn[e];
					}
				}
			}
			for(ii=0;ii<3&&!bad;ii++)
			{
				k=as[im][0][ii][md].fr;
				for(jj=0;jj<2&&!bad;jj++)
				{
					e=(ii+1+jj)%3;
					c=0;
					for(i=1;i<=nn[e];i++)
					{
						x=as[im][1][e][i].fr;
						y=as[im][1][e][i].sc;
						c+=x>k;
						if(c==md)
						{
							break;
						}
					}
					if(c<md)
					{
						continue;
					}
					l=y;
					e=(ii+1+!jj)%3;
					c=0;
					for(i=1;i<=nn[e];i++)
					{
						x=as[im][0][e][i].fr;
						y=as[im][0][e][i].sc;
						c+=x>k&&y>l;
					}
					bad|=c>=md;
				}
			}
		}
		if(bad)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	printf("%lld\n",zz*3);
}