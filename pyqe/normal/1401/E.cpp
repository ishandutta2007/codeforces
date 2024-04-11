#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,ma=1e6,fw[1000069],fi;
pair<long long,long long> a[1000069];
vector<long long> vl[1000069][2];

void ud(long long x,long long w)
{
	x++;
	for(fi=x;fi<=ma+1;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

long long qr(long long lh,long long rh)
{
	long long z=0;
	
	lh++;
	rh++;
	for(fi=rh;fi;fi-=fi&-fi)
	{
		z+=fw[fi];
	}
	for(fi=lh-1;fi;fi-=fi&-fi)
	{
		z-=fw[fi];
	}
	return z;
}

int main()
{
	long long i,j,ii,u,k,l,w,sz,z;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<=ma;i++)
	{
		a[i]={-1,-1};
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&w,&k,&l);
		a[w]={k,l};
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&w,&k,&l);
		vl[k][0].push_back(w);
		vl[l][1].push_back(w);
	}
	a[0]={0,ma};
	a[ma]={0,ma};
	vl[0][0].push_back(0);
	vl[ma][1].push_back(0);
	vl[0][0].push_back(ma);
	vl[ma][1].push_back(ma);
	z=-n-m-3;
	for(i=0;i<=ma;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			sz=vl[i][ii].size();
			for(j=0;j<sz;j++)
			{
				l=vl[i][ii][j];
				ud(l,u);
			}
			if(!ii&&a[i].fr!=-1)
			{
				z+=qr(a[i].fr,a[i].sc);
			}
		}
	}
	printf("%lld\n",z);
}