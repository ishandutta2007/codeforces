#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn;
pair<long long,long long> a[269];
map<pair<pair<long long,long long>,long long>,long long> yk;
bitset<20269> vtd[269];
vector<long long> al[20269];
double mz[14][269][269],a0[269],az[269];

int main()
{
	long long t,rr,i,j,r,ii,k,l,w,sz,ll,szz,p,y,x,ly,lx,gd;
	double sm,z;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&y,&x);
		a[i]={y,x};
	}
	nn=n;
	for(i=1;i<=n;i++)
	{
		y=a[i].fr;
		x=a[i].sc;
		for(j=i+1;j<=n;j++)
		{
			ly=y-a[j].fr;
			lx=x-a[j].sc;
			gd=__gcd(ly,lx);
			ly/=gd;
			lx/=gd;
			if(lx<0||(!lx&&ly<0))
			{
				ly*=-1;
				lx*=-1;
			}
			w=y*lx-x*ly;
			if(!yk[{{ly,lx},w}])
			{
				nn++;
				yk[{{ly,lx},w}]=nn;
			}
			k=yk[{{ly,lx},w}];
			for(ii=0;ii<2;ii++)
			{
				if(!vtd[i][k])
				{
					al[i].push_back(k);
					al[k].push_back(i);
					vtd[i][k]=1;
				}
				swap(i,j);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		sz=al[i].size();
		for(j=0;j<sz;j++)
		{
			l=al[i][j];
			szz=al[l].size();
			for(r=0;r<szz;r++)
			{
				ll=al[l][r];
				mz[0][ll][i]+=(double)1/(sz*szz);
			}
		}
	}
	for(i=1;i<14;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(r=1;r<=n;r++)
			{
				for(p=1;p<=n;p++)
				{
					mz[i][j][r]+=mz[i-1][j][p]*mz[i-1][p][r];
				}
			}
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&w);
		for(i=1;i<=n;i++)
		{
			a0[i]=0;
			az[i]=0;
		}
		a0[k]=1;
		for(i=0;i<14;i++)
		{
			if(w-1>>i&1)
			{
				for(j=1;j<=n;j++)
				{
					for(r=1;r<=n;r++)
					{
						az[r]+=a0[j]*mz[i][j][r];
					}
				}
				for(j=1;j<=n;j++)
				{
					a0[j]=az[j];
					az[j]=0;
				}
			}
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			sm=0;
			for(j=1;j<=n;j++)
			{
				sm+=a0[j]*mz[0][j][i];
			}
			z=max(z,sm);
		}
		for(i=n+1;i<=nn;i++)
		{
			sm=0;
			sz=al[i].size();
			for(j=0;j<sz;j++)
			{
				l=al[i][j];
				sm+=a0[l]/sz;
			}
			z=max(z,sm);
		}
		printf("%.20lf\n",z);
	}
}