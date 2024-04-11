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
int n,siz[100005],in[100005],out[100005],cnt;
V<int> v[100005];
void dfs(int p,int fa){
	siz[p]=1;in[p]=++cnt;
	for(auto u:v[p])if(u!=fa){
		dfs(u,p);
		siz[p]+=siz[u];
	}
	out[p]=cnt;
}
void solve(){
	cin>>n;
	int x,y;
	FOR(i,1,n)v[i].clear();
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	if(n&1){
		cout<<v[1].back()<<" 1\n";
		cout<<v[1].back()<<" 1\n";RE;
	}
	dfs(1,-1);
	int t=0;
	FOR(i,1,n){
		if(siz[i]==n/2){
			t=i;break;
		}
	}
	if(!t){
		cout<<v[1].back()<<" 1\n";
		cout<<v[1].back()<<" 1\n";RE;
	}
	FOR(i,1,n){
		if(v[i].size()==1&&(in[i]>out[t]||in[i]<in[t])){
			cout<<i<<' '<<v[i].back()<<'\n';
			cout<<i<<' '<<t<<'\n';RE ;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	RE 0;
}