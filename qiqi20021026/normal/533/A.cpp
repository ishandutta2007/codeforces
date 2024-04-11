#include<bits/stdc++.h>

using namespace std;

#define N 600000
#define INF 0x3f3f3f3f
#define ls (x<<1)
#define rs (x<<1|1)

int n,m,x,y,z,tot,k,ans,xb;
int a[N],b[N],c[N],h[N],mn[N],head[N],fa[N],hsh[N*2],seg[N*4],tag[N*4];
vector<int> vec[N];
struct edge{int v,nxt;}e[N*2];

void add(int x,int y){e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;}

void psd(int x){
	seg[ls]+=tag[x]; seg[rs]+=tag[x];
	tag[ls]+=tag[x]; tag[rs]+=tag[x];
	tag[x]=0;
}

void add(int x,int l,int r,int R,int k){
	if (r<=R){seg[x]+=k; tag[x]+=k; return;}
	psd(x);
	int mid=(l+r)>>1;
	if (R>=mid+1) add(rs,mid+1,r,R,k);
	add(ls,l,mid,R,k);
	seg[x]=min(seg[ls],seg[rs]);
}

int srch(int x,int l,int r){
	if (l==r) return l;
	psd(x);
	int mid=(l+r)>>1;
	if (seg[rs]<0) return srch(rs,mid+1,r);
	return srch(ls,l,mid);
}

void dfs(int u){
	b[u]=b[fa[u]]; c[u]=c[fa[u]]; mn[u]=mn[fa[u]];
	if (a[u]<b[u]){c[u]=b[u]; b[u]=a[u]; mn[u]=u;}
	else{if (a[u]<c[u]) c[u]=a[u];}
	vec[mn[u]].push_back(u);
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa[u]){
			fa[v]=u; dfs(v);
		}
}

void calc(int u){
	if (hsh[k]>hsh[a[u]]){
		for (int i=0;i<(int)vec[u].size();++i){
			int x=vec[u][i];
			add(1,1,n+m,b[x],-1); add(1,1,n+m,min(k,c[x]),1);
		}
		if (seg[1]>=0) ans=min(ans,hsh[k]-hsh[a[u]]);
		for (int i=0;i<(int)vec[u].size();++i){
			int x=vec[u][i];
			add(1,1,n+m,b[x],1); add(1,1,n+m,min(k,c[x]),-1);
		}
	}
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa[u]) calc(v);
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){scanf("%d",&a[i]); hsh[++xb]=a[i];}
	for (int i=1;i<n;++i){scanf("%d%d",&x,&y); add(x,y); add(y,x);}
	scanf("%d",&m);
	for (int i=1;i<=m;++i){scanf("%d",&h[i]); hsh[++xb]=h[i];}
	sort(hsh+1,hsh+xb+1);
	for (int i=1;i<=n;++i) a[i]=lower_bound(hsh+1,hsh+xb+1,a[i])-hsh;
	for (int i=1;i<=m;++i) h[i]=lower_bound(hsh+1,hsh+xb+1,h[i])-hsh;
	a[0]=b[0]=c[0]=INF; dfs(1);
	for (int i=1;i<=m;++i) add(1,1,n+m,h[i],-1);
	for (int i=1;i<=n;++i) add(1,1,n+m,b[i],1);
	if (seg[1]>=0) return puts("0");
	k=srch(1,1,n+m); ans=INF; calc(1);
	printf("%d\n",ans>=INF?-1:ans);
	
	return 0;
}