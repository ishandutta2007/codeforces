#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n,m,q;
struct edge{
	int u,v,w;
};
vector<edge> edges;
vector<int> g[maxn];
void add_edge(int u,int v,int w){
	g[u].push_back(edges.size());
	edges.push_back({u,v,w});
}
typedef long long ll;
const ll inf=9e18;
ll d[maxn];
bool vis[maxn];
int p[maxn];
typedef pair<ll,int> pii;
void dj(int s){
	for(int i=1;i<=n;i++) d[i]=inf;
	memset(vis,0,sizeof(vis));
	memset(p,-1,sizeof(p));
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	pq.push({0,s});
	d[s]=0;
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i:g[u]){
			edge& e=edges[i];
			if(d[e.v]>d[u]+e.w){
				d[e.v]=d[u]+e.w;
				p[e.v]=i;
				pq.push(pii(d[e.v],e.v));
			}
		}
	}
}
ll d1[maxn];
int l[maxn],r[maxn],pos[maxn*2];
int ord[maxn];
struct node{
	int l,r;
	node* ch[2];
	ll tag;
	node(int l,int r):l(l),r(r),tag(inf){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
	}
	void pushdown(){
		ch[0]->tag=min(ch[0]->tag,tag);
		ch[1]->tag=min(ch[1]->tag,tag);
	}
	void modify(int ql,int qr,ll k){
		if(ql<=l&&qr>=r){
			tag=min(tag,k);
			return;
		}
		pushdown();
		if(ql<=ch[0]->r) ch[0]->modify(ql,qr,k);
		if(qr>=ch[1]->l) ch[1]->modify(ql,qr,k);
	}
	ll query(int x){
		if(l==r) return tag;
		pushdown();
		if(x<=ch[0]->r) return ch[0]->query(x);
		else return ch[1]->query(x);
	}
}*rt;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	q=readint();
	for(int i=0;i<m;i++){
		int u,v,w;
		u=readint();
		v=readint();
		w=readint();
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	dj(1);
	int u=n,cnt=0;
	while(u>1){
		cnt++;
		u=edges[p[u]].u;
	}
	u=n;
	for(int i=0;u>1;i++){
		pos[p[u]]=cnt-i;
		u=edges[p[u]].u;
	}
	for(int i=1;i<=n;i++) ord[i]=i;
	sort(ord+1,ord+n+1,[](int a,int b){
		return d[a]<d[b];
	});
	for(int i=2;i<=n;i++) if(p[ord[i]]>=0)
		l[ord[i]]=pos[p[ord[i]]]?pos[p[ord[i]]]:l[edges[p[ord[i]]].u];
	for(int i=1;i<=n;i++) d1[i]=d[i];
	dj(n);
	for(int i=1;i<=n;i++) ord[i]=i;
	sort(ord+1,ord+n+1,[](int a,int b){
		return d[a]<d[b];
	});
	r[n]=cnt+1;
	for(int i=2;i<=n;i++) if(p[ord[i]]>=0)
		r[ord[i]]=pos[p[ord[i]]^1]?pos[p[ord[i]]^1]:r[edges[p[ord[i]]].u];
	rt=new node(1,cnt);
	for(int i=0;i<m*2;i++){
		edge& e=edges[i];
		if(pos[i]||d1[e.u]==inf||d[e.v]==inf||l[e.u]+1>=r[e.v]) continue;
		rt->modify(l[e.u]+1,r[e.v]-1,d1[e.u]+d[e.v]+e.w);
	}
	while(q--){
		int t,x;
		t=readint();
		x=readint();
		edge& e=edges[t*2-1];
		if(pos[t*2-1]||pos[t*2-2]){
			if(x>e.w){
				int res=pos[t*2-1]?pos[t*2-1]:pos[t*2-2];
				printf("%lld\n",min(d[1]+x-e.w,rt->query(res)));
			}
			else printf("%lld\n",d[1]+x-e.w);
		}
		else{
			if(x>e.w) printf("%lld\n",d[1]);
			else{
				ll res=inf;
				if(d1[e.u]<inf&&d[e.v]<inf) res=min(res,d1[e.u]+d[e.v]);
				if(d1[e.v]<inf&&d[e.u]<inf) res=min(res,d1[e.v]+d[e.u]);
				printf("%lld\n",min(d[1],res+x));
			}
		}
	}
	return 0;
}