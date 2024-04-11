#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[200069],dsu[2][200069],cc[200069];
multiset<pair<long long,long long>> ms;

long long fd(long long xx,long long x)
{
	if(dsu[xx][x]!=x)
	{
		dsu[xx][x]=fd(xx,dsu[xx][x]);
	}
	return dsu[xx][x];
}

int main()
{
	long long i,ii,u,k,l,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(i=(n+1)*ii;i>=0&&i<=n+1;i+=u)
		{
			dsu[ii][i]=i;
			if(i-u>0&&i-u<=n&&a[i]==a[i-u])
			{
				dsu[ii][i-u]=i;
			}
			if(ii)
			{
				cc[i]=1;
				if(i-u>0&&i-u<=n&&a[i]==a[i-u])
				{
					cc[i]+=cc[i-u];
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(fd(1,i)==i)
		{
			ms.insert({-cc[i],i});
		}
	}
	for(;!ms.empty();)
	{
		k=ms.begin()->sc;
		ms.erase(ms.begin());
		z++;
		l=fd(0,k)+1;
		a[k]=a[l];
		cc[k]=cc[l];
		dsu[0][fd(0,k)]=fd(0,l);
		dsu[1][l]=k;
		if(fd(0,l)<=n)
		{
			ms.erase({-cc[l],l});
			ms.insert({-cc[k],k});
		}
		l=fd(1,k-1);
		if(a[k]==a[l])
		{
			cc[l]+=cc[k];
			dsu[0][fd(0,l)]=fd(0,k);
			dsu[1][k]=l;
			if(l>0)
			{
				ms.erase({-cc[k],k});
				ms.erase({-(cc[l]-cc[k]),l});
				ms.insert({-cc[l],l});
			}
			
		}
	}
	printf("%lld\n",z);
}