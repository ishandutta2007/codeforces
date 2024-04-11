#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,fi;
bitset<200069> a,fw,sq;
pair<long long,long long> qq[200069];
vector<long long> ql[200069];

void ud(long long x,long long w)
{
	for(fi=x;fi<=m;fi+=fi&-fi)
	{
		fw[fi]=fw[fi]^w;
	}
}

bool qr(long long lh,long long rh)
{
	bool z=0;
	
	for(fi=rh;fi;fi-=fi&-fi)
	{
		z^=fw[fi];
	}
	for(fi=lh-1;fi;fi-=fi&-fi)
	{
		z^=fw[fi];
	}
	return z;
}

int main()
{
	long long t,rr,i,j,r,k,l,sz,pz;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		a[k]=!a[k];
	}
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		qq[rr]={k,l};
	}
	for(i=0;1ll<<i<=m;i++)
	{
		for(j=1;j<=min(1ll<<i+1,m);j++)
		{
			ql[j].clear();
		}
		for(j=1;j<=t;j++)
		{
			k=qq[j].fr;
			ql[(k-1)%(1ll<<i+1)+1].push_back(j);
		}
		fw.reset();
		for(j=1;j<=m;j++)
		{
			if(j-1>>i&1)
			{
				ud(j,a[j]);
			}
		}
		for(j=1;j<=min(1ll<<i+1,m);j++)
		{
			sz=ql[j].size();
			for(r=0;r<sz;r++)
			{
				pz=ql[j][r];
				k=qq[pz].fr;
				l=qq[pz].sc;
				sq[pz]=sq[pz]||qr(k,l);
			}
			for(r=(j-1)%(1ll<<i)+1;r<=m;r+=1ll<<i)
			{
				ud(r,a[r]);
			}
		}
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%c",(char)(!sq[rr]+'A'));
	}
	printf("\n");
}