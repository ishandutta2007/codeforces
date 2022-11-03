#include<bits/stdc++.h>
#define il inline
#define vd void
#define ll long long
il int gi(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n;
int cnt,fir[8000000],dis[20000010],nxt[20000010],id;
il vd link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int lg[200010];
struct Tree{
	int fir[200010],nxt[400010],dis[400010],id;
	int fa[200010],siz[200010],dep[200010],st[18][200010],ST[18][200010];
	int A[200010],B[200010];
	il vd treelink(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
	il vd dfs(int x){
		for(int i=fir[x];i;i=nxt[i])
			if(fa[x]!=dis[i]){
				st[0][dis[i]]=x;fa[dis[i]]=x;
				dep[dis[i]]=dep[x]+1;
				dfs(dis[i]);
			}
	}
	il int jump(int x,int d){for(int i=17;~i;--i)if((d>>i)&1)x=st[i][x];return x;}
	int fe[200010];
	il int LCA(int a,int b){
		if(dep[a]<dep[b])std::swap(a,b);
		int c=dep[a]-dep[b];
		for(int i=17;~i;--i)if((c>>i)&1)a=st[i][a];
		for(int i=17;~i;--i)if(st[i][a]!=st[i][b])a=st[i][a],b=st[i][b];
		if(a^b)a=st[0][a];return a;
	}
	il vd _link(int u,int v,int w){
		if(u==v)return;
		int len=dep[v]-dep[u],g=lg[len];
		link(ST[g][v],w);
		link(ST[g][jump(v,len-(1<<g))],w);
	}
	il vd Link(int u,int v,int w){
		int o=LCA(u,v);
		_link(o,u,w);_link(o,v,w);
	}
	il vd init(int d){
		int u,v;
		for(int i=1;i<n;++i)u=A[i]=i+1,v=B[i]=gi(),treelink(u,v),treelink(v,u);
		dep[1]=1;dfs(1);
		for(int i=1;i<n;++i)
			if(dep[A[i]]<dep[B[i]])fe[B[i]]=i;
			else fe[A[i]]=i;
		for(int i=2;i<=n;++i)ST[0][i]=fe[i]+d;
		for(int i=1;i<18;++i)
			for(int j=1;j<=n;++j){
				st[i][j]=st[i-1][st[i-1][j]];
				if(st[i][j])ST[i][j]=++cnt,link(ST[i-1][j],ST[i][j]),link(ST[i-1][st[i-1][j]],ST[i][j]);
			}
	}
}A,B;
int dist[8000000];bool vis[8000000];
std::deque<int>que;
std::vector<int>ans[200010];
int main(){
#ifdef XZZSB
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	n=gi();
	for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
	cnt=2*n-2;
	A.init(0),B.init(n-1);
	for(int i=1;i<n;++i)B.Link(A.A[i],A.B[i],i);
	for(int i=1;i<n;++i)A.Link(B.A[i],B.B[i],n-1+i);
	memset(dist,-1,sizeof dist);
	que.push_back(gi());dist[que.front()]=0;
	while(!que.empty()){
		while(!que.empty()&&vis[que.front()])que.pop_front();
		if(que.empty())break;
		int x=que.front();
		if(x<=n*2-2)ans[dist[x]].push_back(x);
		vis[x]=1;que.pop_front();
		for(int i=fir[x];i;i=nxt[i])
			if(dist[dis[i]]==-1||dist[dis[i]]>dist[x]+(x<=n-1)){
				dist[dis[i]]=dist[x]+(x<=n-1);
				if(x<=n-1)que.push_back(dis[i]);
				else que.push_front(dis[i]);
			}
	}
	for(int i=0;i<=n;++i){
		std::sort(ans[i].begin(),ans[i].end());
		if(ans[i].empty())continue;
		if(ans[i].back()>n-1){
			puts("Red");
			int p=ans[i].size()-1;
			while(p>0&&ans[i][p-1]>n-1)--p;
			for(int j=p;j<ans[i].size();++j)printf("%d ",ans[i][j]-n+1);
			puts("");
		}
		if(ans[i].front()<=n-1){
			puts("Blue");
			for(int j=0;j<ans[i].size();++j)
				if(ans[i][j]<=n-1)printf("%d ",ans[i][j]);
				else break;
			puts("");
		}
	}
	return 0;
}