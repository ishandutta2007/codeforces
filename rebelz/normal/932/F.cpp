#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int N=100000;
int n,tot;
ll aa[100005],bb[100005],siz[100005],son[100005],tag[600000],k[100005],b[100005],v[200005],nxt[200005],h[100005],d[100005];
vector<int> vec;

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

ll val(int x,ll p){return (p-N)*k[x]+b[x];}

void change(int id,int l,int r,int c){
	vec.push_back(id);
	if(!tag[id]) return (void)(tag[id]=c);
	if(l==r){
		if(val(c,l)>val(tag[id],l)) tag[id]=c;
		return;
	}
	int mid=(l+r)/2;
	if(k[c]<k[tag[id]]){
		if(val(c,mid)<val(tag[id],mid)) change(id<<1,l,mid,tag[id]),tag[id]=c;
		else change(id<<1|1,mid+1,r,c);
	}
	else{
		if(val(c,mid)<val(tag[id],mid)) change(id<<1|1,mid+1,r,tag[id]),tag[id]=c;
		else change(id<<1,l,mid,c);
	}
}

ll query(int id,int l,int r,int x){
	ll now=tag[id]?val(tag[id],x):1ll<<60;
	if(l==r) return now;
	int mid=(l+r)/2;
	if(x<=mid) return min(now,query(id<<1,l,mid,x));
	else return min(now,query(id<<1|1,mid+1,r,x));
}

void add(int u,int fa){
	change(1,0,N+N,u);
	for(int p=h[u];p;p=nxt[p]) if(v[p]!=fa) add(v[p],u);
}

void dfs1(int u,int fa){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs1(v[p],u);
		if(siz[v[p]]>siz[son[u]]) son[u]=v[p];
		siz[u]+=siz[v[p]];
	}
}

void dfs2(int u,int fa,int keep){
	if(!son[u]){
		d[u]=b[u]=0,k[u]=bb[u];
		if(keep) change(1,0,N+N,u);
		return;
	}
	for(int p=h[u];p;p=nxt[p]) if(v[p]!=fa&&v[p]!=son[u]) dfs2(v[p],u,0);
	if(son[u]) dfs2(son[u],u,1);
	for(int p=h[u];p;p=nxt[p]) if(v[p]!=fa&&v[p]!=son[u]) add(v[p],u);
	d[u]=query(1,0,N+N,aa[u]+N);
	k[u]=bb[u],b[u]=d[u];
	change(1,0,N+N,u);
	if(!keep){
		for(int i=0;i<vec.size();i++) tag[vec[i]]=0;
		vec.clear();
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) aa[i]=readint();
	for(int i=1;i<=n;i++) bb[i]=readint();
	for(int i=1;i<=n-1;i++) addedge(readint(),readint());
	dfs1(1,-1);
	dfs2(1,-1,1);
	for(int i=1;i<=n;i++) printf("%lld ",d[i]);
	puts("");
	return 0;
}