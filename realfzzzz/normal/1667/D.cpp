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
const int maxn=2e5+5;
int n;
vector<int> g[maxn],g2[maxn];
int fa[maxn];
bool f[maxn];
bool dfs1(int u){
	vector<int> vec0,vec1;
	for(int v:g[u]) if(v!=fa[u]){
		fa[v]=u;
		if(!dfs1(v)) return 0;
		if(f[v]) vec1.push_back(v);
		else vec0.push_back(v);
	}
	int cnt0=vec0.size(),cnt1=vec1.size();
	if(u!=1){
		if(cnt0==cnt1+1||cnt0==cnt1+2){
			f[u]=1;
			cnt1++;
			vec1.push_back(u);
		}
		else{
			f[u]=0;
			cnt0++;
			vec0.push_back(u);
		}
	}
	if(cnt0==cnt1||cnt0==cnt1+1){
		for(int i=0;i<cnt1;i++){
			g2[vec0[i]].push_back(vec1[i]);
			if(i<cnt0-1)
				g2[vec1[i]].push_back(vec0[i+1]);
		}
		return 1;
	}
	else return 0;
}
bool vis[maxn];
vector<int> s;
void dfs2(int u){
	vis[u]=1;
	for(int v:g2[u]) if(!vis[v]) dfs2(v);
	s.push_back(u);
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)
			vector<int>().swap(g[i]);
		for(int i=1;i<n;i++){
			int u,v;
			u=read();
			v=read();
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=2;i<=n;i++)
			vector<int>().swap(g2[i]);
		if(!dfs1(1)){
			printf("NO\n");
			continue;
		}
		for(int i=2;i<=n;i++) vis[i]=0;
		vector<int>().swap(s);
		for(int i=2;i<=n;i++) if(!vis[i]) dfs2(i);
		printf("YES\n");
		for(int i:s) printf("%d %d\n",i,fa[i]);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}