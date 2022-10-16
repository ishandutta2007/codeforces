#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long vy[4]={-1,0,1,0},vx[4]={0,1,0,-1},inf=1e18;
const string ky="URDL";
long long n,m,nn,yk[26],a[2069][2069],dp[2069][2069];
bitset<2069> vtd[2069],vtd2[2069];
pair<long long,long long> ca[4000069];

int main()
{
	long long t,rr,i,j,r,k,y,x,yy,xx;
	pair<long long,pair<long long,long long>> mxe;
	char ch;
	
	for(i=0;i<4;i++)
	{
		yk[ky[i]-'A']=i;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf(" %c",&ch);
				a[i][j]=yk[ch-'A'];
				vtd[i][j]=0;
			}
		}
		mxe={-inf,{-1,-1}};
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(!vtd[i][j])
				{
					nn=0;
					for(y=i,x=j;1;y=yy,x=xx)
					{
						nn++;
						ca[nn]={y,x};
						if(vtd[y][x])
						{
							break;
						}
						vtd[y][x]=1;
						vtd2[y][x]=1;
						yy=min(max(y+vy[a[y][x]],1ll),n);
						xx=min(max(x+vx[a[y][x]],1ll),m);
					}
					if(!vtd2[y][x])
					{
						for(r=nn-1;r;r--)
						{
							y=ca[r].fr;
							x=ca[r].sc;
							yy=ca[r+1].fr;
							xx=ca[r+1].sc;
							dp[y][x]=dp[yy][xx]+1;
						}
					}
					else
					{
						for(r=1;ca[r]!=ca[nn];r++);
						k=r;
						for(;r<=nn;r++)
						{
							y=ca[r].fr;
							x=ca[r].sc;
							dp[y][x]=nn-k;
						}
						for(r=k-1;r;r--)
						{
							y=ca[r].fr;
							x=ca[r].sc;
							yy=ca[r+1].fr;
							xx=ca[r+1].sc;
							dp[y][x]=dp[yy][xx]+1;
						}
					}
					for(r=1;r<=nn;r++)
					{
						y=ca[r].fr;
						x=ca[r].sc;
						vtd2[y][x]=0;
					}
				}
				mxe=max(mxe,{dp[i][j],{i,j}});
			}
		}
		printf("%lld %lld %lld\n",mxe.sc.fr,mxe.sc.sc,mxe.fr);
	}
}