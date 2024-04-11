#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
int n,a[1005],val[1005],it[1005],pos[1005];
P<int,int> p[1005];
bool vis[1005];
V<int> node[1005];
bool dfs(int x){
	for(auto i:node[x])if(val[x]%a[i]==0&&pos[x]!=i&&!vis[i]){
		vis[i]=1;
		if(!it[i]||dfs(it[i])){
			pos[x]=i;it[i]=x;RE 1;
		}
	}
	RE 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n){
		FOR(j,1,n)p[j]=MP((val[i-1]/a[j]+1)*a[j],j);
		sort(p+1,p+n+1);
		FILL(vis,0);
		FOR(j,1,n){
			vis[p[j].S]=1;
			if(!it[p[j].S]||dfs(it[p[j].S])){
				pos[i]=p[j].S;val[i]=p[j].F;it[p[j].S]=i;break;
			}
		}
		FOR(j,1,n)if(val[i]%a[j]==0)node[i].PB(j);
	}
	ll ans=0;
	FOR(i,1,n)ans+=val[i];
	cout<<ans;
	RE 0;
}