#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

using namespace std;

int block;

struct node{
	int l,r,t,id;
	bool operator<(const node c)const{
		if(l/block==c.l/block)
			return l/block%2==0?r<c.r:r>c.r;
		return l/block<c.l/block;
	}
}q[100005];

int n,m,tot=0,ncnt=0;
int v[200005],nxt[200005],h[100005],dfn[100005],siz[100005];
int a[100005],cnt[100005],nowans[100005],ans[100005],rnk[100005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	dfn[u]=++ncnt,rnk[ncnt]=u,siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa)
			continue;
		dfs(v[p],u);
		siz[u]+=siz[v[p]];
	}
}

void add(int x){nowans[++cnt[a[rnk[x]]]]++;}
void del(int x){nowans[cnt[a[rnk[x]]]--]--;}

int main(){
	scanf("%d%d",&n,&m);
	block=sqrt(n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int x,y;
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	dfs(1,-1);
	for(int i=1;i<=m;i++){
		q[i].id=i;
		scanf("%d%d",&x,&q[i].t);
		q[i].l=dfn[x],q[i].r=dfn[x]+siz[x]-1;
	}
	sort(q+1,q+m+1);
	int nl=1,nr=0;
	for(int i=1;i<=m;i++){
		while(nl>q[i].l)add(--nl);
		while(nr<q[i].r)add(++nr);
		while(nl<q[i].l)del(nl++);
		while(nr>q[i].r)del(nr--);
		ans[q[i].id]=nowans[q[i].t];
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	printf("\n");
	return 0;
}