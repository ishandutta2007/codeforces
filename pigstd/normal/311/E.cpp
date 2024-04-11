#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int inf=1e18;
const int M=12010;
const int N=4e4+10; 
int de[M],cur[M],n,m,v[M],a[M],g;
struct edge{int to,next,w;}e[N<<1];int cnt=1,head[M];
void add(int u,int to,int w){e[++cnt].to=to,e[cnt].w=w,e[cnt].next=head[u],head[u]=cnt;}
void adde(int u,int to,int w){add(u,to,w),add(to,u,0);}

int bfs(int s,int t)
{
	memset(de,0,sizeof(de));
	memcpy(cur,head,sizeof(cur));
	queue<int>q;q.push(s),de[s]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for (int i=head[u];i;i=e[i].next)
		{
			int to=e[i].to;
			if (de[to]||!e[i].w)continue;
			de[to]=de[u]+1,q.push(to);
		}
	}
	return de[t]!=0;
}

int dfs(int s,int t,int now)
{
	if (s==t)return now;int res=0;
	for (int i=cur[s];i;i=e[i].next)
	{
		int to=e[i].to;cur[s]=i;
		if (de[to]!=de[s]+1)continue;
		int x=dfs(to,t,min(now,e[i].w));
		res+=x,now-=x,e[i].w-=x,e[i^1].w+=x;
		if (now==0)break;
	}return res;
}

int dinic(int s,int t)
{
	int res=0;
	while(bfs(s,t))res+=dfs(s,t,inf);
	return res;
}


signed main()
{
	n=read(),m=read(),g=read();
	int s=n+m+1,t=s+1,res=0;
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)
	{
		v[i]=read();
		if (a[i])adde(i,t,v[i]);
		else adde(s,i,v[i]);
	}
	for (int i=1;i<=m;i++)
	{
		int num=read(),w=read(),k=read();res+=w;
		for (int j=1;j<=k;j++)
			if (num)adde(read(),i+n,inf);
			else adde(i+n,read(),inf);
		w+=read()*g;
		if (num)adde(i+n,t,w);
		else adde(s,i+n,w);
	}
//	cout<<res<<endl;
	res-=dinic(s,t);
	cout<<res<<endl;
	return 0;
}