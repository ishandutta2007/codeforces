#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nh,nv,fw[10069],fwp;
pair<long long,pair<long long,long long>> ah[5069];
pair<pair<long long,long long>,long long> av[5069];

long long tri(long long x)
{
	return x*(x-1)/2;
}

void ud(long long x,long long w)
{
	for(fwp=x;fwp<=10001;fwp+=fwp&-fwp)
	{
		fw[fwp]+=w;
	}
}

long long sm(long long lh,long long rh)
{
	long long z=0;
	
	for(fwp=rh;fwp>0;fwp-=fwp&-fwp)
	{
		z+=fw[fwp];
	}
	for(fwp=lh-1;fwp>0;fwp-=fwp&-fwp)
	{
		z-=fw[fwp];
	}
	return z;
}

int main()
{
	long long i,j,jj,x1,y1,x2,y2,z=0,k,l,p,kk,ll,pp;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		x1+=5001;
		y1+=5001;
		x2+=5001;
		y2+=5001;
		if(x1>x2)
		{
			swap(x1,x2);
		}
		if(y1>y2)
		{
			swap(y1,y2);
		}
		if(y1==y2)
		{
			ah[nh]={y1,{x1,x2}};
			nh++;
		}
		else if(x1==x2)
		{
			av[nv]={{y1,y2},x1};
			nv++;
		}
	}
	sort(ah,ah+nh);
	sort(av,av+nv);
	for(i=0;i<nh;i++)
	{
		x1=ah[i].sc.fr;
		x2=ah[i].sc.sc;
		y1=ah[i].fr;
		for(j=0;j<=10001;j++)
		{
			fw[j]=0;
		}
		jj=0;
		for(j=0;j<i;j++)
		{
			k=ah[j].sc.fr;
			l=ah[j].sc.sc;
			p=ah[j].fr;
			for(;jj<nv&&av[jj].fr.fr<=p;jj++)
			{
				kk=av[jj].fr.fr;
				ll=av[jj].fr.sc;
				pp=av[jj].sc;
				if(kk<=y1&&ll>=y1&&pp>=x1&&pp<=x2)
				{
					ud(pp,1);
				}
			}
			z+=tri(sm(k,l));
		}
	}
	printf("%lld\n",z);
}