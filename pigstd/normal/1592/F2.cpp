#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e9;
const int M=510;
int n,m,b[M][M],a[M][M],ans,s,t;

struct node
{
	int to,w,next;
}e[M*M*3];int head[M<<1],cnt=1;
void add(int u,int to,int w){e[++cnt].to=to,e[cnt].next=head[u],e[cnt].w=w,head[u]=cnt;}
int de[M<<1],cur[M<<1];
bool bfs(int s,int t)
{
    memset(de,0,sizeof(de));
	memcpy(cur,head,sizeof(cur));
	queue<int> q;
	de[s]=1,q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for (int i=head[u];i;i=e[i].next)
		{
			int to=e[i].to;
			if (de[to]==0&&e[i].w)
				de[to]=de[u]+1,q.push(to);
		}
	}
	return de[t]!=0;
}

int dfs(int u,int t,int minn)
{
	if (!minn||u==t)return minn;
	int rest=0;
	for (int i=cur[u];i;i=e[i].next)
	{
		int to=e[i].to;
		cur[u]=i;
		if (de[to]!=de[u]+1)continue;
		int flow=dfs(to,t,min(minn,e[i].w));
		if (!flow)continue;
		rest+=flow,minn-=flow,e[i].w-=flow,e[i^1].w+=flow;
		if (!minn)break;
	}
	return rest;
}

int dinic(int s,int t)
{
	int maxflow=0;
	while(bfs(s,t))maxflow+=dfs(s,t,inf);
	return maxflow;
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		string s;cin>>s;
		for (int j=1;j<=m;j++)a[i][j]=s[j-1]=='B';
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			b[i][j]=a[i][j]^a[i][j+1]^a[i+1][j]^a[i+1][j+1];
	for (int i=1;i<n;i++)
		for (int j=1;j<m;j++)
			if (b[i][j]&&b[i][m]&&b[n][j])
				add(i,j+n-1,1),add(j+n-1,i,0);//,cout<<i<<' '<<j<<endl;
	int s=n+m-1,t=s+1;
	for (int i=1;i<n;i++)
		add(s,i,1),add(i,s,0);
	for (int i=1;i<m;i++)
		add(i+n-1,t,1),add(t,i+n-1,0);
	int x=dinic(s,t);
	b[n][m]^=(x&1);int ans=-x;//cout<<x<<endl;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)ans+=b[i][j];
	cout<<ans<<endl;
	return 0;
}