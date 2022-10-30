#pragma GCC optimize("Ofast")
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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
V<int> v[500005],ans;
int n,a[500005],l[500005]; 
V<bool> f[500005];
bool vis[500005];
priority_queue<P<int,int>,V<P<int,int>>,greater<P<int,int>>> q;
void solve(){
	while(!q.empty()){
		P<int,int> cur=q.top();q.pop();
		ans.PB(cur.S);
		for(auto u:v[cur.S]){
			if(cur.F>=f[u].size())continue;
			f[u][cur.F]=1;
			while(f[u].size()>l[u]&&f[u][l[u]]){
				l[u]++;
			}
			if(l[u]>=a[u]){
				cout<<-1;exit(0);
			}
			if(l[u]==a[u]-1&&!vis[u]){
				vis[u]=1;
				q.emplace(MP(l[u],u));
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	int x,y;
	FOR(i,1,m){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	FOR(i,1,n)cin>>a[i],f[i].resize(v[i].size()+1,0);
	FOR(i,1,n){
		if(a[i]==1){
			q.emplace(MP(0,i));vis[i]=1;
		}
	}
	solve();
	FOR(i,1,n){
		if(!vis[i]){
			cout<<-1;RE 0;
		}
	}
	for(auto u:ans)cout<<u<<' ';
	RE 0;
}