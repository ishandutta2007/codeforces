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
	ll x,y,z;
	node(int xx=0,int yy=0,int zz=0):x(xx),y(yy),z(zz){}
	bool operator<(const node c)const{return x<c.x;}
}q[2000005];

ll n,m,ncnt,tot,cnt;
ll v[600005],nxt[600005],h[300005],c[300005],siz[300005],dep[300005],dfn[300005],rnk[300005],ans[300005];

int lowbit(int x){return x&(-x);}
void add(int x,int k){for(;x<=n;x+=lowbit(x))c[x]+=k;}
ll ask(int x){ll ret=0;for(;x;x-=lowbit(x))ret+=c[x];return ret;}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	dfn[u]=++ncnt; rnk[ncnt]=u; siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dep[v[p]]=dep[u]+1;
		dfs(v[p],u);
		siz[u]+=siz[v[p]];
	}
}

int main(){
	n=readint();
	ll x,y,z;
	for(int i=1;i<=n-1;i++){
		x=readint(); y=readint();
		addedge(x,y);
	}
	dep[1]=1; dfs(1,-1);
//	for(int i=1;i<=n;i++) cout<<dfn[i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=n;i++) cout<<siz[i]<<' ';
//	cout<<endl;
	m=readint();
	for(int i=1;i<=m;i++){
		x=readint(); y=readint(); z=readint();
		if(dfn[x]+siz[x]<=n&&dep[x]+y+1<=n) q[++cnt]=node(dfn[x]+siz[x],dep[x]+y+1,z);
		q[++cnt]=node(dfn[x],dep[x],z);
		if(dep[x]+y+1<=n) q[++cnt]=node(dfn[x],dep[x]+y+1,-z);
		if(dfn[x]+siz[x]<=n) q[++cnt]=node(dfn[x]+siz[x],dep[x],-z);
	}
	sort(q+1,q+cnt+1);
	q[cnt+1].x=n+1;
	for(int i=1;i<=cnt;i++){
//		cout<<q[i].x<<' '<<q[i].y<<' '<<q[i].z<<' '<<dep[rnk[q[i].x]]<<endl;
		add(q[i].y,q[i].z);
		if(q[i].x!=q[i+1].x){
			for(int j=q[i].x;j<=q[i+1].x-1;j++) ans[rnk[j]]=ask(dep[rnk[j]]);
		}
	}
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}