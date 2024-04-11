#include <bits/stdc++.h>

using namespace std;

long long n,m,ed[300069][2],od[300069],dsu[300069],cc[300069][2],kd[300069];
bitset<300069> a,lz;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		fd(dsu[x]);
		lz[x]=lz[x]^lz[dsu[x]];
		dsu[x]=dsu[dsu[x]];
	}
	return dsu[x];
}

long long val(long long x)
{
	x=fd(x);
	if(kd[x]==-1)
	{
		return min(cc[x][0],cc[x][1]);
	}
	else
	{
		return cc[x][kd[x]];
	}
}

int main()
{
	long long i,j,ii,k,l,sz,p,z=0;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch-'0';
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&sz);
		for(j=0;j<sz;j++)
		{
			scanf("%lld",&k);
			ed[k][od[k]]=i;
			od[k]++;
		}
		dsu[i]=i;
		cc[i][0]=1;
		kd[i]=-1;
	}
	for(i=1;i<=n;i++)
	{
		k=ed[i][0];
		l=ed[i][1];
		if(!l)
		{
			z-=val(k);
			kd[fd(k)]=a[i]^lz[k];
			z+=val(k);
		}
		else if(fd(k)!=fd(l))
		{
			z-=val(k)+val(l);
			if(kd[fd(l)]+1)
			{
				kd[fd(k)]=kd[fd(l)]^!a[i]^lz[k]^lz[l];
			}
			for(ii=0;ii<2;ii++)
			{
				cc[fd(k)][ii]+=cc[fd(l)][ii^!a[i]^lz[k]^lz[l]];
			}
			p=fd(l);
			dsu[p]=fd(k);
			lz[p]=!a[i]^lz[k]^lz[l];
			z+=val(k);
		}
		printf("%lld\n",z);
	}
}