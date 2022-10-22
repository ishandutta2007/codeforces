#include<bits/stdc++.h>
#define int long long
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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
V<int> v[200005];
int d[200005],to[200005];
bool vis[200005],ff;
void dfs(int x,int fa){
	for(auto u:v[x])if(u!=fa){
		if(vis[u]){
			if(d[u]==d[x]){
				ff=1;
			}
		}else{
			vis[u]=1;
			d[u]=d[x]^1;
			dfs(u,x);
		}
	}
}
void solve(){
	int n,m;ff=0;
	cin>>n>>m;
	FOR(i,1,n)v[i].clear(),d[i]=0,vis[i]=0;
	FOR(i,1,n)cin>>to[i];
	FOR(i,1,n){
		int x;
		cin>>x;
		to[i]=x-to[i];
	}
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	if(1){
		d[1]=0;vis[1]=1;
		dfs(1,-1);
		if(!ff){
			int sum=0;
			FOR(i,1,n){
				if(d[i]&1)sum+=to[i];
				else sum-=to[i];
			}
			if(sum==0){
				cout<<"YES\n";RE ;
			}else cout<<"NO\n";
			RE ;
		}
		int sum=0;
		FOR(i,1,n)sum+=to[i];
		if(sum%2==0){
			cout<<"YES\n";RE ;
		}else {
			cout<<"NO\n";RE;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}