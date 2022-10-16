#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,nn,nm,tn,cr,a[369][369];
pair<pair<long long,long long>,long long> as[669],tmp[669];
pair<long long,long long> ca[369];
double sq[369];

bool cmp(pair<long long,long long> x,pair<long long,long long> y)
{
	return x.fr*y.sc<y.fr*x.sc;
}

pair<long long,long long> fins(long long p,long long x,long long y)
{
	return {a[cr-1][p]*y+(a[cr][p]-a[cr-1][p])*x,y};
}

int main()
{
	long long i,j,r,r2,k,l,p,k2,l2,sz;
	pair<long long,long long> x,x2,y,y2;
	pair<double,double> da[4];
	double sm;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=d;j++)
		{
			scanf("%lld",&a[j][i]);
		}
	}
	for(i=1;i<=d;i++)
	{
		cr=i;
		nn=1;
		as[0]={{0,1},0};
		as[1]={{1,1},0};
		for(j=1;j<=n;j++)
		{
			nm=0;
			for(r=1;r<=nn;r++)
			{
				p=as[r].sc;
				if((a[i-1][j]<a[i-1][p]&&a[i][j]>a[i][p])||(a[i-1][j]>a[i-1][p]&&a[i][j]<a[i][p]))
				{
					k=abs(a[i-1][j]-a[i-1][p]);
					l=abs(a[i][j]-a[i][p]);
					nm++;
					ca[nm]={k,k+l};
				}
			}
			sort(ca+1,ca+nm+1,cmp);
			tn=0;
			for(r2=0,r=1;r<=nn;r++)
			{
				p=as[r].sc;
				for(;r2<nm&&!cmp(as[r].fr,ca[r2+1]);)
				{
					r2++;
					tn++;
					tmp[tn]={ca[r2],p};
				}
				tn++;
				tmp[tn]=as[r];
			}
			for(r=1;r<=tn;r++)
			{
				as[r]=tmp[r];
			}
			nn=tn;
			for(r=1;r<=nn;r++)
			{
				k=as[r].fr.fr;
				l=as[r].fr.sc;
				p=as[r].sc;
				k2=as[r-1].fr.fr;
				l2=as[r-1].fr.sc;
				x=fins(j,k,l);
				x2=fins(j,k2,l2);
				y=fins(p,k,l);
				y2=fins(p,k2,l2);
				if(!cmp(x,y)&&!cmp(x2,y2))
				{
					da[0]={(double)k/l,(double)x.fr/x.sc};
					da[1]={(double)k/l,(double)y.fr/y.sc};
					da[2]={(double)k2/l2,(double)y2.fr/y2.sc};
					da[3]={(double)k2/l2,(double)x2.fr/x2.sc};
					sm=0;
					for(r2=0;r2<4;r2++)
					{
						sm+=da[r2].fr*da[(r2+1)%4].sc-da[r2].sc*da[(r2+1)%4].fr;
					}
					sq[j]+=abs(sm);
					as[r].sc=j;
				}
			}
			sz=nn;
			nn=0;
			for(r=1;r<=sz;r++)
			{
				p=as[r].sc;
				nn+=!nn||as[nn].sc!=p;
				as[nn]=as[r];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%.20lf\n",sq[i]/2);
	}
}