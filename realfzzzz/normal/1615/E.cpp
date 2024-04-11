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
const int maxn=2e5+5;
int n,k;
vector<int> g[maxn];
int fa[maxn],pos[maxn],size[maxn],dep[maxn];
vector<int> f;
void dfs(int u){
	pos[u]=f.size();
	f.push_back(u);
	dep[u]=dep[fa[u]]+1;
	size[u]=1;
	for(int v:g[u]) if(v!=fa[u]){
		fa[v]=u;
		dfs(v);
		size[u]+=size[v];
	}
}
struct data{
	int val,pos;
	bool operator <(const data b)const{
		return val<b.val;
	}
};
struct node{
	int l,r;
	node* ch[2];
	data mx;
	int add=0;
	void pushup(){
		mx=max(ch[0]->mx,ch[1]->mx);
	}
	node(int l,int r):l(l),r(r){
		if(l==r){
			mx={dep[f[r]],r};
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
		pushup();
	}
	void pushtag(int k){
		mx.val+=k;
		add+=k;
	}
	void pushdown(){
		ch[0]->pushtag(add);
		ch[1]->pushtag(add);
		add=0;
	}
	void modify(int ql,int qr,int k){
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
bool vis[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	k=readint();
	for(int i=1;i<n;i++){
		int u,v;
		u=readint();
		v=readint();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	rt=new node(0,n-1);
	int s=0;
	ll ans=-1ll*n/2*(n-n/2);
	for(int i=1;i<=k;i++){
		s+=rt->mx.val;
		int u=f[rt->mx.pos];
		while(u&&!vis[u]){
			rt->modify(pos[u],pos[u]+size[u]-1,-1);
			vis[u]=1;
			u=fa[u];
		}
		ans=max(ans,1ll*i*(n-i)-1ll*min(n-s,n/2)*(n-min(n-s,n/2)));
	}
	printf("%lld\n",ans);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}