#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nh,dsu[2000069],cc[2000069],hs[2000069],z;
pair<long long,long long> ed[1000069];
bitset<1000069> sq;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		return fd(dsu[x]);
	}
	else
	{
		return x;
	}
}

inline void jo(long long x,long long y)
{
	x=fd(x);
	y=fd(y);
	if(cc[x]<cc[y])
	{
		swap(x,y);
	}
	if(x!=y)
	{
		cc[x]+=cc[y];
	}
	dsu[y]=x;
	nh++;
	hs[nh]=y;
}

inline bool jo2(long long x,long long y)
{
	if(fd(x)==fd(y))
	{
		return 0;
	}
	jo(x,n+y);
	jo(n+x,y);
	return 1;
}

inline void un()
{
	dsu[hs[nh]]=hs[nh];
	nh--;
}

void dnc(long long lb,long long rb)
{
	if(lb==rb)
	{
		z=lb;
	}
	else
	{
		long long i,ii,k,l,md=(lb+rb)/2;
		
		for(i=md+1;i<=rb;i++)
		{
			k=ed[i].fr;
			l=ed[i].sc;
			if(!jo2(k,l))
			{
				break;
			}
		}
		if(i>rb)
		{
			dnc(lb,md);
			if(z!=-1)
			{
				return;
			}
		}
		for(i--;i>md;i--)
		{
			for(ii=0;ii<2;ii++)
			{
				un();
			}
		}
		for(i=lb;i<=md;i++)
		{
			k=ed[i].fr;
			l=ed[i].sc;
			if(!jo2(k,l))
			{
				break;
			}
		}
		if(i>md)
		{
			dnc(md+1,rb);
			if(z!=-1)
			{
				return;
			}
		}
		for(i--;i>=lb;i--)
		{
			for(ii=0;ii<2;ii++)
			{
				un();
			}
		}
	}
}

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%lld%lld",&k,&l);
			ed[i]={k,l};
		}
		for(i=1;i<=n*2;i++)
		{
			dsu[i]=i;
			cc[i]=1;
		}
		nh=0;
		z=-1;
		dnc(1,m);
		if(z==-1)
		{
			printf("NO\n");
			continue;
		}
		k=ed[z].fr;
		l=ed[z].sc;
		for(i=1;i<=n;i++)
		{
			if(fd(i)==fd(k))
			{
				sq[i]=1;
			}
			else if(fd(n+i)==fd(k))
			{
				sq[i]=0;
			}
			else
			{
				sq[i]=fd(i)==fd(l);
			}
		}
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			printf("%lld",(long long)sq[i]);
		}
		printf("\n");
	}
}