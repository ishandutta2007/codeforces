#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ma=2e5,a[200069],dsu[200069],cc[200069],ls[200069],sq[200069];
pair<long long,long long> ed[200069];
vector<long long> vl[200069];

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
	long long i,j,r,k,l,sz,p;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		ed[i]={k,l};
		vl[__gcd(a[k],a[l])].push_back(i);
	}
	for(i=1;i<=n;i++)
	{
		ls[i]=ma+1;
	}
	for(i=ma;i;i--)
	{
		for(j=i;j<=ma;j+=i)
		{
			sq[i]-=sq[j];
			sz=vl[j].size();
			for(r=0;r<sz;r++)
			{
				p=vl[j][r];
				k=ed[p].fr;
				l=ed[p].sc;
				if(ls[k]>i)
				{
					ls[k]=i;
					dsu[k]=k;
					cc[k]=1;
				}
				if(ls[l]>i)
				{
					ls[l]=i;
					dsu[l]=l;
					cc[l]=1;
				}
				sq[i]+=cc[fd(k)]*cc[fd(l)];
				cc[fd(k)]+=cc[fd(l)];
				dsu[fd(l)]=fd(k);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		sq[a[i]]++;
	}
	for(i=1;i<=ma;i++)
	{
		if(sq[i])
		{
			printf("%lld %lld\n",i,sq[i]);
		}
	}
}