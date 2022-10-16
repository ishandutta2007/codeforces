#include <bits/stdc++.h>

using namespace std;

const long long ma=1e6;
long long n,a[150069],ls[1000069],dsu[150069];
vector<long long> fz[1000069];
map<long long,bool> spc[150069];

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
	long long t,rr,i,j,r,k,l,sz,z;
	
	for(i=2;i<=ma+1;i++)
	{
		sz=fz[i].size();
		if(!sz)
		{
			for(j=i;j<=ma+1;j+=i)
			{
				fz[j].push_back(i);
			}
		}
	}
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		dsu[i]=i;
		sz=fz[a[i]].size();
		for(j=0;j<sz;j++)
		{
			k=fz[a[i]][j];
			if(ls[k])
			{
				dsu[fd(ls[k])]=fd(i);
			}
			ls[k]=i;
		}
	}
	for(i=1;i<=n;i++)
	{
		sz=fz[a[i]+1].size();
		for(j=0;j<sz;j++)
		{
			k=fz[a[i]+1][j];
			if(ls[k])
			{
				spc[fd(i)][fd(ls[k])]=1;
				for(r=j+1;r<sz;r++)
				{
					l=fz[a[i]+1][r];
					if(ls[l])
					{
						spc[fd(ls[k])][fd(ls[l])]=1;
						spc[fd(ls[l])][fd(ls[k])]=1;
					}
				}
			}
		}
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(fd(k)==fd(l))
		{
			z=0;
		}
		else if(spc[fd(k)][fd(l)]||spc[fd(l)][fd(k)])
		{
			z=1;
		}
		else
		{
			z=2;
		}
		printf("%lld\n",z);
	}
}