#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node{
	int left,right,sum;
}t[1000000];

int n,m,tot=0,cnt=0;
int v[400005],nxt[400005],h[200005],siz[200005],f[200005],dep[200005],son[200005],top[200005],dfn[200005],rnk[200005],a[200005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void buildtree(int id,int l,int r){
	t[id].left=l,t[id].right=r;
	if(l==r)
		return;
	int mid=(l+r)/2;
	buildtree(id<<1,l,mid);
	buildtree(id<<1|1,mid+1,r);
}

void change(int id,int p,int c){
	if(t[id].left==p&&t[id].right==p){
		t[id].sum+=c;
		return;
	}
	if(p<=t[id<<1].right)
		change(id<<1,p,c);
	else
		change(id<<1|1,p,c);
	t[id].sum=t[id<<1].sum+t[id<<1|1].sum;
}

int query(int id,int l,int r){
	if(t[id].left==l&&t[id].right==r)
		return t[id].sum;
	if(t[id<<1].right>=r)
		return query(id<<1,l,r);
	else if(t[id<<1|1].left<=l)
		return query(id<<1|1,l,r);
	else
		return query(id<<1,l,t[id<<1].right)+query(id<<1|1,t[id<<1|1].left,r);
}

void dfs1(int u){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u])
			continue;
		f[v[p]]=u,dep[v[p]]=dep[u]+1;
		dfs1(v[p]);
		siz[u]+=siz[v[p]];
		if(siz[v[p]]>siz[son[u]])
			son[u]=v[p];
	}
}

void dfs2(int u){
	dfn[u]=++cnt,rnk[cnt]=u;
	if(son[u]){
		top[son[u]]=top[u];
		dfs2(son[u]);
	}
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u]||v[p]==son[u])
			continue;
		top[v[p]]=v[p];
		dfs2(v[p]);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int opt,x,y,ans;
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	dep[1]=1; top[1]=1;
	dfs1(1); dfs2(1);
	buildtree(1,1,n);
	for(int i=1;i<=m;i++){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&x,&y);
			if(dep[x]%2==1)
				y=-y;
			change(1,dfn[x],y);
		}
		else{
			scanf("%d",&x);
			y=x,ans=0;
			while(x){
				ans+=query(1,dfn[top[x]],dfn[x]);
				x=f[top[x]];
			}
			printf("%d\n",(dep[y]%2==1?-ans:ans)+a[y]);
		}
	}
	return 0;
}