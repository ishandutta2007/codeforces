#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,ncnt,tot;
int v[500005],nxt[500005],h[250005],siz[250005],dfn[250005],rnk[250005],f[250005],fa[250005],ch[250005][2],rev[250005],mina[250005],maxa[250005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u){
	dfn[u]=++ncnt,rnk[ncnt]=u,siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u]) continue;
		f[v[p]]=u;
		dfs(v[p]);
		siz[u]+=siz[v[p]];
	}
}

int nroot(int u){return ch[fa[u]][0]==u||ch[fa[u]][1]==u;}
int son(int u){return ch[fa[u]][1]==u;}
void reverse(int u){rev[u]^=1,swap(ch[u][0],ch[u][1]);}
void pushdown(int u){if(rev[u])reverse(ch[u][0]),reverse(ch[u][1]),rev[u]=0;}

void update(int u){
	mina[u]=min(dfn[u],min(mina[ch[u][0]],mina[ch[u][1]]));
	maxa[u]=max(dfn[u],max(maxa[ch[u][0]],maxa[ch[u][1]]));
}

void rotate(int x){
	int y=fa[x],z=fa[y],k=son(x),w=ch[x][!k];
	if(nroot(y)) ch[z][son(y)]=x;
	ch[x][!k]=y,ch[y][k]=w;
	if(w) fa[w]=y;
	fa[y]=x,fa[x]=z;
	update(y),update(x);
}

void pushall(int u){
	if(nroot(u)) pushall(fa[u]);
	pushdown(u);
}

void splay(int x){
	pushall(x);
	while(nroot(x)){
		int y=fa[x];
		if(nroot(y)) rotate(son(x)==son(y)?y:x);
		rotate(x);
	}
}

void access(int x){for(int y=0;x;x=fa[y=x]) splay(x),ch[x][1]=y,update(x);}
void makeroot(int x){access(x); splay(x); reverse(x);}
void link(int x,int y){makeroot(x);makeroot(y); if(nroot(x)||nroot(y)) return; fa[x]=y;}
void cut(int x,int y){makeroot(x); access(y); splay(x); if(ch[x][1]!=y) return; ch[x][1]=0,fa[y]=0;}

int find(int x,int l,int r){
	pushdown(x);
	if(mina[ch[x][0]]<l||maxa[ch[x][0]]>r) return find(ch[x][0],l,r);
	if(dfn[x]<l||dfn[x]>r) return x;
	return find(ch[x][1],l,r);
}

int main(){
	n=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	dfs(1);
	for(int i=1;i<=n;i++) mina[i]=maxa[i]=dfn[i];
	mina[0]=1<<30;
	for(int i=1;i<n;i++) link(readint(),readint());
	printf("%d\n",n-1);
	for(int i=n;i>1;i--){
		int u=rnk[i];
		makeroot(u);
		access(f[u]);
		splay(u);
		int x=find(u,dfn[u],dfn[u]+siz[u]-1),y;
		if(!x) return 0;
		splay(x);
		pushdown(x);
		for(y=ch[x][0];ch[y][1];y=ch[y][1]) pushdown(y);
		cut(x,y);
		link(u,f[u]);
		printf("%d %d %d %d\n",u,f[u],x,y);
	}
	return 0;
}