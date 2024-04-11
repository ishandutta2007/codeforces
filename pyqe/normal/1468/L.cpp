#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,np=0,nn=0,ns=0,nm=0,ma=1e6,ub=1e9,pe[100069],a[1069],ex[569],ey[1069],sq[1069],zs=0,inf=1e18;
bitset<1000069> vtd;
vector<long long> vl[569],fz[1069];
bitset<569> spc;

int main()
{
	long long i,j,k,sz,p,c,tg=0,e;
	pair<long long,long long> mne={inf,-1};
	
	for(i=2;i<=ma;i++)
	{
		if(!vtd[i])
		{
			np++;
			pe[np]=i;
			for(j=i*i;j<=ma;j+=i)
			{
				vtd[j]=1;
			}
		}
	}
	scanf("%lld%lld",&n,&m);
	if(m==1)
	{
		printf("0\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(j=1;j<=np;j++)
		{
			if(a[i]%pe[j]==0)
			{
				j=-1;
				break;
			}
		}
		if(j!=-1&&a[i]<=ub)
		{
			np++;
			pe[np]=a[i];
		}
	}
	sort(a+1,a+n+1);
	for(i=1;i<=np;i++)
	{
		c=0;
		for(k=pe[i];k<=a[n];k*=pe[i])
		{
			p=lower_bound(a+1,a+n+1,k)-a;
			if(a[p]==k)
			{
				vl[nn+1].push_back(k);
				c++;
			}
		}
		if(c>=2)
		{
			nn++;
			ex[nn]=pe[i];
			ns+=c;
			if(c>2)
			{
				tg=nn;
			}
		}
		else
		{
			vl[nn+1].clear();
		}
	}
	for(i=1;i<=n;i++)
	{
		k=a[i];
		c=0;
		for(j=1;j<=nn;j++)
		{
			if(k%ex[j]==0)
			{
				fz[nm+1].push_back(j);
				c++;
				for(;k%ex[j]==0;k/=ex[j]);
			}
		}
		if(k==1&&c>1)
		{
			nm++;
			ey[nm]=a[i];
			mne=min(mne,{c,nm});
		}
		else
		{
			fz[nm+1].clear();
		}
	}
	e=mne.sc;
	if(m>ns+nm)
	{
		printf("0\n");
		return 0;
	}
	else if(m>=nn*2)
	{
		for(i=1;i<=nn;i++)
		{
			for(j=0;j<2;j++)
			{
				zs++;
				sq[zs]=vl[i][j];
			}
		}
		for(i=1;i<=nn;i++)
		{
			sz=vl[i].size();
			for(j=2;j<sz;j++)
			{
				if(zs<m)
				{
					zs++;
					sq[zs]=vl[i][j];
				}
			}
		}
		for(i=1;i<=nm;i++)
		{
			if(zs<m)
			{
				zs++;
				sq[zs]=ey[i];
			}
		}
	}
	else if(m%2==0)
	{
		for(i=1;i<=m/2;i++)
		{
			for(j=0;j<2;j++)
			{
				zs++;
				sq[zs]=vl[i][j];
			}
		}
	}
	else if(tg)
	{
		for(i=0;i<3;i++)
		{
			zs++;
			sq[zs]=vl[tg][i];
		}
		for(i=1;i<=nn;i++)
		{
			if(i!=tg)
			{
				for(j=0;j<2;j++)
				{
					if(zs<m)
					{
						zs++;
						sq[zs]=vl[i][j];
					}
				}
			}
		}
	}
	else if(e+1&&m>=(long long)fz[e].size()*2)
	{
		zs++;
		sq[zs]=ey[e];
		sz=fz[e].size();
		for(i=0;i<sz;i++)
		{
			k=fz[e][i];
			spc[k]=1;
			for(j=0;j<2;j++)
			{
				zs++;
				sq[zs]=vl[k][j];
			}
		}
		for(i=1;i<=nn;i++)
		{
			if(!spc[i])
			{
				for(j=0;j<2;j++)
				{
					if(zs<m)
					{
						zs++;
						sq[zs]=vl[i][j];
					}
				}
			}
		}
	}
	else
	{
		printf("0\n");
		return 0;
	}
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}