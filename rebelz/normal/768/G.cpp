// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,rt,tot;
int v[200005],nxt[200005],h[100005],siz[100005],son[100005],ans[100005];
multiset<int> s1,s2,s3;

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs1(v[p],u);
		siz[u]+=siz[v[p]];
		if(siz[v[p]]>siz[son[u]]) son[u]=v[p];
	}
}

void add(int u,int fa){
	s1.insert(siz[u]);
	for(int p=h[u];p;p=nxt[p]) if(v[p]!=fa) add(v[p],u);
}

void del(int u,int fa){
	s1.erase(s1.find(siz[u]));
	for(int p=h[u];p;p=nxt[p]) if(v[p]!=fa) del(v[p],u);
}

void dfs2(int u,int fa){
	int mx1=0,mx2=0,mn=n-siz[u];
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		chkmin(mn,siz[v[p]]);
		if(siz[v[p]]>mx1) mx2=mx1,mx1=siz[v[p]];
		else chkmax(mx2,siz[v[p]]);
	}
	ans[u]=max(mx1,n-siz[u]);
	if(mx1<=n-siz[u]){
		auto it=s1.lower_bound((ans[u]-mn)/2);
		if(it!=s1.end()) chkmin(ans[u],max(mx1,max(mn+*it,n-siz[u]-*it)));
		if(it!=s1.begin()){
			it--;
			chkmin(ans[u],max(mx1,max(mn+*it,n-siz[u]-*it)));
		}
		it=s2.lower_bound((max(mx1,n-siz[u])-mn)/2+siz[u]);
		if(it!=s2.end()) chkmin(ans[u],max(mx1,max(mn+*it-siz[u],n-siz[u]-*it+siz[u])));
		if(it!=s2.begin()){
			it--;
			chkmin(ans[u],max(mx1,max(mn+*it-siz[u],n-siz[u]-*it+siz[u])));
		}
	}
	for(int p=h[u];p;p=nxt[p]) if(v[p]!=fa&&v[p]!=son[u]) add(v[p],u);
	if(u!=rt) s2.insert(siz[u]);
	if(son[u]) dfs2(son[u],u);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa||v[p]==son[u]) continue;
		del(v[p],u);
		dfs2(v[p],u);
	}
	s1.insert(siz[u]);
	if(u!=rt) s2.erase(siz[u]);
}

void add3(int u,int fa){
	s3.insert(siz[u]);
	for(int p=h[u];p;p=nxt[p]) if(v[p]!=fa) add3(v[p],u);
}

void dfs3(int u,int fa){
	int mx1=0,mx2=0,mn=siz[u]==n?n+1:n-siz[u];
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		chkmin(mn,siz[v[p]]);
		if(siz[v[p]]>mx1) mx2=mx1,mx1=siz[v[p]];
		else chkmax(mx2,siz[v[p]]);
	}
	int pl=0;
	if(mx1>n-siz[u]){
		chkmax(mx2,n-siz[u]);
		for(int p=h[u];p;p=nxt[p]) if(v[p]!=fa&&siz[v[p]]==mx1) pl=v[p];
	}
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]!=fa&&v[p]!=son[u]){
			dfs3(v[p],u);
			if(v[p]==pl){
				auto it=s3.lower_bound((mx1-mn)/2);
				if(it!=s3.end()) chkmin(ans[u],max(mx2,max(mx1-*it,mn+*it)));
				if(it!=s3.begin()){
					it--;
					chkmin(ans[u],max(mx2,max(mx1-*it,mn+*it)));
				}
			}
			s3.clear();
		}
	}
	if(son[u]){
		dfs3(son[u],u);
		if(son[u]==pl){
			auto it=s3.lower_bound((mx1-mn)/2);
			if(it!=s3.end()) chkmin(ans[u],max(mx2,max(mx1-*it,mn+*it)));
			if(it!=s3.begin()){
				it--;
				chkmin(ans[u],max(mx2,max(mx1-*it,mn+*it)));
			}
		}
		s3.insert(siz[son[u]]);
	}
	for(int p=h[u];p;p=nxt[p]) if(v[p]!=fa&&v[p]!=son[u]) add3(v[p],u);
}

int main(){
	n=readint();
	int x,y;
	for(int i=1;i<=n;i++){
		x=readint(); y=readint();
		if(!x) rt=y;
		else addedge(x,y);
	}
	dfs1(rt,-1);
	dfs2(rt,-1);
	dfs3(rt,-1);
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}