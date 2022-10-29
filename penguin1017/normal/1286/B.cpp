#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define lb(x) ((x)&(-x))
#define pb push_back
using namespace std;
const int N=2e3+9;
vi g[N];
int sum[N],n,fa[N],sz[N],c[N],a[N],flag,rt;
void Set(int p,int val){
	for(int i=p;i<N;i+=lb(i))sum[i]+=val;
} 
int Get(int p){
	int res=0;
	for(int i=p;i;i^=lb(i))res+=sum[i];
	return res;
}
int find(int val){
	int l=1,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(Get(mid)<val)l=mid+1;
		else r=mid;
	}
	Set(r,-1);
	return r;
}
void dfs(int u,int fa){
	sz[u]++;
	for(auto v:g[u]){
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
void dfs2(int u,int fa){
	if(sz[u]<=c[u])flag=1;
	a[u]=find(c[u]+1);
	for(auto v:g[u]){
		if(flag)return;
		dfs2(v,u);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n+1){
		scanf("%d%d",&fa[i],&c[i]);
		if(!fa[i])rt=i;
		else g[fa[i]].pb(i);
	}
	rep(i,1,n+1)Set(i,1);
	dfs(rt,-1);
	dfs2(rt,-1);
//	cout<<"OK\n";
	if(flag){
		printf("NO");
	}
	else{
		printf("YES\n");
		rep(i,1,n+1)printf("%d ",a[i]);
	}
}