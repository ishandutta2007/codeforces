#include <bits/stdc++.h>

using namespace std;

long long n,m,a[3],sq[169][169];
string ky[6]={".//#","\\.#\\","\\#.\\","#//.","####","...."};

int main()
{
	long long i,j,p,k;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<3;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			p=i*m+j;
			if(p<a[0])
			{
				sq[i][j]=4;
			}
			else if(p<a[0]+m)
			{
				if(j>=a[0]%m)
				{
					sq[i][j]=2+(j-a[0]%m+1)%2;
				}
				else
				{
					sq[i][j]=2+(a[0]%m-j)%2;
				}
			}
			else
			{
				sq[i][j]=5;
			}
		}
	}
	a[2]-=m;
	for(i=a[0]/m+1;i<n-1;i+=2)
	{
		k=min(a[2]/2,m-a[0]%m);
		a[2]-=k*2;
		sq[i][m-k]=0;
	}
	for(i=a[0]/m+2;i<n-1;i+=2)
	{
		k=min(a[2]/2,a[0]%m);
		a[2]-=k*2;
		sq[i][k-1]=1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(i&&sq[i-1][j]<2)
			{
				sq[i][j]=sq[i-1][j]+2;
			}
			else if(j>a[0]%m&&sq[i][j-1]<2)
			{
				sq[i][j]=!sq[i][j-1];
			}
		}
		for(j=m-1;j+1;j--)
		{
			if(j<a[0]%m-1&&sq[i][j+1]<2)
			{
				sq[i][j]=!sq[i][j+1];
			}
		}
	}
	if(a[2])
	{
		if(sq[n-1][0]==5)
		{
			for(i=0;i<a[2];i++)
			{
				sq[n-1][i]=(a[2]-i)%2;
			}
		}
		else
		{
			for(i=0;i<a[2];i++)
			{
				sq[n-1][m-1-i]=(a[2]-i-1)%2;
			}
		}
	}
	for(i=0;i<n*2;i++)
	{
		for(j=0;j<m*2;j++)
		{
			printf("%c",ky[sq[i/2][j/2]][i%2*2+j%2]);
		}
		printf("\n");
	}
}