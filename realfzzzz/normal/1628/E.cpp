#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=3e5+5;
int n,q,u[maxn],v[maxn],w[maxn];
int ord[maxn],p[maxn*2];
int find(int u){
	return p[u]==u?u:p[u]=find(p[u]);
}
int fa[maxn*2],ch[maxn*2][2];
int sz[maxn*2],dep[maxn*2],son[maxn*2];
void dfs1(int u){
	dep[u]=dep[fa[u]]+1;
	sz[u]=1;
	for(int v:{ch[u][0],ch[u][1]}) if(v){
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
vector<int> f;
int pos[maxn],top[maxn*2];
void dfs2(int u){
	if(u<=n){
		pos[u]=f.size();
		f.push_back(u);
	}
	top[u]=son[fa[u]]==u?top[fa[u]]:u;
	for(int v:{ch[u][0],ch[u][1]}) if(v) dfs2(v);
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	return y;
}
struct node{
	int l,r;
	node* ch[2];
	int mn,mn2=n,mx,mx2=-1,tag=-1;
	void pushup(){
		mn2=min(ch[0]->mn2,ch[1]->mn2);
		mx2=max(ch[0]->mx2,ch[1]->mx2);
	}
	node(int l,int r):l(l),r(r){
		if(l==r){
			mn=mx=pos[r];
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
		mn=min(ch[0]->mn,ch[1]->mn);
		mx=max(ch[0]->mx,ch[1]->mx);
	}
	void pushtag(bool k){
		if(k){
			mn2=mn;
			mx2=mx;
		}
		else{
			mn2=n;
			mx2=-1;
		}
		tag=k;
	}
	void pushdown(){
		if(tag>=0){
			ch[0]->pushtag(tag);
			ch[1]->pushtag(tag);
			tag=-1;
		}
	}
	void modify(int ql,int qr,bool k){
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
	n=read();
	q=read();
	for(int i=1;i<n;i++){
		u[i]=read();
		v[i]=read();
		w[i]=read();
	}
	for(int i=1;i<n;i++) ord[i]=i;
	sort(ord+1,ord+n,[](int a,int b){
		return w[a]<w[b];
	});
	for(int i=1;i<n*2;i++) p[i]=i;
	for(int i=1;i<n;i++){
		int x=ord[i];
		ch[n+x][0]=find(u[x]);
		ch[n+x][1]=find(v[x]);
		fa[p[u[x]]]=fa[p[v[x]]]=n+x;
		p[p[u[x]]]=p[p[v[x]]]=n+x;
	}
	dfs1(n+ord[n-1]);
	dfs2(n+ord[n-1]);
	rt=new node(1,n);
	while(q--){
		int opt=read();
		if(opt==1){
			int l,r;
			l=read();
			r=read();
			rt->modify(l,r,1);
		}
		else if(opt==2){
			int l,r;
			l=read();
			r=read();
			rt->modify(l,r,0);
		}
		else{
			int x=read(),mn=rt->mn2,mx=rt->mx2;
			mn=min(mn,pos[x]);
			mx=max(mx,pos[x]);
			printf("%d\n",mn==mx?-1:w[lca(f[mn],f[mx])-n]);
		}
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}