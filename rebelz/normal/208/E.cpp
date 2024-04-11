#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node{
	int lch,rch,val;
}t[6000005];

int n,m,tot,cnt,ncnt;
int v[200005],nxt[200005],h[100005],siz[100005],dfn[100005],rnk[100005],f[100005][20],vs[100005];
int dep[100005];
bool vis[100005];

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

void buildtree(int id,int l,int r){
	if(l==r)
		return;
	int mid=(l+r)/2;
	buildtree(t[id].lch=++cnt,l,mid);
	buildtree(t[id].rch=++cnt,mid+1,r);
}

int change(int id,int l,int r,int p){
	int root=++cnt;
	t[root]=t[id]; t[root].val++;
	if(l==r)
		return root;
	int mid=(l+r)/2;
	if(p<=mid)
		t[root].lch=change(t[id].lch,l,mid,p);
	else
		t[root].rch=change(t[id].rch,mid+1,r,p);
	return root;
}

int query(int id1,int id2,int l,int r,int p){
	if(l==r)
		return t[id2].val-t[id1].val;
	int mid=(l+r)/2;
	if(p<=mid)
		return query(t[id1].lch,t[id2].lch,l,mid,p);
	else
		return query(t[id1].rch,t[id2].rch,mid+1,r,p);
}

void dfs(int u){
	dfn[u]=++ncnt,rnk[ncnt]=u,siz[u]=1;
	for(int i=1;i<=19;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	for(int p=h[u];p;p=nxt[p]){
		f[v[p]][0]=u,dep[v[p]]=dep[u]+1;
		dfs(v[p]);
		siz[u]+=siz[v[p]];
	}
}

int find(int x,int y){
	for(int i=19;i>=0;i--)
		if((y>>i)&1)
			x=f[x][i];
	return x;
}

int main(){
	scanf("%d",&n);
	int x,y,z;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(x!=0)
			addedge(x,i);
		else
			vis[i]=true;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			dep[i]=1;
			dfs(i);
		}
	}
	buildtree(vs[0]=0,1,n);
	for(int i=1;i<=n;i++)
		vs[i]=change(vs[i-1],1,n,dep[rnk[i]]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		z=find(x,y);
		if(z<=0)
			printf("0\n");
		else
			printf("%d\n",query(vs[dfn[z]-1],vs[dfn[z]+siz[z]-1],1,n,dep[x])-1);
	}
	return 0;
}