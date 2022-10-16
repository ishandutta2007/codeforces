#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,d2,d3,nn=0,as[50069],dsu[69],sq[50069][2];
pair<long long,pair<long long,long long>> ed[369];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long t,t2,rr,i,j,u,k,l,w,w2,p[2],e,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		ed[i]={w,{k,l}};
	}
	sort(ed+1,ed+m+1);
	nn++;
	as[nn]=-1;
	for(i=1;i<=m;i++)
	{
		w=ed[i].fr;
		for(j=i;j<=m;j++)
		{
			w2=ed[j].fr;
			nn++;
			as[nn]=(w+w2)/2+1;
		}
	}
	sort(as+1,as+nn+1);
	for(i=1;i<=nn;i++)
	{
		for(j=1;j<=n;j++)
		{
			dsu[j]=j;
		}
		p[0]=lower_bound(ed+1,ed+m+1,mp(as[i],mp(0ll,0ll)))-ed;
		p[1]=p[0]-1;
		for(;p[0]<=m||p[1]>0;p[e]+=u)
		{
			e=p[0]>m||(p[1]>0&&as[i]-ed[p[1]].fr<ed[p[0]].fr-as[i]);
			u=!e*2-1;
			w=ed[p[e]].fr;
			k=ed[p[e]].sc.fr;
			l=ed[p[e]].sc.sc;
			if(fd(k)!=fd(l))
			{
				dsu[fd(l)]=fd(k);
				sq[i][0]-=u;
				sq[i][1]+=w*u;
			}
		}
	}
	scanf("%lld%lld%lld%lld%lld",&t2,&t,&d,&d2,&d3);
	for(rr=1;rr<=t;rr++)
	{
		if(rr<=t2)
		{
			scanf("%lld",&k);
		}
		else
		{
			k=(k*d+d2)%d3;
		}
		l=upper_bound(as+1,as+nn+1,k)-as-1;
		z^=sq[l][0]*k+sq[l][1];
	}
	printf("%lld\n",z);
}