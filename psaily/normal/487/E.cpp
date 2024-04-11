#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;

#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define fi first
#define se second

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int maxn=3e5+50;
const int maxm=3e5+50;
const int max_node=maxn<<1;
const int max_edge=maxm<<1;
const int inf=0x3f3f3f3f;

int n,m,q;
int val[maxn];

struct delete_heap{
	priority_queue<int,vector<int>,greater<int> >A,B;
	int siz;
	void init(){while(B.size()>0&&A.top()==B.top())A.pop(),B.pop();}
	void push(int x){siz++;init();A.push(x);}
	void _delete(int x){siz--;init();B.push(x);}
	int _top(){init();if(A.size())return A.top();else return inf;}
	void pop(){siz--;init();A.pop();}
	int size(){return siz;}
}heap[max_node];

int head[max_node],nxt[max_edge],to[max_edge],edge_tot;
void add_edge(int u,int v){nxt[++edge_tot]=head[u];head[u]=edge_tot;to[edge_tot]=v;}

int dfn_cnt,bcc_cnt,top,tot;
int bccno[max_node],dfn[max_node],low[max_node],stk[max_node];

vector<int>E[max_node];

void tarjan(int u,int f){
	dfn[u]=low[u]=++dfn_cnt;
	stk[++top]=u;
	for(int i=head[u];~i;i=nxt[i]){
		int v=to[i];
		if(!dfn[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<=low[v]){
				bcc_cnt++;tot++;
				E[u].push_back(tot);
				E[tot].push_back(u);
				for(;;){
					int k=stk[top--];
					E[k].push_back(tot);
					E[tot].push_back(k);
					if(k==v)break;
				}
			}
		}else if(v!=f)low[u]=min(low[u],dfn[v]);
	}
}

void find_bcc(){
	dfn_cnt=bcc_cnt=top=0;
	tot=n;
	memset(dfn,0,sizeof(dfn));
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i,-1);
}

int dep[max_node],par[max_node],son[max_node],siz[max_node];

void ldfs(int u,int f){
	son[u]=0,siz[u]=1,par[u]=f,dep[u]=dep[f]+1;
	for(int i=0;i<E[u].size();i++){
		int v=E[u][i];
		if(v==f)continue;
		if(u>n&&v<=n)heap[u].push(val[v]);
		ldfs(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}

int sig_cnt;
int tp[max_node],tid[max_node],sig[max_node];

void rdfs(int u,int _tp){
	tp[u]=_tp;
	sig[++sig_cnt]=u,tid[u]=sig_cnt;
	if(son[u])rdfs(son[u],_tp);
	for(int i=0;i<E[u].size();i++){
		int v=E[u][i];
		if(v==son[u]||v==par[u])continue;
		rdfs(v,v);
	}
}

struct segment_tree{
	#define lp tree[p<<1]
	#define rp tree[p<<1|1]
	#define lson p<<1,l,mid
	#define rson p<<1|1,mid+1,r
	struct node{
		int l,r;
		int mi;
	}tree[max_node<<2];
	void push_up(int p){tree[p].mi=min(lp.mi,rp.mi);}
	void build(int p,int l,int r){
		tree[p].l=l,tree[p].r=r,tree[p].mi=inf;
		if(l==r){
			int u=sig[l];
			if(u<=n)tree[p].mi=val[u];
			else tree[p].mi=heap[u]._top();
			return;
		}
		int mid=(l+r)>>1;
		build(lson);
		build(rson);
		push_up(p);
	}
	int query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return tree[p].mi;
		int mid=(l+r)>>1;
		if(qr<=mid)return query(lson,ql,qr);
		else if(mid<ql)return query(rson,ql,qr);
		else return min(query(lson,ql,qr),query(rson,ql,qr));
	}
	void update(int p,int l,int r,int x,int a){
		if(l==r){
			tree[p].mi=a;
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid)update(lson,x,a);
		else update(rson,x,a);
		push_up(p);
	}
}T;

int main(){
	memset(head,edge_tot=-1,sizeof(head));
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&val[i]);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	find_bcc();
	ldfs(1,0);
	rdfs(1,1);
	T.build(1,1,sig_cnt);
	while(q--){
		char op[5];
		scanf("%s",op);
		if(op[0]=='C'){
			int a,w;
			scanf("%d%d",&a,&w);
			int f=par[a];
			if(f){
				heap[f]._delete(val[a]);
				heap[f].push(w);
				int pos=tid[f];
				T.update(1,1,sig_cnt,pos,heap[f]._top());
			}
			val[a]=w;
			T.update(1,1,sig_cnt,tid[a],w);
		}else{
			int a,b,ans=inf;
			scanf("%d%d",&a,&b);
			while(tp[a]!=tp[b]){
				if(dep[tp[a]]>dep[tp[b]])swap(a,b);
				ans=min(ans,T.query(1,1,sig_cnt,tid[tp[b]],tid[b]));
				b=par[tp[b]];
			}
			if(dep[a]>dep[b])swap(a,b);
			ans=min(ans,T.query(1,1,sig_cnt,tid[a],tid[b]));
			if(a>n&&par[a])ans=min(ans,val[par[a]]);
			printf("%d\n",ans);
		}
	}
	return 0;
}