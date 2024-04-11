#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn,nn2,fh[500069][2],pr[500069],ca[500069],fq[500069],sq[2][500069];
vector<long long> al[500069],fhl[500069];
bitset<500069> vtd;
pair<long long,long long> ca2[500069];

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			pr[l]=x;
			bd(l);
			fh[x][1]=max(fh[x][1],min(fh[x][0],fh[l][0]+1));
			fh[x][0]=max(fh[x][0],fh[l][0]+1);
		}
	}
}

void bd2(long long x,long long cw)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			fhl[x].push_back(fh[l][0]+1);
			bd2(l,max(cw,fh[x][fh[l][0]+1==fh[x][0]])+1);
		}
		else
		{
			fhl[x].push_back(cw);
		}
	}
}

int main()
{
	long long i,j,r,ii,k,l,w,sz,ll,ww,szz,mx,p;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	bd(1);
	vtd.reset();
	bd2(1,0);
	for(i=1;i<=n;i++)
	{
		nn=0;
		nn2=0;
		sz=al[i].size();
		for(j=0;j<sz;j++)
		{
			l=al[i][j];
			w=fhl[i][j];
			nn++;
			ca[nn]=w;
			if(l!=pr[i])
			{
				szz=al[l].size();
				for(r=0;r<szz;r++)
				{
					ll=al[l][r];
					ww=fhl[l][r];
					if(ll!=i)
					{
						nn2++;
						ca2[nn2]={ww,l};
					}
				}
			}
		}
		sort(ca+1,ca+nn+1,greater<long long>());
		ca[0]=n+1;
		sort(ca2+1,ca2+nn2+1,greater<pair<long long,long long>>());
		mx=0;
		for(p=0,r=1,j=1;j<=nn+1;j++)
		{
			if(j<=nn)
			{
				sq[0][ca[j]]=max(sq[0][ca[j]],j);
				k=min(ca[j],ca[j-1]-1);
				sq[1][k]=max(sq[1][k],j);
			}
			for(;r<=nn2&&(j>nn||ca2[r].fr>=ca[j]);r++)
			{
				ww=ca2[r].fr;
				l=ca2[r].sc;
				fq[l]++;
				mx=max(mx,fq[l]-1);
				for(;p<nn&&ca[p+1]>=ww;p++);
				sq[0][ww]=max(sq[0][ww],fq[l]+p-(ww<=fh[l][0]+1));
			}
			if(j<=nn)
			{
				sq[0][ca[j]]=max(sq[0][ca[j]],j+mx);
			}
		}
		sq[1][0]=max(sq[1][0],nn+1);
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=n;i;i--)
		{
			sq[ii][i]=max(sq[ii][i],sq[ii][i+1]);
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",max(sq[i%2][i/2],1ll)," \n"[i==n]);
	}
}