#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005;
int T,x[N];
bool vis[N],bad[N];
vector<int>e[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		int n,K;
		scanf("%d%d",&n,&K);
		rep(i,1,n)e[i].clear(),vis[i]=0,bad[i]=0;
		queue<int>q;
		rep(i,1,K)scanf("%d",&x[i]),q.push(x[i]),bad[x[i]]=i,vis[x[i]]=1;
		vis[1]=1,q.push(1);
		rep(i,2,n){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].pb(v),e[v].pb(u);
		}
		while(!q.empty()){
			int k1=q.front();
			q.pop();
			for(auto y:e[k1]){
				if(!vis[y]){
					vis[y]=1;
					bad[y]=bad[k1];
					q.push(y);
				}
			}
		}
		int flg=0;
		rep(i,2,n)if(SZ(e[i])==1&&!bad[i])flg=1;
		if(flg){
			puts("-1");
		}else{
			int tot=0;
			rep(i,1,n)if(!bad[i]){
				for(auto y:e[i])if(bad[y]){
					++tot;
				}
			}
			printf("%d\n",tot);
		}
	}
	return 0;
}