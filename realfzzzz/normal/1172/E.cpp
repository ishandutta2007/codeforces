#include<vector>
#include<cctype>
#include<cstdio>
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
const int maxn=4e5+5;
int n,m,c[maxn];
vector<int> g[maxn];
int fa[maxn];
void dfs(int u){
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i];
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs(v);
	}
}
typedef long long ll;
struct lct{
	int fa[maxn],ch[maxn][2],s[maxn],s2[maxn];
	ll ss[maxn];
	void init(){
		for(int i=1;i<=n;i++) s[i]=1;
	}
	void pushup(int x){
		s[x]=s2[x]+1;
		if(ch[x][0]) s[x]+=s[ch[x][0]];
		if(ch[x][1]) s[x]+=s[ch[x][1]];
	}
	bool isroot(int x){
		return !fa[x]||(ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x);
	}
	void rotate(int x){
		int y=fa[x],z=fa[fa[x]];
		if(!isroot(y)) ch[z][ch[z][1]==y]=x;
		bool d=ch[y][1]==x;
		int k=ch[x][!d];
		if(k) fa[k]=y;
		ch[y][d]=k;
		ch[x][!d]=y;
		fa[y]=x;
		fa[x]=z;
		pushup(y);
		pushup(x);
	}
	void splay(int x){
		while(!isroot(x)){
			int y=fa[x],z=fa[fa[x]];
			if(!isroot(y)){
				if((ch[y][1]==x)^(ch[z][1]==y)) rotate(x);
				else rotate(y);
			}
			rotate(x);
		}
	}
	void access(int x){
		int y=0;
		while(x){
			splay(x);
			if(ch[x][1]){
				s2[x]+=s[ch[x][1]];
				ss[x]+=1ll*s[ch[x][1]]*s[ch[x][1]];
			}
			ch[x][1]=y;
			if(y){
				s2[x]-=s[y];
				ss[x]-=1ll*s[y]*s[y];
			}
			y=x;
			x=fa[x];
		}
	}
	int findroot(int x){
		access(x);
		splay(x);
		while(ch[x][0]) x=ch[x][0];
		splay(x);
		return x;
	}
	void link(int x,int y){
		access(y);
		splay(y);
		splay(x);
		fa[x]=y;
		s2[y]+=s[x];
		ss[y]+=1ll*s[x]*s[x];
		pushup(y);
	}
	void cut(int x,int y){
		access(y);
		splay(y);
		splay(x);
		fa[x]=0;
		s2[y]-=s[x];
		ss[y]-=1ll*s[x]*s[x];
		pushup(y);
	}
}t;
typedef pair<int,int> pii;
vector<pii> q[maxn];
bool c2[maxn];
ll query(int u){
	int x=t.findroot(u);
	if(c2[x]) return 1ll*t.s[t.ch[x][1]]*t.s[t.ch[x][1]];
	else return 1ll*t.s[x]*t.s[x];
}
ll modify(int u){
	c2[u]^=1;
	if(c2[u]){
		if(u==1){
			t.access(1);
			return t.ss[1]-1ll*t.s[1]*t.s[1];
		}
		else{
			ll res=-query(u);
			t.cut(u,fa[u]);
			t.access(u);
			res+=t.ss[u];
			if(!c2[fa[u]]) res+=query(fa[u]);
			return res;
		}
	}
	else{
		if(u==1){
			t.access(1);
			return 1ll*t.s[1]*t.s[1]-t.ss[1];
		}
		else{
			t.access(u);
			ll res=-t.ss[u];
			if(!c2[fa[u]]) res-=query(fa[u]);
			t.link(u,fa[u]);
			res+=query(u);
			return res;
		}
	}
}
ll ans[maxn];
void solve(int c){
	for(int i=0;i<(int)q[c].size();i++)
		ans[q[c][i].first]+=modify(q[c][i].second);
	for(int i=(int)q[c].size()-1;i>=0;i--)
		modify(q[c][i].second);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	for(int i=1;i<=n;i++) c[i]=readint();
	for(int i=1;i<n;i++){
		int u,v;
		u=readint();
		v=readint();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	t.init();
	for(int i=2;i<=n;i++) t.link(i,fa[i]);
	for(int i=1;i<=n;i++) q[c[i]].push_back(pii(0,i));
	for(int i=1;i<=m;i++){
		int u,x;
		u=readint();
		x=readint();
		q[c[u]].push_back(pii(i,u));
		q[c[u]=x].push_back(pii(i,u));
	}
	for(int i=1;i<=n;i++) solve(i);
	for(int i=1;i<=m;i++) ans[i]+=ans[i-1];
	for(int i=0;i<=m;i++) printf("%lld\n",-ans[i]);
	return 0;
}