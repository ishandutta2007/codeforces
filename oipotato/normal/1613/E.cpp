#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=1000010;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
char s[N];
int n,m,x,y;
queue<pair<int,int>>q;
vector<bool>can[N],ok[N];
vector<int>deg[N];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d",&n,&m);
		rep(i,n)
		{
			ok[i].resize(m+1);
			can[i].resize(m+1);
			deg[i].resize(m+1);
			scanf("%s",s+1);
			rep(j,m)
			{
				deg[i][j]=0;can[i][j]=0;
				if(s[j]=='#')ok[i][j]=0;
				else ok[i][j]=1;
				if(s[j]=='L')x=i,y=j;
			}
		}
		rep(i,n)rep(j,m)if(ok[i][j])for(int k=0;k<4;k++)
		{
			int nx=i+dx[k],ny=j+dy[k];
			if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&ok[nx][ny])deg[i][j]++;
		}
		q.push(mp(x,y));deg[x][y]=0;can[x][y]=1;
		for(;!q.empty();q.pop())
		{
			auto u=q.front();
			for(int k=0;k<4;k++)
			{
				int nx=u.first+dx[k],ny=u.second+dy[k];
				if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&ok[nx][ny])
				{
					deg[nx][ny]--;
					if(deg[nx][ny]<=1&&!can[nx][ny])q.push(mp(nx,ny)),can[nx][ny]=1;
				}
			}
		}
		rep(i,n)
		{
			rep(j,m)if(x==i&&y==j)putchar('L');else if(can[i][j])putchar('+');else if(ok[i][j])putchar('.');else putchar('#');
			puts("");
		}
	}
    return 0;
}