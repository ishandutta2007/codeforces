#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n[3],a[3][169],faf[169],sq[169],zs;
pair<pair<long long,long long>,pair<long long,long long>> dp[169][169][169];

int main()
{
	long long i,j,r,ii,jj,rr,p,mx,e;
	string s;
	pair<long long,long long> mxe={-1e18,-1};
	
	for(ii=0;ii<3;ii++)
	{
		cin>>s;
		n[ii]=s.length();
		for(i=1;i<=n[ii];i++)
		{
			a[ii][i]=s[i-1]-'A';
		}
	}
	faf[0]=-1;
	for(i=1;i<=n[2];i++)
	{
		for(j=i-1;j&&a[2][faf[j]+1]!=a[2][i];j=faf[j]);
		faf[i]=faf[j]+1;
	}
	for(i=0;i<=n[0];i++)
	{
		for(j=0;j<=n[1];j++)
		{
			for(r=0;r<n[2];r++)
			{
				dp[i][j][r]={{-1e18,-1},{-1,-1}};
			}
		}
	}
	dp[0][0][0].fr.fr=0;
	for(i=0;i<=n[0];i++)
	{
		for(j=0;j<=n[1];j++)
		{
			for(r=0;r<n[2];r++)
			{
				dp[i+1][j][r]=max(dp[i+1][j][r],{{dp[i][j][r].fr.fr,r},{i,j}});
				dp[i][j+1][r]=max(dp[i][j+1][r],{{dp[i][j][r].fr.fr,r},{i,j}});
				if(a[0][i+1]==a[1][j+1])
				{
					for(p=r;p>=0&&a[2][p+1]!=a[0][i+1];p=faf[p]);
					p++;
					if(p<n[2])
					{
						dp[i+1][j+1][p]=max(dp[i+1][j+1][p],{{dp[i][j][r].fr.fr+1,r},{i,j}});
					}
				}
			}
		}
	}
	for(i=0;i<n[2];i++)
	{
		mxe=max(mxe,{dp[n[0]][n[1]][i].fr.fr,i});
	}
	mx=mxe.fr;
	e=mxe.sc;
	zs=mx;
	for(i=n[0],j=n[1],r=e;i||j||r;i=ii,j=jj,r=rr)
	{
		ii=dp[i][j][r].sc.fr;
		jj=dp[i][j][r].sc.sc;
		rr=dp[i][j][r].fr.sc;
		if(ii!=i&&jj!=j)
		{
			sq[zs]=a[0][i];
			zs--;
		}
	}
	if(!mx)
	{
		printf("0");
	}
	for(i=1;i<=mx;i++)
	{
		printf("%c",(char)sq[i]+'A');
	}
	printf("\n");
}