/*

DP





ll int
 dp 










*/
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
int n,a[1000005];
int in[1000005];
V<int> g[1000005];
void solve(){
	cin>>n;
	FOR(i,1,n)g[i].clear(),in[i]=0;
	FOR(i,1,n){
		cin>>a[i];
		g[i].PB(i-a[i]);
		in[i-a[i]]++;
	}
	queue<int> q;
	FOR(i,1,n){
		if(!in[i])q.emplace(i);
	}
	while(!q.empty()){
		int cur=q.front();q.pop();
		for(auto u:g[cur]){
			if(--in[u]==0){
				q.emplace(u);
			}
		}
	}
	FOR(i,1,n)if(in[i]){
		V<int> ans;
		int t=i;
		do{
			ans.PB(t);
			t=t-a[t];
		}while(t!=i);
		cout<<ans.size()<<'\n';
		for(auto u:ans){
			cout<<u<<' ';
		}
		cout<<'\n';
		RE ;
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