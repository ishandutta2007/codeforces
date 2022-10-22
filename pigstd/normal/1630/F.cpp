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

const int M=2e5+10;
const int N=3e6+10;
int n,a[M],T[M],s,t;
vector<int>d[M];

void init(int n)
{
	for (int i=1;i<=n;i++)
		for (int j=i*2;j<=n;j+=i)d[j].pb(i);
}

const int inf=1e18;
int de[M],cur[M];
struct edge{int to,next,w;}e[N<<1];int cnt=1,head[M];
void add(int u,int to,int w){e[++cnt].to=to,e[cnt].w=w,e[cnt].next=head[u],head[u]=cnt;assert(cnt<=2*N);}
void adde(int u,int to,int w){add(u,to,w),add(to,u,0);}

int bfs(int s,int t)
{
	for (int i=1;i<=4*n+2;i++)de[i]=0,cur[i]=head[i];
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

void add(int x,int y){adde(x,y+2*n,1),adde(x+n,y+3*n,1),adde(x,y+3*n,1);}

void clear()
{
	memset(head,0,sizeof(head));
	for (int i=0;i<=cnt;i++)e[i].to=e[i].w=e[i].next=0;
	cnt=1;
}

void solve()
{
	n=read();s=4*n+1,t=s+1; 
	for (int i=1;i<=n;i++)T[a[i]=read()]=i;
	for (int i=1;i<=n;i++)
		for (auto x:d[a[i]])
			if (T[x])add(T[x],i);
//	puts("qwq");
	for (int i=1;i<=n;i++)adde(i,i+3*n,1),adde(s,i,1),adde(i+2*n,t,1),adde(s,i+n,1),adde(i+3*n,t,1);
	cout<<dinic(s,t)-n<<'\n';
	for (int i=1;i<=n;i++)T[a[i]]=0;clear();
}

signed main()
{
	init(5e4);
	WT solve();
	return 0;
}