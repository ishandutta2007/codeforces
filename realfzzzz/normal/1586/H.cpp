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
int n,q,e[maxn],a[maxn],b[maxn],c[maxn],t[maxn],v[maxn],x[maxn];
struct edge{
	int v,w;
};
vector<edge> g[maxn];
int fa[maxn],dep[maxn],size[maxn],hson[maxn],w[maxn];
void dfs1(int u){
	dep[u]=dep[fa[u]]+1;
	size[u]=1;
	for(edge e:g[u]) if(e.v!=fa[u]){
		fa[e.v]=u;
		w[e.v]=e.w;
		dfs1(e.v);
		size[u]+=size[e.v];
		if(size[e.v]>size[hson[u]]) hson[u]=e.v;
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
	for(edge e:g[u]) if(e.v!=fa[u]&&e.v!=hson[u]){
		top[e.v]=e.v;
		dfs2(e.v);
	}
}
int st[20][maxn],lg[maxn];
void build(){
	for(int i=1;i<n;i++) st[0][i]=w[f[i]];
	for(int i=1;(1<<i)<n;i++)
		for(int j=1;j+(1<<i)-1<n;j++)
			st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	for(int i=2;i<n;i++) lg[i]=lg[i/2]+1;
}
int rmq(int l,int r){
	int k=lg[r-l+1];
	return max(st[k][l],st[k][r-(1<<k)+1]);
}
int query(int x,int y){
	int ans=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ans=max(ans,rmq(pos[top[x]],pos[x]));
		x=fa[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	if(pos[y]<pos[x]) ans=max(ans,rmq(pos[y]+1,pos[x]));
	return ans;
}
int ord[maxn*2];
int p[maxn];
int find(int u){
	return p[u]==u?u:p[u]=find(p[u]);
}
int mx[maxn],tr[maxn];
struct cmp{
	bool operator ()(int a,int b){
		return pos[a]<pos[b];
	}
};
set<int,cmp> s[maxn];
int ans1[maxn],ans2[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	q=readint();
	for(int i=1;i<=n;i++) e[i]=readint();
	for(int i=1;i<n;i++){
		a[i]=readint();
		b[i]=readint();
		c[i]=readint();
		t[i]=readint();
		g[a[i]].push_back({b[i],t[i]});
		g[b[i]].push_back({a[i],t[i]});
	}
	dfs1(1);
	top[1]=1;
	dfs2(1);
	build();
	for(int i=1;i<=q;i++){
		v[i]=readint();
		x[i]=readint();
	}
	for(int i=1;i<q+n;i++) ord[i]=i;
	sort(ord+1,ord+q+n,[](int a,int b){
		int x=a>q?c[a-q]:v[a],y=b>q?c[b-q]:v[b];
		if(x!=y) return x>y;
		return a>q&&b<=q;
	});
	for(int i=1;i<=n;i++){
		p[i]=i;
		mx[i]=e[i];
		s[i]={i};
	}
	for(int i=1;i<q+n;i++)
		if(ord[i]<=q){
			int u=x[ord[i]],v=find(u);
			ans1[ord[i]]=mx[v];
			ans2[ord[i]]=tr[v];
			auto it=s[v].upper_bound(u);
			if(it!=s[v].begin())
				ans2[ord[i]]=max(ans2[ord[i]],query(u,*--it));
			it=s[v].lower_bound(u);
			if(it!=s[v].end())
				ans2[ord[i]]=max(ans2[ord[i]],query(u,*it));
		}
		else{
			int u=find(a[ord[i]-q]),v=find(b[ord[i]-q]);
			if(mx[u]!=mx[v]){
				if(mx[u]>mx[v]) p[v]=u;
				else p[u]=v;
				continue;
			}
			p[v]=u;
			if(s[u].size()<s[v].size()){
				swap(s[u],s[v]);
				swap(tr[u],tr[v]);
			}
			for(int w:s[v]){
				auto it=s[u].upper_bound(w);
				if(it!=s[u].begin()) tr[u]=max(tr[u],query(w,*--it));
				it=s[u].lower_bound(w);
				if(it!=s[u].end()) tr[u]=max(tr[u],query(w,*it));
				s[u].insert(w);
			}
			s[v]={};
		}
	for(int i=1;i<=q;i++) printf("%d %d\n",ans1[i],ans2[i]);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}