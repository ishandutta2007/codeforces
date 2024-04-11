#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long ma=2e5,dv=998244353;
long long n,nn=0,nm,ns,dh[200069],peu[200069],sbt[200069],lg2[400069],ca[200069],vi[200069],sk[200069],dp[200069],dp2[200069];
vector<long long> fz[200069],vl[200069],al[200069],dpl[200069],dpl2[200069];
bitset<200069> vtd,spc;
pair<long long,long long> sp[19][400069];
vector<pair<long long,long long>> al2[200069];

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	nn++;
	sp[0][nn]={dh[x],x};
	peu[x]=nn;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			bd(l);
			nn++;
			sp[0][nn]={dh[x],x};
			sbt[x]+=sbt[l];
		}
	}
}

inline void spbd()
{
	long long i,j,k;
	
	for(i=1;1ll<<i<=nn;i++)
	{
		for(j=1;j<=nn-(1ll<<i)+1;j++)
		{
			sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1ll<<i-1)]);
		}
	}
	for(i=1;i<=nn;i++)
	{
		for(k=i;k>1;k/=2,lg2[i]++);
	}
}

inline long long spqr(long long lh,long long rh)
{
	long long e=lg2[rh-lh+1];
	
	return min(sp[e][lh],sp[e][rh-(1ll<<e)+1]).sc;
}

inline long long lca(long long x,long long y)
{
	if(peu[x]>peu[y])
	{
		swap(x,y);
	}
	return spqr(peu[x],peu[y]);
}

bool ceu(long long x,long long y)
{
	return peu[x]<peu[y];
}

void dfs(long long x)
{
	long long i,sz=al2[x].size(),l,w;
	
	dp[x]=spc[x];
	dp2[x]=0;
	for(i=0;i<sz;i++)
	{
		l=al2[x][i].fr;
		w=al2[x][i].sc;
		dfs(l);
		dp[x]+=dp[l];
		dp2[x]=(dp2[x]+dp2[l]+w*dp[l])%dv;
	}
}

void dfs2(long long x,long long cw,long long cw2)
{
	long long i,sz=al2[x].size(),l,w,tw,tw2;
	
	for(i=0;i<sz;i++)
	{
		l=al2[x][i].fr;
		w=al2[x][i].sc;
		dpl[x].push_back(dp[l]);
		dpl2[x].push_back((dp2[l]+w*dp[l])%dv);
		tw=cw+dp[x]-dp[l];
		tw2=(cw2+dp2[x]+dv-(dp2[l]+w*dp[l])%dv+w*tw)%dv;
		dpl[l].push_back(tw);
		dpl2[l].push_back(tw2);
		dfs2(l,tw,tw2);
	}
}

int main()
{
	long long i,j,r,k,l,w,w2,sz,la,sm,sm2,z=0;
	
	for(i=2;i<=ma;i++)
	{
		if(fz[i].empty())
		{
			for(j=i;j<=ma;j+=i)
			{
				fz[j].push_back(i);
			}
		}
	}
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		sz=fz[k].size();
		for(j=0;j<sz;j++)
		{
			l=fz[k][j];
			vl[l].push_back(i);
		}
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	bd(1);
	spbd();
	for(i=1;i<=ma;i++)
	{
		if(vl[i].empty())
		{
			continue;
		}
		nm=0;
		sz=vl[i].size();
		for(j=0;j<sz;j++)
		{
			k=vl[i][j];
			nm++;
			ca[nm]=k;
			vi[k]=i;
			spc[k]=1;
		}
		sort(ca+1,ca+nm+1,ceu);
		for(j=nm-1;j;j--)
		{
			la=lca(ca[j],ca[j+1]);
			if(vi[la]<i)
			{
				nm++;
				ca[nm]=la;
				vi[la]=i;
				spc[la]=0;
			}
		}
		sort(ca+1,ca+nm+1,ceu);
		ns=0;
		for(j=nm;j;j--)
		{
			al2[ca[j]].clear();
			dpl[ca[j]].clear();
			dpl2[ca[j]].clear();
			for(;ns&&peu[sk[ns]]<=peu[ca[j]]+sbt[ca[j]]*2-2;ns--)
			{
				al2[ca[j]].push_back({sk[ns],dh[sk[ns]]-dh[ca[j]]});
			}
			ns++;
			sk[ns]=ca[j];
		}
		dfs(sk[ns]);
		dfs2(sk[ns],0,0);
		for(j=1;j<=nm;j++)
		{
			sm=spc[ca[j]];
			sm2=0;
			sz=dpl[ca[j]].size();
			for(r=0;r<sz;r++)
			{
				w=dpl[ca[j]][r];
				sm2=(sm2+w*sm)%dv;
				sm+=w;
			}
			for(r=0;r<sz;r++)
			{
				w=dpl[ca[j]][r];
				w2=dpl2[ca[j]][r];
				z=(z+w2*(sm2+dv-w*(sm-w)%dv))%dv;
			}
		}
	}
	printf("%lld\n",z);
}