#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int lazy;
	bitset<1000> b;
}t[300000];

int n,m,q,tot,cnt,num;
int v[200005],nxt[200005],h[100005],rnk[100005],dfn[100005],a[100005],siz[100005],prime[100005];
bool fl[100005];
bitset<1000> pri;

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void build(int id,int l,int r){
	if(l==r) return (void)(t[id].b[a[rnk[l]]]=1);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id].b=t[id<<1].b|t[id<<1|1].b;
}

void turn(bitset<1000> &bs,int k){bs=(bs>>(m-k))|(bs<<(1000-m+k)>>(1000-m));}

void pushdown(int id){
	if(t[id].lazy){
		t[id<<1].lazy=(t[id<<1].lazy+t[id].lazy)%m,t[id<<1|1].lazy=(t[id<<1|1].lazy+t[id].lazy)%m;
		turn(t[id<<1].b,t[id].lazy),turn(t[id<<1|1].b,t[id].lazy);
		t[id].lazy=0;
	}
}

void change(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr){
		turn(t[id].b,c);
		t[id].lazy=(t[id].lazy+c)%m;
		return;
	}
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	t[id].b=t[id<<1].b|t[id<<1|1].b;
}

bitset<1000> query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return t[id].b;
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return query(id<<1,l,mid,ql,mid)|query(id<<1|1,mid+1,r,mid+1,qr);
}

void dfs(int u,int fa){
	dfn[u]=++cnt,rnk[cnt]=u,siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs(v[p],u);
		siz[u]+=siz[v[p]];
	}
}

void getprime(int g){
	fl[1]=true;
	for(int i=2;i<g;i++){
		if(!fl[i]) prime[++num]=i,pri[i]=1;
		for(int j=1;j<=num&&i*prime[j]<g;j++){
			fl[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
}

int main(){
	n=readint(); m=readint();
	getprime(m);
	for(int i=1;i<=n;i++) a[i]=readint()%m;
	for(int i=1;i<=n-1;i++) addedge(readint(),readint());
	dfs(1,-1);
	build(1,1,n);
	q=readint();
	int opt,x;
	while(q--){
		opt=readint(); x=readint();
		if(opt==1) change(1,1,n,dfn[x],dfn[x]+siz[x]-1,readint()%m);
		else printf("%d\n",(query(1,1,n,dfn[x],dfn[x]+siz[x]-1)&pri).count());
	}
	return 0;
}