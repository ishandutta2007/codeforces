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
const int maxn=1.5e5+5;
int n,m,k,s[maxn],t[maxn];
vector<int> g[maxn];
int fa[maxn],dep[maxn],size[maxn],hson[maxn];
void dfs1(int u){
	dep[u]=dep[fa[u]]+1;
	size[u]=1;
	for(int v:g[u]){
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs1(v);
		size[u]+=size[v];
		if(size[v]>size[hson[u]]) hson[u]=v;
	}
}
int pos[maxn],top[maxn];
vector<int> f;
void dfs2(int u){
	pos[u]=f.size();
	f.push_back(u);
	if(!hson[u]) return;
	top[hson[u]]=top[u];
	dfs2(hson[u]);
	for(int v:g[u]){
		if(v==fa[u]||v==hson[u]) continue;
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
int jump(int x,int k){
	while(pos[x]-pos[top[x]]<k){
		k-=pos[x]-pos[top[x]]+1;
		x=fa[top[x]];
	}
	return f[pos[x]-k];
}
struct node{
	int l,r;
	node* ch[2];
	int s;
	node(int l,int r):l(l),r(r),s(0){
		ch[0]=ch[1]=0;
	}
	void modify(int x,int k){
		s+=k;
		if(l==r) return;
		int mid=l+(r-l)/2;
		if(x<=mid){
			if(!ch[0]) ch[0]=new node(l,mid);
			ch[0]->modify(x,k);
		}
		else{
			if(!ch[1]) ch[1]=new node(mid+1,r);
			ch[1]->modify(x,k);
		}
	}
	int query(int ql,int qr){
		if(ql<=l&&qr>=r) return s;
		int ans=0;
		if(ch[0]&&ql<=ch[0]->r) ans+=ch[0]->query(ql,qr);
		if(ch[1]&&qr>=ch[1]->l) ans+=ch[1]->query(ql,qr);
		return ans;
	}
};
node* merge(node* a,node* b){
	if(!a) return b;
	if(!b) return a;
	node* x=new node(a->l,a->r);
	x->s=a->s+b->s;
	x->ch[0]=merge(a->ch[0],b->ch[0]);
	x->ch[1]=merge(a->ch[1],b->ch[1]);
	return x;
}
int l[maxn];
vector<int> q[maxn];
long long ans=0;
node* rt1;
void dfs3(int u){
	for(int i:q[u]){
		if(dep[s[i]]-dep[u]>=k){
			int x=jump(s[i],dep[s[i]]-dep[u]-k);
			ans+=rt1->query(pos[x],pos[x]+size[x]-1);
		}
		if(dep[t[i]]-dep[u]>=k){
			int x=jump(t[i],dep[t[i]]-dep[u]-k);
			ans+=rt1->query(pos[x],pos[x]+size[x]-1);
		}
	}
	for(int i:q[u]){
		rt1->modify(pos[s[i]],1);
		rt1->modify(pos[t[i]],1);
	}
	for(int v:g[u]){
		if(v==fa[u]) continue;
		dfs3(v);
	}
	for(int i:q[u]){
		rt1->modify(pos[s[i]],-1);
		rt1->modify(pos[t[i]],-1);
	}
}
bool cmp(int a,int b){
	if(l[a]!=l[b]) return l[a]<l[b];
	if(pos[s[a]]!=pos[s[b]]) return pos[s[a]]<pos[s[b]];
	return a<b;
}
int ord[maxn],pos2[maxn];
node* rt2[maxn];
void dfs4(int u){
	for(int v:g[u]){
		if(v==fa[u]) continue;
		dfs4(v);
		rt2[u]=merge(rt2[u],rt2[v]);
	}
}
int mn[maxn],mx[maxn];
set<int> st[maxn];
void insert(int u,int x){
	set<int>::iterator it1,it2;
	it1=st[u].lower_bound(mn[l[x]]);
	it2=st[u].upper_bound(mx[l[x]]);
	if(dep[u]+dep[t[x]]-dep[l[x]]*2>=k){
		int v=l[x];
		if(dep[u]-dep[l[x]]<k)
			v=jump(t[x],dep[u]+dep[t[x]]-dep[l[x]]*2-k);
		if(it1!=it2) ans+=rt2[v]->query(*it1,*--it2);
	}
}
void dfs5(int u){
	if(!hson[u]) return;
	dfs5(hson[u]);
	if(st[u].size()<st[hson[u]].size()) swap(st[u],st[hson[u]]);
	for(int i:st[hson[u]]) insert(u,ord[i]);
	for(int i:st[hson[u]]) st[u].insert(i);
	set<int>().swap(st[hson[u]]);
	for(int v:g[u]){
		if(v==fa[u]||v==hson[u]) continue;
		dfs5(v);
		if(st[u].size()<st[v].size()) swap(st[u],st[v]);
		for(int i:st[v]) insert(u,ord[i]);
		for(int i:st[v]) st[u].insert(i);
		set<int>().swap(st[v]);
	}
	for(int i:q[u]) st[u].erase(pos2[i]);
}
node* rt3;
void dfs6(int u){
	sort(q[u].begin(),q[u].end(),cmp);
	for(int i:q[u]){
		if(dep[s[i]]-dep[u]>=k){
			int x=jump(s[i],dep[s[i]]-dep[u]-k);
			ans+=rt3->query(pos[x],pos[x]+size[x]-1);
		}
		rt3->modify(pos[t[i]],1);
	}
	for(int i:q[u]) rt3->modify(pos[t[i]],-1);
	for(int v:g[u]){
		if(v==fa[u]) continue;
		dfs6(v);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	k=readint();
	for(int i=1;i<n;i++){
		int u,v;
		u=readint();
		v=readint();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1);
	top[1]=1;
	dfs2(1);
	for(int i=1;i<=m;i++){
		s[i]=readint();
		t[i]=readint();
		if(pos[s[i]]>pos[t[i]]) swap(s[i],t[i]);
	}
	for(int i=1;i<=m;i++){
		l[i]=lca(s[i],t[i]);
		q[l[i]].push_back(i);
	}
	rt1=new node(0,n-1);
	dfs3(1);
	for(int i=1;i<=m;i++) ord[i]=i;
	sort(ord+1,ord+m+1,cmp);
	for(int i=1;i<=m;i++) pos2[ord[i]]=i;
	for(int i=1;i<=n;i++) rt2[i]=new node(1,m);
	for(int i=1;i<=m;i++) rt2[t[i]]->modify(pos2[i],1);
	dfs4(1);
	for(int i=1;i<=n;i++){
		mn[i]=m+1;
		mx[i]=0;
	}
	for(int i=1;i<=m;i++){
		mn[l[i]]=min(mn[l[i]],pos2[i]);
		mx[l[i]]=max(mx[l[i]],pos2[i]);
	}
	for(int i=1;i<=m;i++){
		insert(s[ord[i]],ord[i]);
		st[s[ord[i]]].insert(i);
	}
	dfs5(1);
	rt3=new node(0,n-1);
	dfs6(1);
	printf("%lld\n",ans);
	return 0;
}