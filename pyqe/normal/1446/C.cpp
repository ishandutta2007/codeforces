#include <bits/stdc++.h>

using namespace std;

long long n,nn,d=31,a[31];

struct trie
{
	long long i,dh,sbt=0,z=1;
	trie *p[31];
	
	void bd(long long x)
	{
		long long i;
		
		dh=x;
		for(i=0;i<d;i++)
		{
			p[i]=0;
		}
	}
	void ins()
	{
		sbt++;
		if(dh<=nn)
		{
			if(!p[a[dh]])
			{
				p[a[dh]]=new trie;
				p[a[dh]]->bd(dh+1);
			}
			p[a[dh]]->ins();
		}
	}
	void dfs()
	{
		long long i,j,k,sm=0;
		
		for(j=30,i=30;i+1;i--)
		{
			k=0;
			if(p[i])
			{
				p[i]->dfs();
				k=p[i]->z;
			}
			for(j=min(j,i-1);j+1&&!p[j];j--);
			z=max(z,sm+k+(j>=0));
			sm+=!!p[i];
		}
	}
}
tr;

int main()
{
	long long i,j,k;
	
	scanf("%lld",&n);
	tr.bd(0);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		nn=0;
		a[0]=0;
		for(j=1;k;k/=2,j++)
		{
			if(k%2)
			{
				nn++;
				a[nn]=j;
			}
		}
		for(j=0;j<nn-j;j++)
		{
			swap(a[j],a[nn-j]);
		}
		tr.ins();
	}
	tr.dfs();
	printf("%lld\n",n-tr.z);
}