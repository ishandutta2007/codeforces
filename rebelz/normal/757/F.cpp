#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
bool vis[200005];
int n,m,tot,s;
int v[1200005],nxt[1200005],c[1200005],h[200005],g[200005],du[200005],qu[200005],dep[200005];
int xx[300005],yy[300005],zz[300005],siz[200005],f[200005][20];
ll dis[200005];

void addedge(int x,int y,int z){v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;}
void addedge2(int x,int y){/*cout<<"TEST "<<x<<' '<<y<<endl;*/v[++tot]=y; nxt[tot]=g[x]; g[x]=tot;}

void dij(){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0; q.push(make_pair(0,s));
	while(!q.empty()){
		int t=q.top().second; q.pop();
		vis[t]=true;
		for(int p=h[t];p;p=nxt[p]){
			if(dis[v[p]]>dis[t]+c[p]){
				dis[v[p]]=dis[t]+c[p];
				q.push(make_pair(dis[v[p]],v[p]));
			}
		}
	}
}

void toposort(){
	int front=1,rear=1;
	for(int i=1;i<=n;i++) if(!du[i]&&dis[i]<0x3f3f3f3f3f3f3f3f) qu[rear++]=i;
	while(front<rear){
		int t=qu[front++];
		for(int p=h[t];p;p=nxt[p]) if((--du[v[p]])==0) qu[rear++]=v[p];
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

void dfs(int u){
	siz[u]=1;
	for(int p=g[u];p;p=nxt[p]){
		if(v[p]==f[u][0]) continue;
		dfs(v[p]);
		siz[u]+=siz[v[p]];
	}
}

int main(){
	n=readint(); m=readint(); s=readint();
	for(int i=1;i<=m;i++){
		xx[i]=readint(); yy[i]=readint(); zz[i]=readint();
		addedge(xx[i],yy[i],zz[i]);
		addedge(yy[i],xx[i],zz[i]);
	}
	dij();
	memset(h,0,sizeof(h)); tot=0;
	for(int i=1;i<=m;i++){
		if(dis[xx[i]]+zz[i]==dis[yy[i]]) addedge(yy[i],xx[i],zz[i]),du[xx[i]]++;
		else if(dis[yy[i]]+zz[i]==dis[xx[i]]) addedge(xx[i],yy[i],zz[i]),du[yy[i]]++;
	}
	toposort();
	int cnt=0,d;
	for(int i=n;i>=1;i--){
		if(!qu[i]) continue;
		cnt=0;
		for(int p=h[qu[i]];p;p=nxt[p]){
			if(!cnt) d=v[p];
			else d=lca(d,v[p]);
			cnt++;
		}
		if(!cnt) d=0;
		addedge2(d,qu[i]);
		dep[qu[i]]=dep[d]+1,f[qu[i]][0]=d;
		for(int j=1;j<=19;j++) f[qu[i]][j]=f[f[qu[i]][j-1]][j-1];
	}
	dfs(0);
	int ans=0;
	for(int i=1;i<=n;i++) if(i!=s) ans=max(ans,siz[i]);
	printf("%d\n",ans);
	return 0;
}