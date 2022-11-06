#include<cstdio>
const int maxn=200000,maxc=100;
struct node{
	int l,r,v[maxc+10];
	bool tag;
}a[maxn*4+10];
int n,m,b[maxn+10];
void build(int p,int l,int r){
	a[p].l=l; a[p].r=r; for(int i=1;i<=maxc;++i) a[p].v[i]=i;
	if(l!=r){
		int mid=(l+r)/2;
		build(p*2,l,mid); build(p*2+1,mid+1,r);
	}
}
void push(int p){
	if(a[p].tag){
		for(int i=1;i<=maxc;++i){
			a[p*2].v[i]=a[p].v[a[p*2].v[i]];
			a[p*2+1].v[i]=a[p].v[a[p*2+1].v[i]];
		}
		for(int i=1;i<=maxc;++i) a[p].v[i]=i;
		a[p].tag=0; a[p*2].tag=a[p*2+1].tag=1;
	}
}
void change(int p,int l,int r,int x,int y){
	if(a[p].l==l&&a[p].r==r){
		for(int i=1;i<=maxc;++i)
			if(a[p].v[i]==x) a[p].v[i]=y;
		a[p].tag=1; return;
	}
	int mid=(a[p].l+a[p].r)/2; push(p);
	if(r<=mid) change(p*2,l,r,x,y);
	else if(l>mid) change(p*2+1,l,r,x,y);
	else change(p*2,l,mid,x,y),change(p*2+1,mid+1,r,x,y);
}
void dfs(int p){
	if(a[p].l==a[p].r)
		printf("%d ",a[p].v[b[a[p].l]]);
	else push(p),dfs(p*2),dfs(p*2+1);
}
int main(){
	scanf("%d",&n); build(1,1,n);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		int l,r,x,y; scanf("%d%d%d%d",&l,&r,&x,&y);
		change(1,l,r,x,y);
	}
	dfs(1); return 0;
}