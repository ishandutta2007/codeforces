#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,dh[1000069],fh[1000069],fq[20][1000069],sq[1000069];
vector<long long> al[1000069];
bitset<1000069> vtd;
pair<long long,long long> mxe[20];

void bd(long long x)
{
	long long i,sz=al[x].size(),l,mx=0;
	vector<long long> v;
	
	vtd[x]=1;
	fh[x]=dh[x];
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			bd(l);
			v.push_back(l);
			fh[x]=max(fh[x],fh[l]);
			mx=max(mx,fh[l]);
		}
	}
	sz=v.size();
	if(sz)
	{
		for(i=0;fh[v[i]]<mx;i++);
		swap(v[0],v[i]);
	}
	al[x]=v;
}

void ad(long long xx,long long x,long long w)
{
	fq[xx][x]+=w;
	mxe[xx]=max(mxe[xx],{fq[xx][x],-x});
}

void dfs(long long x)
{
	long long i,j,sz=al[x].size(),l,ub;
	
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dfs(l);
		ub=fh[l];
		if(!i)
		{
			nn++;
			ub=dh[x];
		}
		nn--;
		for(j=dh[l];j<=ub;j++)
		{
			ad(nn-1,j,fq[nn][j]);
			fq[nn][j]=0;
		}
		mxe[nn]={0,0};
	}
	if(!sz)
	{
		nn++;
	}
	ad(nn-1,dh[x],1);
	sq[x]=-mxe[nn-1].sc-dh[x];
}

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	bd(1);
	dfs(1);
	for(i=1;i<=n;i++)
	{
		printf("%lld\n",sq[i]);
	}
}