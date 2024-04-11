#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005;
int T,n,fa[N],p[N],w[N],dis[N];
bool vis[N];
vector<int>e[N];
void sol(){
	scanf("%d",&n);
	rep(i,1,n)e[i].clear(),vis[i]=0;
	rep(i,1,n){
		scanf("%d",&fa[i]);
		if(fa[i]==i){
			fa[i]=0;
		}else{
			e[fa[i]].pb(i);
		}
	}
	rep(i,1,n)scanf("%d",&p[i]);
	vis[0]=1;
	int cur=0;
	rep(i,1,n){
		int u=p[i];
		if(!vis[fa[u]]){
			puts("-1");
			return;
		}
		vis[u]=1;
		w[u]=cur-dis[fa[u]];
		dis[u]=cur++;
	}
	rep(i,1,n)printf("%d%c",w[i],i==n?'\n':' ');
}
int main(){
	scanf("%d",&T);
	while(T--){
		sol();
	}
	return 0;
}