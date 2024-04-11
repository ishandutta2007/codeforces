#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,dsu[400069],cc[400069],dp[200069];
pair<long long,long long> ed[200069],hs[400069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		return fd(dsu[x]);
	}
	return x;
}

void jo(long long x,long long y)
{
	x=fd(x);
	y=fd(y);
	if(cc[x]<cc[y])
	{
		swap(x,y);
	}
	if(x!=y)
	{
		dsu[y]=x;
		cc[x]+=cc[y];
	}
	nn++;
	hs[nn]={x,y};
}

void un()
{
	long long k,l;
	
	k=hs[nn].fr;
	l=hs[nn].sc;
	nn--;
	if(k!=l)
	{
		dsu[l]=l;
		cc[k]-=cc[l];
	}
}

void dnc(long long lh,long long rh,long long rb,bool g)
{
	long long i,k,l,md=(lh+rh)/2,e;
	bool bad=g;
	
	for(i=lh+1;i<=md;i++)
	{
		k=ed[i].fr;
		l=ed[i].sc;
		jo(k,n+l);
		jo(n+k,l);
		bad|=fd(k)==fd(l);
	}
	if(!bad)
	{
		for(i=rb-1;i>=md;i--)
		{
			k=ed[i].fr;
			l=ed[i].sc;
			jo(k,n+l);
			jo(n+k,l);
			if(fd(k)==fd(l)||i==md)
			{
				break;
			}
		}
		e=i;
	}
	else
	{
		e=rb;
	}
	dp[md]=e;
	for(i=0;i<(rb-e+md-lh)*2;i++)
	{
		un();
	}
	if(lh<=md-1)
	{
		bad=g;
		for(i=rb-1;i>=e;i--)
		{
			k=ed[i].fr;
			l=ed[i].sc;
			jo(k,n+l);
			jo(n+k,l);
			bad|=fd(k)==fd(l);
		}
		dnc(lh,md-1,e,bad);
		for(i=0;i<(rb-e)*2;i++)
		{
			un();
		}
	}
	if(md+1<=rh)
	{
		bad=g;
		for(i=lh+1;i<=md+1;i++)
		{
			k=ed[i].fr;
			l=ed[i].sc;
			jo(k,n+l);
			jo(n+k,l);
			bad|=fd(k)==fd(l);
		}
		dnc(md+1,rh,rb,bad);
		for(i=0;i<(md+1-lh)*2;i++)
		{
			un();
		}
	}
}

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld%lld%lld",&n,&m,&t);
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
	dnc(0,m,m+1,0);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(l+1<=dp[k-1])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}