#include<bits/stdc++.h>
using namespace std;
using ll=long long;
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
const int maxn=1e5+5;
int n,m,q,w[maxn];
vector<int> g[maxn],g2[maxn*2];
int dep1[maxn],low[maxn],cnt=0,st[maxn],tp=0;
void dfs(int u,int fa){
	low[u]=dep1[u]=dep1[fa]+1;
	st[++tp]=u;
	for(int v:g[u]){
		if(dep1[v]){
			low[u]=min(low[u],dep1[v]);
			continue;
		}
		dfs(v,u);
		low[u]=min(low[u],low[v]);
		if(low[v]==dep1[u]){
			cnt++;
			g2[u].push_back(n+cnt);
			g2[n+cnt].push_back(u);
			while(st[tp+1]!=v){
				g2[st[tp]].push_back(n+cnt);
				g2[n+cnt].push_back(st[tp]);
				tp--;
			}
		}
	}
}
int fa[maxn*2],dep[maxn*2],sz[maxn*2],son[maxn*2];
void dfs1(int u){
	dep[u]=dep[fa[u]]+1;
	sz[u]=1;
	for(int v:g2[u]) if(v!=fa[u]){
		fa[v]=u;
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
int cnt2=0,pos[maxn*2],top[maxn*2];
void dfs2(int u){
	pos[u]=cnt2++;
	top[u]=son[fa[u]]==u?top[fa[u]]:u;
	if(son[u]) dfs2(son[u]);
	for(int v:g2[u]) if(v!=fa[u]&&v!=son[u]) dfs2(v);
}
multiset<int> s[maxn];
const int inf=2e9;
struct node{
	int l,r;
	node* ch[2];
	int mn=2e9;
	void pushup(){
		mn=min(ch[0]->mn,ch[1]->mn);
	}
	node(int l,int r):l(l),r(r){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
	}
	void modify(int x,int k){
		if(l==r){
			mn=k;
			return;
		}
		if(x<=ch[0]->r) ch[0]->modify(x,k);
		else ch[1]->modify(x,k);
		pushup();
	}
	int query(int ql,int qr){
		if(ql>r||qr<l) return inf;
		if(ql<=l&&qr>=r) return mn;
		return min(ch[0]->query(ql,qr),ch[1]->query(ql,qr));
	}
}*rt;
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++) w[i]=read();
	for(int i=1;i<=m;i++){
		int a,b;
		a=read();
		b=read();
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,0);
	dfs1(1);
	dfs2(1);
	for(int i=2;i<=n;i++) s[fa[i]-n].insert(w[i]);
	rt=new node(0,n+cnt-1);
	for(int i=1;i<=cnt;i++)
		if(s[i].size()) rt->modify(pos[i+n],*s[i].begin());
	while(q--){
		char opt[5];
		scanf("%s",opt);
		if(opt[0]=='C'){
			int a=read();
			if(a==1){
				w[a]=read();
				continue;
			}
			s[fa[a]-n].erase(s[fa[a]-n].find(w[a]));
			s[fa[a]-n].insert(w[a]=read());
			rt->modify(pos[fa[a]],*s[fa[a]-n].begin());
		}
		else{
			int a,b;
			a=read();
			b=read();
			int ans=inf;
			while(top[a]!=top[b]){
				if(dep[top[a]]<dep[top[b]]) swap(a,b);
				ans=min(ans,rt->query(pos[top[a]],pos[a]));
				a=fa[top[a]];
			}
			if(dep[a]<dep[b]) swap(a,b);
			ans=min(ans,rt->query(pos[b],pos[a]));
			if(b>n) ans=min(ans,w[fa[b]]);
			else ans=min(ans,w[b]);
			printf("%d\n",ans);
		}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}