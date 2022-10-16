#include <bits/stdc++.h>

using namespace std;

long long n,m,b[2][569][569];
bitset<569> a[2][569];
string s[569];

int main()
{
	long long i,j,it,t,r,y1,x1,y2,x2;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(j>0&&s[i][j-1]=='.'&&s[i][j]=='.')
			{
				a[0][i+1][j+1]=true;
			}
			if(i>0&&s[i-1][j]=='.'&&s[i][j]=='.')
			{
				a[1][i+1][j+1]=true;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			for(it=0;it<2;it++)
			{
				b[it][i][j]=a[it][i][j]+b[it][i-1][j]+b[it][i][j-1]-b[it][i-1][j-1];
			}
		}
	}
	scanf("%lld",&t);
	for(r=0;r<t;r++)
	{
		scanf("%lld%lld%lld%lld",&y1,&x1,&y2,&x2);
		{
			printf("%lld\n",b[0][y2][x2]-b[0][y1-1][x2]-b[0][y2][x1]+b[0][y1-1][x1]+b[1][y2][x2]-b[1][y1][x2]-b[1][y2][x1-1]+b[1][y1][x1-1]);
		}
	}
}