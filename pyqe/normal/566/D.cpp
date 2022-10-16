#include <bits/stdc++.h>

using namespace std;

long long n,dsu[200069],cc[200069];
multiset<long long> ms[200069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void jo(long long x,long long y)
{
	multiset<long long>::iterator it;
	
	x=fd(x);
	y=fd(y);
	if(cc[x]<cc[y])
	{
		swap(x,y);
	}
	for(it=ms[y].begin();it!=ms[y].end();it++)
	{
		if(ms[x].find(*it)==ms[x].end())
		{
			ms[x].insert(*it);
		}
		else
		{
			ms[x].erase(*it);
		}
	}
	cc[x]+=cc[y];
	dsu[y]=x;
}

int main()
{
	long long t,rr,i,ii,ky,k,l;
	multiset<long long>::iterator it;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
		cc[i]=1;
		for(ii=0;ii<2;ii++)
		{
			ms[i].insert(i-ii);
		}
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		if(ky==1)
		{
			if(fd(k)!=fd(l))
			{
				jo(k,l);
			}
		}
		else if(ky==2)
		{
			for(;1;)
			{
				it=ms[fd(k)].lower_bound(k);
				if(*it>=l)
				{
					break;
				}
				jo(k,*it+1);
			}
		}
		else if(fd(k)==fd(l))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}