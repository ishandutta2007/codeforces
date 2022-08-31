#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,tot,ncnt,top,k;
int dfn[100005],v[200005],nxt[200005],h[100005],f[100005][20],dep[100005],d[100005][2],s[100005],a[100005];
bool b[100005];
vector<int> g[100005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	dfn[u]=++ncnt;
	for(int i=1;i<=18;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		f[v[p]][0]=u,dep[v[p]]=dep[u]+1;
		dfs1(v[p],u);
	}
}

bool cmp(int x,int y){return dfn[x]<dfn[y];}

void dfs2(int u){
//	for(auto x:g[u]) cout<<"TEST "<<u<<' '<<x<<endl;
	d[u][0]=d[u][1]=1<<30;
	if(b[u]) d[u][1]=0;
	else d[u][0]=0;
	ll sum1=0,sum2=0;
	for(auto x:g[u]){
		dfs2(x);
		sum1+=d[x][0],sum2+=min(d[x][0],d[x][1]);
		if(b[u]) d[u][1]+=min(d[x][0],d[x][1]+1);
		else d[u][0]+=min(d[x][0],d[x][1]+1);
	}
	if(!b[u]) for(auto x:g[u]) d[u][1]=min((ll)d[u][1],sum1-d[x][0]+d[x][1]);
	if(!b[u]) d[u][0]=min((ll)d[u][0],sum2+1);
//	cout<<"dfs "<<u<<' '<<d[u][0]<<' '<<d[u][1]<<endl;
	g[u].clear();
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=18;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=18;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

void insert(int x){
	if(!top) return (void)(s[++top]=x);
	int l=lca(x,s[top]);
	if(l==s[top]) return (void)(s[++top]=x);
	while(top>1&&dfn[l]<=dfn[s[top-1]]) g[s[top-1]].push_back(s[top]),top--;
	if(l!=s[top]) g[l].push_back(s[top]),s[top]=l;
	s[++top]=x;
}

int main(){
	n=readint();
	for(int i=1;i<=n-1;i++) addedge(readint(),readint());
	dep[1]=1; dfs1(1,-1);
	m=readint();
	while(m--){
		k=readint();
		for(int i=1;i<=k;i++) a[i]=readint(),b[a[i]]=true;
		bool fl=true;
		for(int i=1;i<=k;i++) if(b[f[a[i]][0]]) fl=false;
		if(!fl){
			printf("-1\n");
			for(int i=1;i<=k;i++) b[a[i]]=false;
			continue;
		}
		sort(a+1,a+k+1,cmp);
		top=0;
		if(a[1]!=1) insert(1);
		for(int i=1;i<=k;i++) insert(a[i]);
		while(top>1) g[s[top-1]].push_back(s[top]),top--;
		dfs2(1);
		printf("%d\n",min(d[1][0],d[1][1]));
		for(int i=1;i<=k;i++) b[a[i]]=false;
	}
	return 0;
}