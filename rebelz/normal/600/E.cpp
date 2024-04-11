#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,block,tot,ncnt;

struct node{
	int id,l,r;
	bool operator<(const node c)const{
		if(l/block==c.l/block) return l/block%2==0?r<c.r:r>c.r;
		return l/block<c.l/block;
	}
}q[100005];

int c[100005],dfn[100005],siz[100005],v[200005],nxt[200005],h[100005],rnk[100005],cnt[100005];
int maxa;
ll ans[100005],num[100005];

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	dfn[u]=++ncnt,rnk[ncnt]=u,siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs(v[p],u);
		siz[u]+=siz[v[p]];
	}
}

void add(int x){
	num[cnt[c[rnk[x]]]]-=c[rnk[x]]; cnt[c[rnk[x]]]++; num[cnt[c[rnk[x]]]]+=c[rnk[x]];
	if(cnt[c[rnk[x]]]>maxa) maxa=cnt[c[rnk[x]]];
}

void del(int x){
	num[cnt[c[rnk[x]]]]-=c[rnk[x]]; cnt[c[rnk[x]]]--; num[cnt[c[rnk[x]]]]+=c[rnk[x]];
	if(num[maxa]==0) maxa--;
}

int main(){
	n=readint(); block=sqrt(n);
	for(int i=1;i<=n;i++) c[i]=readint();
	int x,y;
	for(int i=1;i<=n-1;i++){
		x=readint(); y=readint();
		addedge(x,y);
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++) q[i].l=dfn[i],q[i].r=dfn[i]+siz[i]-1,q[i].id=i;
	sort(q+1,q+n+1);
	int nl=1,nr=0;
	for(int i=1;i<=n;i++){
		while(nr<q[i].r) add(++nr);
		while(nl>q[i].l) add(--nl);
		while(nr>q[i].r) del(nr--);
		while(nl<q[i].l) del(nl++);
		ans[q[i].id]=num[maxa];
	}
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}