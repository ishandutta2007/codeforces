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
int n,q;
vector<int> g[maxn];
int fa[maxn],size[maxn],dep[maxn],hson[maxn];
void dfs1(int u){
	dep[u]=u?dep[fa[u]]+1:1;
	size[u]=1;
	for(int v:g[u]) if(v!=fa[u]){
		fa[v]=u;
		dfs1(v);
		size[u]+=size[v];
		if(size[v]>size[hson[u]]) hson[u]=v;
	}
}
vector<int> f;
int pos[maxn],top[maxn];
void dfs2(int u){
	pos[u]=f.size();
	f.push_back(u);
	if(!hson[u]) return;
	top[hson[u]]=top[u];
	dfs2(hson[u]);
	for(int v:g[u]) if(v!=fa[u]&&v!=hson[u]){
		top[v]=v;
		dfs2(v);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	return y;
}
int dist(int x,int y){
	return dep[x]+dep[y]-dep[lca(x,y)]*2;
}
int la(int x,int k){
	if(dep[x]<=k) return 1;
	while(dep[x]-dep[top[x]]<k){
		k-=dep[x]-dep[top[x]]+1;
		x=fa[top[x]];
	}
	return f[pos[x]-k];
}
int c[maxn];
inline int lowbit(int x){
	return x&-x;
}
void modify(int x,int k){
	while(x<=n){
		c[x]+=k;
		x+=lowbit(x);
	}
}
int query(int x){
	int s=0;
	while(x){
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
struct data{
	int x,y;
	bool operator <(const data b)const{
		return dist(x,y)<dist(b.x,b.y);
	}
	data operator +(data b){
		if(!x) return b;
		if(!b.x) return *this;
		data c=max(*this,b);
		c=max(c,max((data){x,b.x},{y,b.y}));
		c=max(c,max((data){x,b.y},{y,b.x}));
		return c;
	}
};
struct node{
	int l,r;
	node* ch[2];
	data val={0,0};
	void pushup(){
		val=ch[0]->val+ch[1]->val;
	}
	node(int l,int r):l(l),r(r){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
	}
	void modify(int x,data k){
		if(l==r){
			val=k;
			return;
		}
		if(x<=ch[0]->r) ch[0]->modify(x,k);
		else ch[1]->modify(x,k);
		pushup();
	}
	data query(int ql,int qr){
		if(ql<=l&&qr>=r) return val;
		data ans={0,0};
		if(ql<=ch[0]->r) ans=ans+ch[0]->query(ql,qr);
		if(qr>=ch[1]->l) ans=ans+ch[1]->query(ql,qr);
		return ans;
	}
}*rt;
struct cmp{
	bool operator ()(int a,int b){
		if(dep[a]!=dep[b]) return dep[a]<dep[b];
		return a<b;
	}
};
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	q=readint();
	for(int i=1;i<n;i++){
		int x,y;
		x=readint();
		y=readint();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs1(1);
	top[1]=1;
	dfs2(1);
	multiset<int,cmp> s;
	rt=new node(0,n-1);
	while(q--){
		int opt=readint();
		if(opt==1){
			int u,v;
			u=readint();
			v=readint();
			int w=lca(u,v);
			s.insert(w);
			modify(pos[u]+1,1);
			modify(pos[v]+1,1);
			modify(pos[w]+1,-1);
			rt->modify(pos[w],{w,w});
		}
		else if(opt==2){
			int u,v;
			u=readint();
			v=readint();
			int w=lca(u,v);
			s.erase(s.find(w));
			modify(pos[u]+1,-1);
			modify(pos[v]+1,-1);
			modify(pos[w]+1,1);
			if(s.find(w)==s.end()) rt->modify(pos[w],{0,0});
		}
		else{
			int d=readint(),x=la(*--s.end(),d),y=la(x,d);
			data res=rt->query(pos[y],pos[y]+size[y]-1);
			if(query(pos[y]+size[y])-query(pos[y])!=(int)s.size()) printf("No\n");
			else if(res.x&&(dist(x,res.x)>d||dist(x,res.y)>d)) printf("No\n");
			else printf("Yes\n");
		}
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}