#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,nn=0,a[500069],dsu[1000069],cc[1000069];
pair<long long,long long> hs[1000069];
bitset<500069> spc;
vector<pair<long long,long long>> al[500069];

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

bool cmp(pair<long long,long long> x,pair<long long,long long> y)
{
	return a[x.sc]<a[y.sc];
}

int main()
{
	long long i,j,r,ii,k,l,sz,sm=0,c,z=0;
	bool bad;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n*2;i++)
	{
		dsu[i]=i;
		cc[i]=1;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(a[k]==a[l])
		{
			spc[a[k]]=spc[a[k]]|fd(k)==fd(l);
			jo(k,n+l);
			jo(n+k,l);
		}
		else
		{
			if(a[k]<a[l])
			{
				swap(k,l);
			}
			al[a[k]].push_back({k,l});
		}
	}
	for(i=1;i<=d;i++)
	{
		if(!spc[i])
		{
			c=0;
			bad=0;
			sort(al[i].begin(),al[i].end(),cmp);
			sz=al[i].size();
			for(r=0,j=0;j<sz;j++)
			{
				k=al[i][j].fr;
				l=al[i][j].sc;
				bad|=fd(k)==fd(l);
				jo(k,n+l);
				jo(n+k,l);
				if(j==sz-1||a[l]!=a[al[i][j+1].sc])
				{
					c+=bad&&!spc[a[l]];
					bad=0;
					for(;r<=j;r++)
					{
						for(ii=0;ii<2;ii++)
						{
							un();
						}
					}
				}
			}
			z+=sm-c;
			sm++;
		}
	}
	printf("%lld\n",z);
}