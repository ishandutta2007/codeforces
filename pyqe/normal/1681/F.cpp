#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn,nm,nn2,dh[500069],peu[500069],sbt[500069],ca[500069],sk[500069],ca2[500069],fq[500069];
pair<long long,long long> ed[500069];
vector<long long> al[500069],vl[500069];
bitset<500069> vtd;

bool ceu(long long x,long long y)
{
	return peu[x]>peu[y];
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	n++;
	peu[x]=n;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			dfs(l);
			sbt[x]+=sbt[l];
		}
	}
}

int main()
{
	long long i,j,r,k,l,w,p,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		ed[i]={k,l};
		al[k].push_back(l);
		al[l].push_back(k);
		vl[w].push_back(i);
	}
	n=0;
	dfs(1);
	for(i=1;i<=n;i++)
	{
		nn=vl[i].size();
		for(j=1;j<=nn;j++)
		{
			p=vl[i][j-1];
			k=ed[p].fr;
			l=ed[p].sc;
			if(dh[k]<dh[l])
			{
				swap(k,l);
			}
			ca[j]=k;
		}
		sort(ca+1,ca+nn+1,ceu);
		nn++;
		ca[nn]=1;
		nm=0;
		for(j=1;j<=nn;j++)
		{
			w=sbt[ca[j]];
			nn2=0;
			for(;nm&&peu[sk[nm]]+sbt[sk[nm]]<=peu[ca[j]]+sbt[ca[j]];nm--)
			{
				w-=sbt[sk[nm]];
				nn2++;
				ca2[nn2]=sk[nm];
			}
			for(r=1;r<=nn2;r++)
			{
				z+=fq[ca2[r]]*w;
			}
			nm++;
			sk[nm]=ca[j];
			fq[ca[j]]=w;
		}
	}
	printf("%lld\n",z);
}