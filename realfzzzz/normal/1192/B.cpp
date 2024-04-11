#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
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
const int maxn=1e5+5;
int n,q,a[maxn],b[maxn];
ll w,c[maxn];
struct edge{
	int v;
	ll w;
};
vector<edge> g[maxn];
int fa[maxn],pos[maxn],pos2[maxn];
vector<int> f;
ll d[maxn];
void dfs(int u){
	pos[u]=f.size();
	f.push_back(u);
	for(edge e:g[u]) if(e.v!=fa[u]){
		fa[e.v]=u;
		d[e.v]=d[u]+e.w;
		dfs(e.v);
		f.push_back(u);
	}
	pos2[u]=f.size()-1;
}
struct data{
	ll l,r,m,lm,mr,lmr;
	data operator +(data b){
		data c;
		c.l=max(l,b.l);
		c.r=max(r,b.r);
		c.m=min(m,b.m);
		c.lm=max(max(lm,b.lm),l-b.m*2);
		c.mr=max(max(mr,b.mr),b.r-m*2);
		c.lmr=max(max(lmr,b.lmr),max(lm+b.r,l+b.mr));
		return c;
	}
};
struct node{
	int l,r;
	node* ch[2];
	data val;
	ll add=0;
	void pushup(){
		val=ch[0]->val+ch[1]->val;
	}
	node(int l,int r):l(l),r(r){
		if(l==r){
			val={d[f[r]],d[f[r]],d[f[r]],-d[f[r]],-d[f[r]],0};
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
		pushup();
	}
	void pushtag(ll k){
		val.l+=k;
		val.r+=k;
		val.m+=k;
		val.lm-=k;
		val.mr-=k;
		add+=k;
	}
	void pushdown(){
		ch[0]->pushtag(add);
		ch[1]->pushtag(add);
		add=0;
	}
	void modify(int ql,int qr,ll k){
		if(ql<=l&&qr>=r){
			pushtag(k);
			return;
		}
		pushdown();
		if(ql<=ch[0]->r) ch[0]->modify(ql,qr,k);
		if(qr>=ch[1]->l) ch[1]->modify(ql,qr,k);
		pushup();
	}
}*rt;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	q=readint();
	w=readint();
	for(int i=0;i<n-1;i++){
		a[i]=readint();
		b[i]=readint();
		c[i]=readint();
		g[a[i]].push_back({b[i],c[i]});
		g[b[i]].push_back({a[i],c[i]});
	}
	dfs(1);
	rt=new node(0,n*2-2);
	ll last=0;
	while(q--){
		int d=(readint()+last)%(n-1);
		ll e=(readint()+last)%w;
		int u=fa[a[d]]==b[d]?a[d]:b[d];
		rt->modify(pos[u],pos2[u],e-c[d]);
		c[d]=e;
		printf("%lld\n",last=rt->val.lmr);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}