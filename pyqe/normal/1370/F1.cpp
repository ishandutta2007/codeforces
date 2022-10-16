#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second
long long n,d,rt,sbt[1069],dh[1069],pr[1069];
vector<long long> al[1069],vl[1069];
bitset<1069> vtd;

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			pr[l]=x;
			bd(l);
			sbt[x]+=sbt[l];
		}
	}
}

void bd2(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vl[dh[x]].push_back(x);
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			bd2(l);
		}
	}
}

int main()
{
	long long t,rr,i,k,l,sz,e,lh,rh,md,zz,zp,p;
	pair<long long,long long> mxe;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		printf("? %lld",n);
		for(i=1;i<=n;i++)
		{
			printf(" %lld",i);
		}
		printf("\n");
		fflush(stdout);
		scanf("%lld%lld",&rt,&d);
		vtd.reset();
		dh[rt]=0;
		bd(rt);
		mxe={0,-1};
		sz=al[rt].size();
		for(i=0;i<sz;i++)
		{
			l=al[rt][i];
			mxe=max(mxe,{sbt[l],l});
		}
		e=mxe.sc;
		vtd.reset();
		for(i=0;i<n;i++)
		{
			vl[i].clear();
		}
		vtd[e]=1;
		bd2(rt);
		for(zz=0,zp=rt,lh=1,rh=n-n/2-1;lh<=rh;)
		{
			md=(lh+rh)/2;
			sz=vl[md].size();
			if(sz)
			{
				printf("? %lld",sz);
				for(i=0;i<sz;i++)
				{
					k=vl[md][i];
					printf(" %lld",k);
				}
				printf("\n");
				fflush(stdout);
				scanf("%lld%lld",&k,&l);
			}
			if(sz&&l==d)
			{
				zz=md;
				zp=k;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		for(p=zp;dh[p]>d-zz;p=pr[p]);
		vtd.reset();
		vtd[rt]=1;
		bd2(e);
		sz=vl[d-zz].size();
		if(sz-(d-zz<=zz))
		{
			printf("? %lld",sz-(d-zz<=zz));
			for(i=0;i<sz;i++)
			{
				k=vl[d-zz][i];
				if(k!=p)
				{
					printf(" %lld",k);
				}
			}
			printf("\n");
			fflush(stdout);
			scanf("%lld%lld",&k,&l);
		}
		else
		{
			k=rt;
		}
		printf("! %lld %lld\n",zp,k);
		fflush(stdout);
		cin>>s;
	}
}