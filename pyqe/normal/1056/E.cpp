#include <bits/stdc++.h>

using namespace std;

const long long dv[3]={(long long)1e9+7,(long long)1e9+9,(long long)1e9+21},iv[3]={576923081,807692315,423076932};
long long n,m,a[1000069],fq[2],pc[1000069][3],ipc[1000069][3],ps[1000069][3];
bitset<100069> ky;

array<long long,3> qr(long long lh,long long rh)
{
	long long i;
	array<long long,3> z;
	
	for(i=0;i<3;i++)
	{
		z[i]=(ps[rh][i]+dv[i]-ps[lh-1][i])*ipc[lh-1][i]%dv[i];
	}
	return z;
}

int main()
{
	long long i,j,ii,k,sz[2],p,ls[2],z=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		ky[i]=s[i-1]-'0';
		fq[ky[i]]++;
	}
	cin>>s;
	m=s.length();
	for(i=0;i<3;i++)
	{
		pc[0][i]=1;
		ipc[0][i]=1;
	}
	for(i=1;i<=m;i++)
	{
		a[i]=s[i-1]-'a';
		for(j=0;j<3;j++)
		{
			pc[i][j]=pc[i-1][j]*26%dv[j];
			ipc[i][j]=ipc[i-1][j]*iv[j]%dv[j];
			ps[i][j]=(ps[i-1][j]+a[i]*pc[i-1][j])%dv[j];
		}
	}
	for(i=1;i<=m;i++)
	{
		k=m-fq[0]*i;
		if(k<=0||k%fq[1])
		{
			continue;
		}
		sz[0]=i;
		sz[1]=k/fq[1];
		for(ii=0;ii<2;ii++)
		{
			ls[ii]=-1;
		}
		p=0;
		for(j=1;j<=n;j++)
		{
			p+=sz[ky[j]];
			if(ls[ky[j]]+1)
			{
				if(qr(p-sz[ky[j]]+1,p)!=qr(ls[ky[j]]-sz[ky[j]]+1,ls[ky[j]]))
				{
					break;
				}
			}
			ls[ky[j]]=p;
		}
		z+=(j>n)&&(sz[0]!=sz[1]||qr(ls[0]-sz[0]+1,ls[0])!=qr(ls[1]-sz[1]+1,ls[1]));
	}
	printf("%lld\n",z);
}