#include<cstdio>
#include<vector>
using namespace std;
const int maxn=100000;
int n,m,d,md[maxn+10],dep[maxn+10],ans; bool b[maxn+10];
vector<int> g[maxn+10];
void dp(int x,int fa){
	dep[x]=dep[fa]+1; md[x]=-1; if(b[x]) md[x]=dep[x];
	for(int i=0;i<g[x].size();++i){
		int e=g[x][i]; if(e!=fa){
			dp(e,x); md[x]=max(md[x],md[e]);
		}
	}
}
void dfs(int x,int fa,int deplim){
	if(b[x]) deplim=min(deplim,dep[x]+d);
	if(dep[x]>deplim) return;
	if(md[x]-dep[x]<=d) ++ans;
	int firm=-1,scm=-1,firid=0;
	for(int i=0;i<g[x].size();++i){
		int e=g[x][i]; if(e!=fa){
			if(md[e]>firm){
				scm=firm; firm=md[e]; firid=e;
			}else if(md[e]>scm) scm=md[e];
		}
	}
	for(int i=0;i<g[x].size();++i){
		int e=g[x][i]; if(e!=fa){ 
			if(e==firid) if(scm!=-1) dfs(e,x,min(dep[x]+d-scm+dep[x],deplim));
			else dfs(e,x,deplim);
			else if(firm!=-1) dfs(e,x,min(dep[x]+d-firm+dep[x],deplim));
			else dfs(e,x,deplim);
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=m;++i){
		int x; scanf("%d",&x); b[x]=1;
	}
	for(int i=1;i<n;++i){
		int l,r; scanf("%d%d",&l,&r);
		g[l].push_back(r); g[r].push_back(l);
	}
	dp(1,0);
	dfs(1,0,0x3f3f3f3f);
	printf("%d",ans);
}