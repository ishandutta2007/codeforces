#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,nn=0,dh[200069],pst[200069],sbt[200069],lg2[400069],ca[200069];
vector<long long> al[200069];
bitset<200069> vtd;
pair<long long,long long> sp[19][400069];

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	nn++;
	sp[0][nn]={dh[x],x};
	pst[x]=nn;
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

bool cdh(long long x,long long y)
{
	return dh[x]>dh[y];
}

int main()
{
	long long t,rr,i,ii,k,l,sz,ls[2],c,mn,mx,la;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	bd(1);
	spbd();
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&sz);
		for(i=1;i<=sz;i++)
		{
			scanf("%lld",ca+i);
			vtd[i]=0;
		}
		if(sz==1)
		{
			printf("YES\n");
			continue;
		}
		sort(ca+1,ca+sz+1,cdh);
		c=0;
		for(ii=0;ii<2;ii++)
		{
			ls[ii]=0;
			for(i=1;i<=sz;i++)
			{
				if(!vtd[i]&&(!ls[ii]||(pst[ca[i]]<=pst[ls[ii]]&&pst[ca[i]]+sbt[ca[i]]*2>=pst[ls[ii]]+sbt[ls[ii]]*2)))
				{
					vtd[i]=1;
					c++;
					ls[ii]=ca[i];
				}
			}
		}
		if(c<sz)
		{
			printf("NO\n");
			continue;
		}
		if(pst[ls[0]]>pst[ls[1]])
		{
			swap(ls[0],ls[1]);
		}
		if(pst[ls[0]]+sbt[ls[0]]*2-2<pst[ls[1]])
		{
			printf("YES\n");
			continue;
		}
		mn=inf;
		mx=-inf;
		for(i=1;i<=sz;i++)
		{
			if(ca[i]!=ls[0])
			{
				mn=min(mn,pst[ca[i]]);
				mx=max(mx,pst[ca[i]]);
			}
		}
		la=spqr(mn,mx);
		if(la==ls[0])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}