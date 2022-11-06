#include<cstdio>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=200000;
vector<int> g[maxn+10]; int ans[maxn+10];
int n,a[maxn+10],dfn[maxn+10],ed[maxn+10],dep[maxn+10],dfscnt,c[maxn+10];
void add(int i){for(;i<=n;i+=i&-i) ++c[i];}
int query(int i){int ans=0; for(;i;i-=i&-i) ans+=c[i]; return ans;}
struct node{
	int val,id,op;
	bool operator<(const node &t)const{
		return val==t.val?op<t.op:val<t.val;
	}
}b[maxn*2+10];
void dfs(int x){
	dfn[x]=++dfscnt;
	for(int i=0;i<g[x].size();++i){
		dep[g[x][i]]+=dep[x]; dfs(g[x][i]);
	}
	ed[x]=dfscnt;
}
main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int i=2;i<=n;++i){
		int x; scanf("%lld%lld",&x,&dep[i]);
		g[x].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=n;++i){
		b[i*2-1]=(node){dep[i]-a[i],i,0}; b[i*2]=(node){dep[i],i,1};
	}
	sort(b+1,b+n*2+1);
	for(int i=1;i<=n*2;++i)
		if(!b[i].op) add(dfn[b[i].id]);
		else ans[b[i].id]=query(ed[b[i].id])-query(dfn[b[i].id]);
	for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
}