#pragma GCC optimize("Ofast")
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
int d[3][200005],n,s[3],c[200005];
V<int> v[200005];
bool vis[200005];
void get(int p){
	queue<int> q;
	q.emplace(s[p]);
	FOR(i,1,n)vis[i]=0,d[p][i]=0;
	int cur;
	vis[s[p]]=1;
	while(!q.empty()){
		cur=q.front();
		q.pop();
		for(auto u:v[cur])if(!vis[u]){
			vis[u]=1;
			d[p][u]=d[p][cur]+1;
			q.emplace(u);
		}
	} 
}
void solve(){
	cin>>n;
	FOR(i,1,n)v[i].clear();
	int m;
	cin>>m;
	rep(i,0,3)cin>>s[i];
	FOR(i,1,m)cin>>c[i];
	sort(c+1,c+m+1);
	FOR(i,1,m)c[i]=c[i]+c[i-1];
	int x,y;
	FOR(i,1,m){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	rep(i,0,3)get(i);
	int ans=1e17,t;
	FOR(i,1,n){
		t=d[0][i]+d[1][i]+d[2][i];
		if(t>m)continue;
		t=c[t]+c[d[1][i]];
		gmin(ans,t);
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}