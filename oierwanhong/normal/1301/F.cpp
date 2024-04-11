//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
typedef int ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
bool umax(ll& a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
bool umin(ll& a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}
ll abs(ll x)
{
	return x>0?x:-x;
}

/**********/
#define MAXN 1011
#define MAXK 41
std::vector<pll>g[MAXK];
ll a[MAXN][MAXN],dis[MAXK][MAXN][MAXN];
ll n,m,col;
bool viscol[MAXK];
std::queue<pll>q;
const ll mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
void bfs(ll k)
{
	memset(viscol,0,sizeof viscol);
	for(ll i=0;i<g[k].size();++i)
	{
		ll x=g[k][i].first,y=g[k][i].second;
		dis[k][x][y]=0;
		q.push(pll(x,y));
	}
	viscol[k]=1;
	while(!q.empty())
	{
		ll x=q.front().first,y=q.front().second;q.pop();
		ll c=a[x][y],cur=dis[k][x][y];
		if(!viscol[c])
		{
			viscol[c]=1;
			for(ll i=0;i<g[c].size();++i)
			{
				ll vx=g[c][i].first,vy=g[c][i].second;
				if(dis[k][vx][vy]<0)
				{
					dis[k][vx][vy]=cur+1;
					q.push(pll(vx,vy));
				}
			}
		}
		for(ll i=0;i<4;++i)
		{
			ll vx=x+mx[i],vy=y+my[i];
			if(vx>0&&vx<=n&&vy>0&&vy<=m&&dis[k][vx][vy]<0)
			{
				dis[k][vx][vy]=cur+1;
				q.push(pll(vx,vy));
			}
		}
	}
}
int main()
{
	memset(dis,-1,sizeof dis);
	n=read(),m=read(),col=read();
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=m;++j)
		{
			ll x=read();
			a[i][j]=x;
			g[x].push_back(pll(i,j));
		}
	for(ll i=1;i<=col;++i)
	{
		bfs(i);
		/*
		printf("col %d:\n",i);
		for(ll x=1;x<=n;++x)
		{
			for(ll y=1;y<=m;++y)
				printf("%d ",dis[i][x][y]);
			putchar('\n');
		}
		*/
	}
	ll task=read();
	while(task--)
	{
		ll x1=read(),y1=read(),x2=read(),y2=read();
		ll ans=abs(x1-x2)+abs(y1-y2);
		for(ll i=1;i<=col;++i)
			umin(ans,dis[i][x1][y1]+dis[i][x2][y2]+1);
		printf("%d\n",ans);
	}
	return 0;
}