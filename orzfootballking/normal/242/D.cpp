#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
queue<int> q;
int n,a[100005],vis[100005],x,y;
V<int> v[100005],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	rep(i,0,m){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	FOR(i,1,n){
		cin>>a[i];
		if(!a[i])q.push(i);
	}
	int cur;
	while(!q.empty()){
		cur=q.front();q.pop();
		if(vis[cur]!=a[cur])continue;
		ans.PB(cur);
		vis[cur]++;
		for(auto u:v[cur]){
			vis[u]++;
			if(vis[u]==a[u])q.push(u);
		} 
	}
	sort(ALL(ans));
	cout<<ans.size()<<'\n';
	for(auto u:ans)cout<<u<<' ';
	RE 0;
}