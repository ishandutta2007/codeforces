#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int left,right;
	ll lazy,mina;
}t[1100000];

const ll inf=1ll<<60;
int n,q,tot;
int v[1000005],c[1000005],nxt[1000005],h[500005],siz[500005];
ll dep[500005],ans[500005];
bool leaf[500005];
vector<pair<int,pair<int,int> > > vec[500005];

void addedge(int x,int y,int z){v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;}

void build(int id,int l,int r){
	t[id].left=l,t[id].right=r;
	if(l==r) return (void)(t[id].mina=leaf[l]?inf:dep[l]);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id].mina=min(t[id<<1].mina,t[id<<1|1].mina);
}

void pushdown(int id){
	if(t[id].lazy){
		t[id<<1].lazy+=t[id].lazy;
		t[id<<1|1].lazy+=t[id].lazy;
		t[id].mina+=t[id].lazy;
		t[id].lazy=0;
	}
}

void change(int id,int l,int r,int c){
	if(t[id].left==l&&t[id].right==r) return (void)(t[id].lazy=t[id].lazy+c);
	pushdown(id);
	if(t[id<<1].right>=r) change(id<<1,l,r,c);
	else if(t[id<<1|1].left<=l) change(id<<1|1,l,r,c);
	else change(id<<1,l,t[id<<1].right,c),change(id<<1|1,t[id<<1|1].left,r,c);
	t[id].mina=min(t[id<<1].mina+t[id<<1].lazy,t[id<<1|1].mina+t[id<<1|1].lazy);
}

ll query(int id,int l,int r){
	if(t[id].left==l&&t[id].right==r) return t[id].mina+t[id].lazy;
	pushdown(id);
	if(t[id<<1].right>=r) return query(id<<1,l,r);
	else if(t[id<<1|1].left<=l) return query(id<<1|1,l,r);
	else return min(query(id<<1,l,t[id<<1].right),query(id<<1|1,t[id<<1|1].left,r));
}

void dfs(int u){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		dep[v[p]]=dep[u]+c[p];
		dfs(v[p]);
		siz[u]+=siz[v[p]];
		leaf[u]=true;
	}
}

void work(int u){
	for(int i=0;i<vec[u].size();i++) ans[vec[u][i].fi]=query(1,vec[u][i].se.fi,vec[u][i].se.se);
	for(int p=h[u];p;p=nxt[p]){
		change(1,1,n,c[p]),change(1,v[p],v[p]+siz[v[p]]-1,-2*c[p]);
		work(v[p]);
		change(1,1,n,-c[p]),change(1,v[p],v[p]+siz[v[p]]-1,2*c[p]);
	}
}

int main(){
	n=readint(); q=readint();
	int x,y,z;
	for(int i=2;i<=n;i++){
		x=readint(); y=readint();
		addedge(x,i,y);
	}
	for(int i=1;i<=q;i++){
		x=readint(); y=readint(); z=readint();
		vec[x].push_back(mp(i,mp(y,z)));
	}
	dfs(1);
	build(1,1,n);
	work(1);
	for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}