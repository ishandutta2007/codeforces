#include <bits/stdc++.h>

using namespace std;

int n,nn=0,sqn=1732,lky[69],a[100069],fq[69][10069],lz[69];
bitset<10069> spc;

void ud(int lh,int rh,int w)
{
	int i;
	
	for(i=lh;i<min(((lh-1)/sqn+1)*sqn,rh/sqn*sqn);i++)
	{
		fq[i/sqn][a[i]]--;
		a[i]+=w;
		fq[i/sqn][a[i]]++;
	}
	for(i=(lh-1)/sqn+1;i<rh/sqn;i++)
	{
		lz[i]+=w;
	}
	for(i=max(rh/sqn*sqn,lh);i<=rh;i++)
	{
		fq[i/sqn][a[i]]--;
		a[i]+=w;
		fq[i/sqn][a[i]]++;
	}
}

int qr(int lh,int rh)
{
	int i,j,z=0;
	
	for(i=lh;i<min(((lh-1)/sqn+1)*sqn,rh/sqn*sqn);i++)
	{
		z+=spc[a[i]+lz[i/sqn]];
	}
	for(i=(lh-1)/sqn+1;i<rh/sqn;i++)
	{
		for(j=1;j<=nn;j++)
		{
			z+=fq[i][max(lky[j]-lz[i],0)];
		}
	}
	for(i=max(rh/sqn*sqn,lh);i<=rh;i++)
	{
		z+=spc[a[i]+lz[i/sqn]];
	}
	return z;
}

int main()
{
	int t,rr,i,j,mk,k,l,w;
	string s;
	
	for(i=1;i<=4;i++)
	{
		for(mk=0;mk<1<<i;mk++)
		{
			nn++;
			for(j=1;j<=i;j++)
			{
				lky[nn]=lky[nn]*10+4+3*(mk>>j-1&1);
			}
			spc[lky[nn]]=1;
		}
	}
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		fq[i/sqn][a[i]]++;
	}
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		scanf("%d%d",&k,&l);
		if(s[0]=='a')
		{
			scanf("%d",&w);
			ud(k,l,w); 
		}
		else
		{
			printf("%d\n",qr(k,l));
		}
	}
}