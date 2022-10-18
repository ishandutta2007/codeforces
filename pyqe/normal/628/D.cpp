#include <bits/stdc++.h>

using namespace std;

int n,m,d,a[2069],dp[2][2069][2],dv=1e9+7;

int main()
{
	int rr,i,j,r,ii,iii,tg,ub,z=0;
	string s;
	
	scanf("%d%d",&m,&d);
	for(rr=0;rr<2;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'0';
		}
		if(!rr)
		{
			a[n]--;
			for(i=n;a[i]==-1;i--)
			{
				a[i]+=10;
				a[i-1]--;
			}
		}
		for(ii=0;ii<2;ii++)
		{
			for(i=0;i<m;i++)
			{
				for(iii=0;iii<2;iii++)
				{
					dp[ii][i][iii]=0;
				}
			}
		}
		dp[0][0][0]=1;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<m;j++)
			{
				for(ii=0;ii<2;ii++)
				{
					ub=9;
					if(!ii)
					{
						ub=a[i];
					}
					for(r=0;r<=ub;r++)
					{
						tg=(j*10+r)%m;
						dp[1][tg][ii||r<a[i]]=(dp[1][tg][ii||r<a[i]]+dp[0][j][ii]*(i%2^r==d))%dv;
					}
				}
			}
			for(j=0;j<m;j++)
			{
				for(ii=0;ii<2;ii++)
				{
					dp[0][j][ii]=dp[1][j][ii];
					dp[1][j][ii]=0;
				}
			}
		}
		z=((dp[0][0][0]+dp[0][0][1])%dv+dv-z)%dv;
	}
	printf("%d\n",z);
}