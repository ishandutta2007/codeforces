#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,ll> mil;
const int maxn=2e5+50;
const int inf=0x3f3f3f3f;
int n,m;
int A[maxn];
int head[maxn],nxt[maxn<<1],to[maxn<<1],edge_tot;
mil mp[maxn];
mil ans;
void add_edge(int u,int v){nxt[++edge_tot]=head[u];head[u]=edge_tot;to[edge_tot]=v;}
int gcd(int u,int v){return __gcd(u,v);}
void dfs(int u,int f){
	mp[u][A[u]]++;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f)continue;
		dfs(v,u);
		for(mil::iterator it1=mp[u].begin();it1!=mp[u].end();it1++)
			for(mil::iterator it2=mp[v].begin();it2!=mp[v].end();it2++)
				ans[gcd(it1->first,it2->first)]+=it1->second*it2->second;
		for(mil::iterator it=mp[v].begin();it!=mp[v].end();it++)
			mp[u][gcd(A[u],it->first)]+=it->second;
		mp[v].clear();
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]),ans[A[i]]++;
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=200000;i++)if(ans[i])printf("%d %I64d\n",i,ans[i]);
	return 0;
}