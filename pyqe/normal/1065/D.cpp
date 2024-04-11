#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,inf=1e18;
pair<long long,long long> pst[169],nr[69][69][3];
queue<pair<pair<long long,long long>,long long>> q;
bitset<69> vtd[4];

int main()
{
	long long rr,i,j,r,ii,u,k,y,x,yy,xx,im,vy[8]={-2,-2,-1,1,2,2,1,-1},vx[8]={-1,1,2,2,1,-1,-2,-2};
	pair<long long,long long> w,ww,z={inf,inf};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lld",&k);
			pst[k]={i,j};
		}
	}
	for(rr=2;rr<=n*n;rr++)
	{
		y=pst[rr-1].fr;
		x=pst[rr-1].sc;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i!=y||j!=x)
				{
					for(r=0;r<3;r++)
					{
						nr[i][j][r]={inf,inf};
					}
				}
			}
		}
		for(i=0;i<4;i++)
		{
			vtd[i].reset();
		}
		for(i=0;i<3;i++)
		{
			q.push({{y,x},i});
		}
		for(;!q.empty();)
		{
			y=q.front().fr.fr;
			x=q.front().fr.sc;
			k=q.front().sc;
			w=nr[y][x][k];
			q.pop();
			ww={w.fr+1,w.sc+1};
			for(i=0;i<3;i++)
			{
				if(nr[y][x][i].fr==inf)
				{
					q.push({{y,x},i});
				}
				nr[y][x][i]=min(nr[y][x][i],ww);
			}
			ww.sc--;
			if(!k)
			{
				for(im=0;im<8;im++)
				{
					yy=y+vy[im];
					xx=x+vx[im];
					if(yy>0&&xx>0&&yy<=n&&xx<=n)
					{
						if(nr[yy][xx][k].fr==inf)
						{
							q.push({{yy,xx},k});
						}
						nr[yy][xx][k]=min(nr[yy][xx][k],ww);
					}
				}
			}
			else if(k==1)
			{
				for(ii=0;ii<2;ii++)
				{
					u=!ii*2-1;
					if(!vtd[ii][y-x*u+n])
					{
						for(i=1;i<=n;i++)
						{
							yy=y+(i-x)*u;
							xx=i;
							if(yy>0&&yy<=n)
							{
								if(nr[yy][xx][k].fr==inf)
								{
									q.push({{yy,xx},k});
								}
								nr[yy][xx][k]=min(nr[yy][xx][k],ww);
							}
						}
						vtd[ii][y-x*u+n]=1;
					}
				}
			}
			else if(k==2)
			{
				for(ii=0;ii<2;ii++)
				{
					if(!vtd[2+ii][y])
					{
						for(i=1;i<=n;i++)
						{
							yy=y;
							xx=i;
							if(ii)
							{
								swap(yy,xx);
							}
							if(nr[yy][xx][k].fr==inf)
							{
								q.push({{yy,xx},k});
							}
							nr[yy][xx][k]=min(nr[yy][xx][k],ww);
						}
						vtd[2+ii][y]=1;
					}
					swap(y,x);
				}
			}
		}
		y=pst[rr].fr;
		x=pst[rr].sc;
	}
	y=pst[n*n].fr;
	x=pst[n*n].sc;
	for(i=0;i<3;i++)
	{
		z=min(z,nr[y][x][i]);
	}
	printf("%lld %lld\n",z.fr,z.sc);
}