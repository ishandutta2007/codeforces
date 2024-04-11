#include<bits/stdc++.h>
#define int long long
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

const int M=250010;
int n,dp[M][2],X,out[M],vis[M];
vector<pair<int,int> >e[M];
pair<int,int>p[M];
bool cmp(pair<int,int>a,pair<int,int>b){return out[a.x]>out[b.x];}

struct heap
{
	priority_queue<int>q1,q2;
	int sz,sum;
	void add(int x){q1.push(x),sz++,sum+=x;}
	void del(int x){q2.push(x),sz--,sum-=x;}
	void pre(){while(q1.size()&&q2.size()&&q1.top()==q2.top())q1.pop(),q2.pop();}
	int size(){return sz;}
	int top(){pre();return q1.top();}
	void pop(){pre(),sz--,sum-=q1.top(),q1.pop();}
}h[M];

void del(int u)
{
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i].x,w=e[u][i].y;
		if (out[to]<=X)break;
		h[to].add(w);
	}
}

void dfs(int u,int fa)
{
	int num=out[u]-X,res=0;vis[u]=X;
	vector<int>v1,v2;v1.clear(),v2.clear();
	while(h[u].size()>num)h[u].pop();
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i].x,w=e[u][i].y;
		if (out[to]<=X)break;
		if (to==fa)continue;
		dfs(to,u);res+=dp[to][0];
		int x=dp[to][1]+w-dp[to][0];
		if (x<0)num--,res+=x;
		else h[u].add(x),v1.pb(x);
	}
	while(h[u].size()&&h[u].size()>num)v2.pb(h[u].top()),h[u].pop();
	dp[u][0]=h[u].sum+res;
	while(h[u].size()&&h[u].size()>num-1)v2.pb(h[u].top()),h[u].pop();
	dp[u][1]=h[u].sum+res;
	for (int i=0;i<v2.size();i++)h[u].add(v2[i]);
	for (int i=0;i<v1.size();i++)h[u].del(v1[i]);
}

signed main()
{
	n=read();int sum=0;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		e[u].pb(mp(v,w)),e[v].pb(mp(u,w));
		out[u]++,out[v]++,sum+=w;
	}
	for (int i=1;i<=n;i++)
		sort(e[i].begin(),e[i].end(),cmp),p[i]=mp(out[i],i);
	sort(p+1,p+1+n);printf("%lld",sum);
	for (int l=1,i=1;i<n;i++)
	{
		int ans=0;X=i;
		while(l<=n&&p[l].x==i)del(p[l].y),l++;
		for (int i=l;i<=n;i++)
		{
			int u=p[i].y;
			if (vis[u]==X)continue;
			dfs(u,0);ans+=dp[u][0];
		}
		printf("% lld",ans);
	}
	return 0;
}