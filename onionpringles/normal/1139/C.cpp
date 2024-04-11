#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
#define mul(x,y) ((long long)(x)*(y)%mod)
int mpow(int n,int e){
	if(!e)return 1;
	int t=mpow(n,e/2);
	t=mul(t,t);
	if(e&1)t=mul(t,n);return t;
}
const int N=101010;
vector<int> adj[N];
int chk[N];
int dfs(int u,int p=-1){
	chk[u]=1;
	int cnt=1;
	for(auto &x:adj[u]){
		if(x==p)continue;
		cnt+=dfs(x,u);
	}
	return cnt;
}
int main(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v,t;scanf("%d%d%d",&u,&v,&t);u--;v--;
		if(!t){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	int ans=mpow(n,k);
	for(int i=0;i<n;i++)if(!chk[i]){
		int cnt=dfs(i);
		ans+=mod-mpow(cnt,k);
		if(ans>=mod)ans-=mod;
	}
	printf("%d\n",ans);
}