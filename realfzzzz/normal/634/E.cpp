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
int n,k,a[maxn];
vector<int> g[maxn];
int mid,fa[maxn],size[maxn],f[maxn];
void dfs1(int u){
	size[u]=1;
	for(int v:g[u]) if(v!=fa[u]){
		fa[v]=u;
		dfs1(v);
		size[u]+=size[v];
	}
	if(a[u]<mid){
		f[u]=0;
		return;
	}
	f[u]=1;
	int mx=0;
	for(int v:g[u]) if(v!=fa[u]){
		if(f[v]==size[v]) f[u]+=f[v];
		else mx=max(mx,f[v]);
	}
	f[u]+=mx;
}
int size2[maxn],f2[maxn],res;
void dfs2(int u){
	f2[u]=1;
	multiset<int> s={0};
	for(int v:g[u])
		if(f2[v]==size2[v]) f2[u]+=f2[v];
		else s.insert(f2[v]);
	if(a[u]>=mid) res=max(res,f2[u]+*--s.end());
	else f2[u]=0;
	for(int v:g[u]) if(v!=fa[u]){
		if(a[u]>=mid){
			if(f[v]==size[v]) f2[u]-=f[v];
			else s.erase(s.find(f[v]));
			f2[u]+=*--s.end();
		}
		size2[u]=n-size[v];
		dfs2(v);
		if(a[u]>=mid){
			f2[u]-=*--s.end();
			if(f[v]==size[v]) f2[u]+=f[v];
			else s.insert(f[v]);
		}
	}
	f2[u]=f[u];
	size2[u]=size[u];
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<n;i++){
		int u,v;
		u=readint();
		v=readint();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int l=1,r=1e6;
	while(l<r){
		mid=l+(r-l+1)/2;
		dfs1(1);
		for(int i=1;i<=n;i++){
			size2[i]=size[i];
			f2[i]=f[i];
		}
		res=0;
		dfs2(1);
		if(res>=k) l=mid;
		else r=mid-1;
	}
	printf("%d\n",r);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}