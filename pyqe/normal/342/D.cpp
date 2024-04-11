#include <bits/stdc++.h>

using namespace std;

long long n,ys,xs,vy[4]={-1,0,1,0},vx[4]={0,1,0,-1},dp[2][1ll<<3],dv=1e9+7;
bitset<3> a[10069];

int main()
{
	long long i,j,ii,im,u,mk,yy,xx,mk2,mk3,z=0;
	char ch;
	
	scanf("%lld",&n);
	for(i=0;i<3;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf(" %c",&ch);
			a[j][i]=ch!='.';
			if(ch=='O')
			{
				ys=j;
				xs=i;
			}
		}
	}
	for(mk=1;mk<1ll<<4;mk++)
	{
		u=__builtin_popcount(mk)%2*2-1;
		for(im=0;im<4;im++)
		{
			if(mk>>im&1)
			{
				for(ii=0;ii<2;ii++)
				{
					yy=ys+vy[im]*(1+ii);
					xx=xs+vx[im]*(1+ii);
					if(yy<1||yy>n||xx<0||xx>=3||a[yy][xx])
					{
						break;
					}
				}
				if(ii<2)
				{
					break;
				}
			}
		}
		if(im<4)
		{
			continue;
		}
		for(im=0;im<4;im++)
		{
			if(mk>>im&1)
			{
				for(ii=0;ii<2;ii++)
				{
					yy=ys+vy[im]*(1+ii);
					xx=xs+vx[im]*(1+ii);
					a[yy][xx]=1;
				}
			}
		}
		for(mk2=0;mk2<1ll<<3;mk2++)
		{
			dp[0][mk2]=0;
		}
		dp[0][(1ll<<3)-1]=1;
		for(i=1;i<=n;i++)
		{
			for(mk2=0;mk2<1ll<<3;mk2++)
			{
				for(j=-1;j<2;j++)
				{
					if(j==-1||(mk2>>j&3)==3)
					{
						mk3=mk2^(3ll<<j)*(j!=-1);
						dp[1][mk2]=(dp[1][mk2]+dp[0][(1ll<<3)-1^mk3])%dv;
					}
				}
			}
			for(mk2=0;mk2<1ll<<3;mk2++)
			{
				dp[0][mk2]=dp[1][mk2];
				dp[1][mk2]=0;
			}
			for(mk2=0;mk2<1ll<<3;mk2++)
			{
				mk3=mk2;
				for(j=0;j<3;j++)
				{
					mk3^=(long long)a[i][j]<<j;
				}
				dp[1][mk3]=dp[0][mk2]*((mk3&mk2)==mk2);
			}
			for(mk2=0;mk2<1ll<<3;mk2++)
			{
				dp[0][mk2]=dp[1][mk2];
				dp[1][mk2]=0;
			}
		}
		z=(z+dv+dp[0][(1ll<<3)-1]*u)%dv;
		for(im=0;im<4;im++)
		{
			if(mk>>im&1)
			{
				for(ii=0;ii<2;ii++)
				{
					yy=ys+vy[im]*(1+ii);
					xx=xs+vx[im]*(1+ii);
					a[yy][xx]=0;
				}
			}
		}
	}
	printf("%lld\n",z);
}