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
V<int> v[300005];
bool vis[300005];
bool col[300005];
void solve(){
	int n;
	int m;
	cin>>n>>m;
	FOR(i,1,n)vis[i]=0,col[i]=1,v[i].clear();
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	queue<int> q;
	q.emplace(1);vis[1]=1;
	V<int> ans;
	while(!q.empty()){
		int cur=q.front();q.pop();
		if(col[cur]){
			for(auto u:v[cur]){
				col[u]=0;
			}
			ans.PB(cur);
		}
		for(auto u:v[cur]){
			if(!vis[u]){
				vis[u]=1;
				q.emplace(u);
			}
		}
	}
	FOR(i,1,n){
		if(!vis[i]){
			cout<<"NO\n";RE;
		}
	}
	cout<<"YES\n";
	cout<<ans.size()<<'\n';
	for(auto u:ans)cout<<u<<' ';
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	while(n--)solve();
	RE 0;
}