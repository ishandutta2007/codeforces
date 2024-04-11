#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ps[2][500069],kd[500069],fh[500069],fw[500069],fi,sq[500069];
bitset<500069> a[3];
pair<pair<long long,long long>,long long> qq[500069];

inline void ud(long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

inline long long qr(long long lh,long long rh)
{
	long long z=0;
	
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
	long long t,rr,i,j,ii,k,l=0,pz;
	char ch;
	
	scanf("%lld",&n);
	for(i=0;i<3;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf(" %c",&ch);
			a[i][j]=ch-'0';
			ps[0][j]+=a[i][j];
			if(i)
			{
				ps[0][j]-=a[i][j]&&a[i-1][j];
			}
			if(j)
			{
				ps[1][j]-=a[i][j]&&a[i][j-1];
				if(i)
				{
					ps[1][j]+=a[i][j]&&a[i-1][j]&&a[i][j-1]&&a[i-1][j-1];
				}
			}
			kd[j]|=(long long)a[i][j]<<i;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			ps[ii][i]+=ps[ii][i-1];
		}
		if(kd[i]==7)
		{
			if(l&&l<i-1)
			{
				fh[i]=l;
			}
			l=i;
		}
		else if(kd[i]!=5)
		{
			l=0;
		}
	}
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		sq[rr]=ps[0][l]-ps[0][k-1]+ps[1][l]-ps[1][k];
		qq[rr]={{l,k},rr};
	}
	sort(qq+1,qq+t+1);
	for(i=1,rr=1;rr<=t;rr++)
	{
		l=qq[rr].fr.fr;
		k=qq[rr].fr.sc;
		pz=qq[rr].sc;
		for(;i<=l;i++)
		{
			if(fh[i])
			{
				ud(fh[i],1);
			}
		}
		sq[pz]+=qr(k,l);
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%lld\n",sq[rr]);
	}
}