#include <bits/stdc++.h>

using namespace std;

long long n,m,nn=0,nm=0,dsu[200069],cc[200069],fq[200069],ls[200069],vl[200069],rs[200069],sq[200069];
vector<long long> al[200069];
queue<long long> q;

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
	long long i,j,k,l,sz;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(k>l)
		{
			swap(k,l);
		}
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
		cc[i]=1;
		sz=al[i].size();
		for(j=0;j<sz;j++)
		{
			l=al[i][j];
			l=fd(l);
			if(ls[l]<i)
			{
				fq[l]=0;
				ls[l]=i;
			}
			fq[l]++;
		}
		nm=0;
		for(j=1;j<=nn;j++)
		{
			if(ls[vl[j]]<i||fq[vl[j]]<cc[vl[j]])
			{
				cc[i]+=cc[vl[j]];
				dsu[vl[j]]=i;
			}
			else
			{
				nm++;
				rs[nm]=vl[j];
			}
		}
		nm++;
		rs[nm]=i;
		nn=nm;
		for(j=1;j<=nm;j++)
		{
			vl[j]=rs[j];
		}
	}
	for(i=1;i<=nn;i++)
	{
		sq[i]=cc[vl[i]];
	}
	sort(sq+1,sq+nn+1);
	printf("%lld\n",nn);
	for(i=1;i<=nn;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==nn]);
	}
}