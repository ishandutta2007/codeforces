#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn[2],m[2],fwp;
pair<long long,pair<long long,long long>> aa[2][100069],a[2][100069];
pair<pair<long long,long long>,long long> q[100069];
map<long long,long long> fw;
priority_queue<pair<long long,long long>> pq;

void ud(long long lh,long long w)
{
	for(fwp=lh;fwp<=2000000001;fwp+=fwp&-fwp)
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
	long long i,x1,y1,x2,y2,cr,mx,k,l,p,ii,ls,z=0,j;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		x1+=1e9+1;
		y1+=1e9+1;
		x2+=1e9+1;
		y2+=1e9+1;
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
			aa[0][nn[0]]={y1,{x1,x2}};
			nn[0]++;
		}
		else if(x1==x2)
		{
			aa[1][nn[1]]={x1,{y1,y2}};
			nn[1]++;
		}
	}
	for(ii=0;ii<2;ii++)
	{
		sort(aa[ii],aa[ii]+nn[ii]);
		cr=-1;
		ls=-1;
		for(i=0;i<=nn[ii];i++)
		{
			p=aa[ii][i].fr;
			k=aa[ii][i].sc.fr;
			l=aa[ii][i].sc.sc;
			if(i==nn[ii]||p>cr||k>mx)
			{
				if(ls>-1)
				{
					a[ii][m[ii]]={cr,{ls,mx}};
					m[ii]++;
					z+=(mx-ls+1);
				}
				ls=k;
			}
			if(p>cr)
			{
				mx=-1;
			}
			cr=p;
			mx=max(mx,l);
		}
	}
	for(i=0;i<m[1];i++)
	{
		p=a[1][i].fr;
		k=a[1][i].sc.fr;
		l=a[1][i].sc.sc;
		q[i*2]={{k,p},1};
		q[i*2+1]={{l+1,p},-1};
	}
	sort(q,q+m[1]*2);
	j=0;
	for(i=0;i<m[0];i++)
	{
		p=a[0][i].fr;
		k=a[0][i].sc.fr;
		l=a[0][i].sc.sc;
		for(;j<m[1]*2&&q[j].fr.fr<=p;j++)
		{
			ud(q[j].fr.sc,q[j].sc);
		}
		z-=sm(k,l);
	}
	printf("%lld\n",z);
}