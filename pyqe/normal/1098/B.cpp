#include <bits/stdc++.h>

using namespace std;

long long n,m,yk[26],a[300069],tmp[300069],sq[300069],inf=1e18;
string ky="AGCT";

void mir(long long x[300069])
{
	long long i,j,p,pp;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			p=i*m+j;
			pp=j*n+i;
			tmp[pp]=x[p];
		}
	}
	for(i=0;i<n*m;i++)
	{
		x[i]=tmp[i];
	}
}

int main()
{
	long long i,j,ii,jj,p,w[4],c[2],e,sm,z=inf;
	char ch;
	
	for(i=0;i<4;i++)
	{
		yk[ky[i]-'A']=i;
	}
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf(" %c",&ch);
			p=i*m+j;
			a[p]=yk[ch-'A'];
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(w[0]=0;w[0]<4;w[0]++)
		{
			for(w[1]=w[0]+1;w[1]<4;w[1]++)
			{
				w[2]=-1;
				for(i=0;i<4;i++)
				{
					if(i!=w[0]&&i!=w[1])
					{
						w[2+(w[2]!=-1)]=i;
					}
				}
				sm=0;
				for(i=0;i<n;i++)
				{
					for(jj=0;jj<2;jj++)
					{
						c[jj]=0;
					}
					for(j=0;j<m;j++)
					{
						p=i*m+j;
						for(jj=0;jj<2;jj++)
						{
							c[jj]+=a[p]!=w[i%2*2+(j%2^jj)];
						}
					}
					e=c[1]<c[0];
					sm+=c[e];
					for(j=0;j<m;j++)
					{
						p=i*m+j;
						tmp[p]=w[i%2*2+(j%2^e)];
					}
				}
				if(sm<z)
				{
					z=sm;
					for(i=0;i<n*m;i++)
					{
						sq[i]=tmp[i];
					}
				}
			}
		}
		mir(a);
		mir(sq);
		swap(n,m);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			p=i*m+j;
			printf("%c",ky[sq[p]]);
		}
		printf("\n");
	}
}