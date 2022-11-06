#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=100000;
int l[maxn+10],r[maxn+10],v[maxn+10],sz[maxn+10],n,m; double ans;
vector<int> g[maxn+10];
void dfs(int x){
	sz[x]=1;
	for(int i=0;i<g[x].size();++i){
		int e=g[x][i]; if(!sz[e]) dfs(e),sz[x]+=sz[e];
	}
}
ll work(int x){
	ll v1=min(sz[l[x]],sz[r[x]]),v2=n-v1;
	return (v1*(v1-1)*v2+v1*v2*(v2-1))*v[x];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d%d%d",&l[i],&r[i],&v[i]);
		g[l[i]].push_back(r[i]); g[r[i]].push_back(l[i]);
	}
	dfs(1);
	for(int i=1;i<n;++i) ans+=work(i);
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		int x,y; scanf("%d%d",&x,&y);
		ans-=work(x); v[x]=y; ans+=work(x);
		printf("%.10lf\n",ans*6/n/(n-1)/(n-2));
	}
	return 0;
}