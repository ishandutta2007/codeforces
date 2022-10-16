#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m=0,nn[2],vx[2][2069],vy[2069],sk[2][2069],inf=1e18;
pair<long long,long long> as[2069];
pair<pair<long long,long long>,long long> ass[5000069];

long long cmp(long long x,long long y,long long x2,long long y2)
{
	return x*y2>=x2*y;
}

bool chk(long long ky,long long x,long long y,long long y2)
{
	long long u=!ky*2-1;
	
	return cmp((vx[ky][y2]-vx[ky][x])*u,vy[x]-vy[y2],(vx[ky][y]-vx[ky][x])*u,vy[x]-vy[y]);
}

bool cmp2(pair<pair<long long,long long>,long long> x,pair<pair<long long,long long>,long long> y)
{
	bool z=!cmp(x.fr.fr,x.fr.sc,y.fr.fr,y.fr.sc);
	
	if(z||!cmp(y.fr.fr,y.fr.sc,x.fr.fr,x.fr.sc))
	{
		return z;
	}
	else
	{
		return x.sc<y.sc;
	}
}

double f(long long ky,long long x,long long w,long long w2)
{
	return (double)(vy[x]*w)/w2+vx[ky][x];
}

int main()
{
	long long i,j,ii,k,l,w,u,c=0,p[2];
	double z=inf;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&vx[1][i],&vx[0][i],vy+i);
		as[i]={vy[i],i};
	}
	sort(as+1,as+n+1);
	for(i=1;i<=n;i++)
	{
		k=as[i].sc;
		for(j=1;as[j].fr<vy[k];j++)
		{
			l=as[j].sc;
			for(ii=0;ii<2;ii++)
			{
				u=!ii*2-1;
				m++;
				ass[m]={{vx[!ii][l]-vx[ii][k],vy[k]-vy[l]},u};
			}
		}
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			if(nn[ii]&&vy[k]==vy[sk[ii][nn[ii]]])
			{
				if(vx[ii][k]*u<=vx[ii][sk[ii][nn[ii]]]*u)
				{
					continue;
				}
				nn[ii]--;
			}
			for(;nn[ii]>=2&&chk(ii,k,sk[ii][nn[ii]],sk[ii][nn[ii]-1]);nn[ii]--);
			nn[ii]++;
			sk[ii][nn[ii]]=k;
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=2;i<=nn[ii];i++)
		{
			k=sk[ii][i];
			l=sk[ii][i-1];
			m++;
			ass[m]={{vx[ii][l]-vx[ii][k],vy[k]-vy[l]},ii*2};
		}
	}
	sort(ass+1,ass+m+1,cmp2);
	p[0]=1;
	p[1]=nn[1];
	for(i=1;i<=m;i++)
	{
		k=ass[i].fr.fr;
		l=ass[i].fr.sc;
		w=ass[i].sc;
		for(ii=0;ii<2;ii++)
		{
			if(!c)
			{
				z=min(z,f(0,sk[0][p[0]],k,l)-f(1,sk[1][p[1]],k,l));
			}
			if(!ii)
			{
				if(abs(w)==1)
				{
					c+=w;
				}
				else
				{
					w/=2;
					u=!w*2-1;
					p[w]+=u;
				}
			}
		}
	}
	if(!m)
	{
		z=f(0,sk[0][p[0]],0,1)-f(1,sk[1][p[1]],0,1);
	}
	printf("%.9lf\n",z);
}