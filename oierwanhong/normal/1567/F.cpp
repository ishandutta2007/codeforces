#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 500011;
const int mx[]={0,1,0,-1},my[]={1,0,-1,0};
std::vector<int>g[MAXN];
void diff(int x,int y,int k){g[x].push_back(y+k),g[y].push_back(x+k),g[x+k].push_back(y),g[y+k].push_back(x);}
int dfn[MAXN],low[MAXN],cur=0,scc[MAXN],scnt=0, s[MAXN],top=0;
bool ins[MAXN];
void tarjan(int u)
{
	dfn[u]=low[u]=++cur,s[++top]=u,ins[u]=1;
	for(auto v:g[u])
		if(!dfn[v])
		{
			tarjan(v),umin(low[u],low[v]);
		}
		else if(ins[v])umin(low[u],dfn[v]);
	if(dfn[u]==low[u])
	{
		++scnt;
		while(s[top]!=u)scc[s[top]]=scnt,ins[s[top]]=0,--top;
		scc[s[top]]=scnt,ins[s[top]]=0,--top;
	}
}
char a[511][511];
int main()
{
	int n=read(),m=read(),all=2*n*m;
	for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
	for(int x=2;x<n;++x)
		for(int y=2;y<m;++y)
			if(a[x][y]=='X')
			{
				int cnt=0;
				for(int i=0;i<4;++i)
				{
					int vx=x+mx[i],vy=y+my[i];
					if(a[vx][vy]=='.')++cnt;
				}
				if(cnt&1){puts("NO");return 0;}
				if(cnt==0)continue;
				if(cnt==2)
				{
					int lst=0;
					for(int i=0;i<4;++i)
					{
						int vx=x+mx[i],vy=y+my[i],cur=(vx-1)*m+vy;
						if(a[vx][vy]=='.')
						{
							if(lst)diff(lst,cur,n*m);
							else lst=cur;
						}
					}
				}
				if(cnt==4)
				{
					int cur=(x-1)*m+y;
					diff(cur-m,cur+1,n*m),diff(cur+1,cur+m,n*m),diff(cur+m,cur-1,n*m),diff(cur-1,cur-m,n*m);
				}
			}
	for(int i=1;i<=all;++i)
		if(!dfn[i])tarjan(i);
	puts("YES");
	for(int x=1;x<=n;++x,puts(""))
		for(int y=1;y<=m;++y)
			if(a[x][y]=='X')
			{
				int cnt=0;
				for(int i=0;i<4;++i)
				{
					int vx=x+mx[i],vy=y+my[i];
					if(a[vx][vy]=='.')++cnt;
				}
				printf("%d ",(cnt>>1)*5);
			}
			else
			{
				int cur=(x-1)*m+y;
				if(scc[cur]==scc[cur+n*m]){fprintf(stderr,"ERR! No solution!");exit(-5);}
				printf("%d ",scc[cur]<scc[cur+n*m]?1:4);
			}
	return 0;
}
/*
.........
.XXXXX.X.
.X...X...
.X.XXXXX.
.X.X.X.X.
.X.XXX.X.
.X.....X.
.XXXXXXX.
.........
*/