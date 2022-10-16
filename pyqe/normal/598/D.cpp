#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dp[1069][1069];
bitset<1069> a[1069];
pair<long long,long long> dsu[1069][1069];

pair<long long,long long> fd(long long x,long long y)
{
	if(dsu[x][y]!=mp(x,y))
	{
		dsu[x][y]=fd(dsu[x][y].fr,dsu[x][y].sc);
	}
	return dsu[x][y];
}

int main()
{
	long long t,rr,i,j,k,l,im,yy,xx,ky[4]={-1,0,1,0},kx[4]={0,1,0,-1};
	string s;
	pair<long long,long long> tmp;
	
	scanf("%lld%lld%lld",&n,&m,&t);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			a[i][j]=s[j-1]=='*';
			dsu[i][j]={i,j};
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(!a[i][j])
			{
				for(im=0;im<4;im++)
				{
					yy=i+ky[im];
					xx=j+kx[im];
					if(!a[yy][xx])
					{
						tmp=fd(yy,xx);
						dsu[tmp.fr][tmp.sc]=fd(i,j);
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(!a[i][j])
			{
				for(im=0;im<4;im++)
				{
					yy=i+ky[im];
					xx=j+kx[im];
					if(a[yy][xx])
					{
						tmp=fd(i,j);
						dp[tmp.fr][tmp.sc]++;
					}
				}
			}
		}
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		tmp=fd(k,l);
		printf("%lld\n",dp[tmp.fr][tmp.sc]);
	}
}