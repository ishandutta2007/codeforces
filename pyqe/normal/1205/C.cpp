#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
bitset<69> sq[69],vtd[69];
queue<pair<long long,long long>> q;

void ad(long long y,long long x,long long w)
{
	sq[y][x]=w;
	q.push({y,x});
	vtd[y][x]=1;
}

void bfs()
{
	long long k,y,x,yy,xx,im,vy[6]={-2,-1,0,2,1,0},vx[6]={0,-1,-2,0,1,2};
	
	for(;!q.empty();)
	{
		y=q.front().fr;
		x=q.front().sc;
		q.pop();
		for(im=0;im<6;im++)
		{
			yy=y+vy[im];
			xx=x+vx[im];
			if(yy>0&&xx>0&&yy<=n&&xx<=n&&!vtd[yy][xx])
			{
				printf("? %lld %lld %lld %lld\n",min(y,yy),min(x,xx),max(y,yy),max(x,xx));
				fflush(stdout);
				scanf("%lld",&k);
				ad(yy,xx,sq[y][x]^!k);
			}
		}
	}
}

int main()
{
	long long i,j,u,k,kk,p;
	
	scanf("%lld",&n);
	ad(1,1,1);
	ad(n,n,0);
	bfs();
	for(p=1;!sq[p][p]||sq[p+2][p+2];p+=2);
	printf("? %lld %lld %lld %lld\n",p+1,p,p+2,p+1);
	fflush(stdout);
	scanf("%lld",&k);
	u=k^sq[p+2][p];
	printf("? %lld %lld %lld %lld\n",p+u,p,p+2,p+1+u);
	fflush(stdout);
	scanf("%lld",&k);
	ad(p+1,p,sq[p+2][p+2*u]^!k);
	ad(p+2,p+1,sq[p+2*u][p]^!k);
	bfs();
	printf("!\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d",(bool)sq[i][j]);
		}
		printf("\n");
	}
	fflush(stdout);
}