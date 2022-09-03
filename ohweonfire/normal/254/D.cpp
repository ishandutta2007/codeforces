#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <queue>
#include <map>
#include <deque>
using namespace std;
#define point pair<int,int>
#define x first
#define y second
#define mtr(x,y,z) make_pair(make_pair((x),(y)),(z))
#define mp make_pair
#define pb push_back
using namespace std;
const int maxn=1005;
char inp[maxn][maxn];
vector<point> rats;
vector<bool> killed;
bool vis[22][22];
int d;
void bfs(point &begin)
{
	memset(vis,0,sizeof(vis));
	queue<pair<point,int> > bq;
	bq.push(mp(begin,d));
	while(!bq.empty())
	{
		point a=bq.front().x;
		int dist=bq.front().y;
		bq.pop();
		if(inp[a.x][a.y]=='X')
			continue;
		if(vis[a.x-begin.x+10][a.y-begin.y+10])continue;
		vis[a.x-begin.x+10][a.y-begin.y+10]=true;
		if(dist)
		{
			bq.push(mtr(a.x+1,a.y,dist-1));
			bq.push(mtr(a.x-1,a.y,dist-1));
			bq.push(mtr(a.x,a.y+1,dist-1));
			bq.push(mtr(a.x,a.y-1,dist-1));
		}
	}
}
int main()
{
	#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n,m;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=0;i<n;i++)
	{
		scanf("%s",inp[i]);
		for(int j=0;j<m;j++)
			if(inp[i][j]=='R')
			{
				rats.pb(mp(i,j));
				killed.pb(0);
			}
	}
	if(rats.size()>500)
	{
		puts("-1");
		return 0;
	}
	bfs(rats[0]);
	vector<point> g1,g2;
	for(int i=0;i<22;i++)
		for(int j=0;j<22;j++)
			if(vis[i][j])
				g1.push_back(mp(i+rats[0].x-10,j+rats[0].y-10));
	for(int I=0;I<g1.size();I++)
	{
		point m1=g1[I];
		if(inp[m1.x][m1.y]=='X')
			continue;
		bfs(m1);
		g2.clear();
		bool live=0;
		point mouse;
		for(int i=0;i<rats.size();i++)
			if(rats[i].x-m1.x>-10&&rats[i].x-m1.x<10&&rats[i].y-m1.y>-10&&rats[i].y-m1.y<10&&vis[rats[i].x-m1.x+10][rats[i].y-m1.y+10])
				killed[i]=true;
			else
			{
				live=true;
				mouse=rats[i];
				killed[i]=false;
			}
		if(!live)
		{
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					if(inp[i][j]!='X'&&(i!=m1.x||j!=m1.y))
					{
						printf("%d %d %d %d\n",m1.x+1,m1.y+1,i+1,j+1);
						return 0;
					}
		}
		else
		{
			bfs(mouse);
			for(int i=0;i<22;i++)
				for(int j=0;j<22;j++)
					if(vis[i][j])
						g2.push_back(mp(i+mouse.x-10,j+mouse.y-10));
			for(int T=0;T<g2.size();T++)
			{
				point m2=g2[T];
				if(inp[m2.x][m2.y]=='X')
					continue;
				if(m1==m2)
					continue;
				bfs(m2);
				bool good=true;
				for(int i=0;i<rats.size();i++)
					if(!(rats[i].x-m2.x>-10&&rats[i].x-m2.x<10&&rats[i].y-m2.y>-10&&rats[i].y-m2.y<10&&vis[rats[i].x-m2.x+10][rats[i].y-m2.y+10]||killed[i]))
					{
						good=false;
						break;
					}
				if(good)
				{
					printf("%d %d %d %d\n",m1.x+1,m1.y+1,m2.x+1,m2.y+1);
					return 0;
				}
			}
		}
	}
	puts("-1");
	return 0;
}