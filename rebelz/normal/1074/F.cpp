#include<bits/stdc++.h>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int lazy,mina,num;
}t[600000];

int n,q,tot,cnt;
int dfn[200005],siz[200005],v[400005],nxt[400005],h[200005],f[200005][20],dep[200005];
map<pii,int> b;

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	dfn[u]=++cnt,siz[u]=1;
	for(int i=1;i<=19;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		f[v[p]][0]=u,dep[v[p]]=dep[u]+1;
		dfs(v[p],u);
		siz[u]+=siz[v[p]];
	}
}

void build(int id,int l,int r){
	t[id].num=r-l+1;
	if(l==r) return;
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}

void pushdown(int id){
	if(t[id].lazy){
		t[id<<1].lazy+=t[id].lazy,t[id<<1].mina+=t[id].lazy;
		t[id<<1|1].lazy+=t[id].lazy,t[id<<1|1].mina+=t[id].lazy;
		t[id].lazy=0;
	}
}

void change(int id,int l,int r,int ql,int qr,int c){
	if(ql>qr) return;
	if(l==ql&&r==qr){
		t[id].lazy+=c,t[id].mina+=c;
		return;
	}
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	if(t[id<<1].mina<t[id<<1|1].mina) t[id].mina=t[id<<1].mina,t[id].num=t[id<<1].num;
	else if(t[id<<1].mina>t[id<<1|1].mina) t[id].mina=t[id<<1|1].mina,t[id].num=t[id<<1|1].num;
	else t[id].mina=t[id<<1].mina,t[id].num=t[id<<1].num+t[id<<1|1].num;
}

int up(int x,int y){
	for(int i=19;i>=0;i--) if(y>=(1<<i)) x=f[x][i],y-=(1<<i);
	return x;
}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n-1;i++) addedge(readint(),readint());
	dep[1]=1; dfs(1,-1);
	build(1,1,n);
	int x,y;
	while(q--){
		x=readint(); y=readint();
		if(dfn[x]>dfn[y]) swap(x,y);
		int tmp=b[mp(x,y)]?-1:1;
		if(dfn[x]+siz[x]-1>=dfn[y]+siz[y]-1){
			int u=up(y,dep[y]-dep[x]-1);
			change(1,1,n,dfn[u],dfn[y]-1,tmp);
			change(1,1,n,dfn[y]+siz[y],dfn[u]+siz[u]-1,tmp);
		}
		else{
			change(1,1,n,1,dfn[x]-1,tmp);
			change(1,1,n,dfn[x]+siz[x],dfn[y]-1,tmp);
			change(1,1,n,dfn[y]+siz[y],n,tmp);
		}
		b[mp(x,y)]^=1;
		if(t[1].mina==0) printf("%d\n",t[1].num);
		else printf("0\n");
	}
	return 0;
}