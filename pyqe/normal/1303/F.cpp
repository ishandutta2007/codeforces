#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,ls[369][369],sq[2000069];
vector<pair<long long,pair<long long,long long>>> qq[2000069][2];
pair<long long,long long> dsu[369][369];
bitset<369> vtd[369];

pair<long long,long long> fd(long long y,long long x)
{
	if(dsu[y][x]!=mp(y,x))
	{
		dsu[y][x]=fd(dsu[y][x].fr,dsu[y][x].sc);
	}
	return dsu[y][x];
}

int main()
{
	long long t,rr,i,j,ii,u,im,k,l,w,pz,sz,c,lc,yy,xx,vy[4]={-1,0,1,0},vx[4]={0,1,0,-1};
	pair<long long,long long> tmp;
	
	scanf("%lld%lld%lld",&n,&m,&t);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			dsu[i][j]={i,j};
			qq[0][0].push_back({0,{i,j}});
		}
	}
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		if(ls[k][l]<w)
		{
			qq[ls[k][l]][1].push_back({-rr,{k,l}});
			ls[k][l]=w;
			qq[w][0].push_back({rr,{k,l}});
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			qq[ls[i][j]][1].push_back({-t-1,{i,j}});
		}
	}
	for(i=0;i<=2000000;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			sort(qq[i][ii].begin(),qq[i][ii].end());
			sz=qq[i][ii].size();
			c=0;
			lc=0;
			for(j=0;j<sz;j++)
			{
				k=qq[i][ii][j].sc.fr;
				l=qq[i][ii][j].sc.sc;
				pz=qq[i][ii][j].fr*u;
				vtd[k][l]=1;
				c++;
				for(im=0;im<4;im++)
				{
					yy=k+vy[im];
					xx=l+vx[im];
					if(vtd[yy][xx]&&fd(yy,xx)!=fd(k,l))
					{
						tmp=fd(yy,xx);
						dsu[tmp.fr][tmp.sc]=fd(k,l);
						c--;
					}
				}
				sq[pz]+=(c-lc)*u;
				lc=c;
			}
			for(j=0;j<sz;j++)
			{
				k=qq[i][ii][j].sc.fr;
				l=qq[i][ii][j].sc.sc;
				vtd[k][l]=0;
				dsu[k][l]={k,l};
			}
		}
	}
	for(rr=1;rr<=t;rr++)
	{
		sq[rr]+=sq[rr-1];
		printf("%lld\n",sq[rr]);
	}
}