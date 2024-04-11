#include <bits/stdc++.h>

using namespace std;

long long n,m,wg[400069],ls[400069],dsu[400069],dh[400069],dg[400069];
bitset<400069> a;
vector<long long> al[400069];
bitset<400069> vtd,vtd2;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void scc(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			scc(l);
		}
		if(vtd2[fd(l)]&&dh[fd(l)]<dh[fd(x)])
		{
			dsu[fd(x)]=fd(l);
		}
	}
	vtd2[x]=0;
}

int main()
{
	long long i,j,l,sz,p,z=0;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			p=i*m+j;
			scanf(" %c",&ch);
			a[p]=ch=='#';
			dsu[p]=p;
		}
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld",wg+i);
		ls[i]=-1;
	}
	for(i=n-1;i+1;i--)
	{
		for(j=0;j<m;j++)
		{
			p=i*m+j;
			if(a[p])
			{
				if(ls[j]+1)
				{
					al[p].push_back(ls[j]);
				}
				if(j&&ls[j-1]+1)
				{
					al[p].push_back(ls[j-1]);
				}
				if(i&&a[p-m])
				{
					al[p].push_back(p-m);
				}
				ls[j]=p;
			}
		}
		for(j=0;j<m-1;j++)
		{
			p=i*m+j;
			if(a[p])
			{
				if(ls[j+1]+1)
				{
					al[p].push_back(ls[j+1]);
				}
			}
		}
	}
	for(i=0;i<n*m;i++)
	{
		if(a[i]&&!vtd[i])
		{
			scc(i);
		}
	}
	for(i=0;i<n*m;i++)
	{
		if(a[i])
		{
			sz=al[i].size();
			for(j=0;j<sz;j++)
			{
				l=al[i][j];
				if(fd(i)!=fd(l))
				{
					dg[fd(l)]++;
				}
			}
		}
	}
	for(i=0;i<n*m;i++)
	{
		z+=a[i]&&fd(i)==i&&!dg[i];
	}
	printf("%lld\n",z);
}