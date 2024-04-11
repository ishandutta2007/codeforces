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
V<int> v[100005],ans;
int pri[100005],siz[100005],mod=1e9+7;
int n;
void dfs(int x,int fa){
	siz[x]=1;
	for(auto u:v[x])if(u!=fa){
		dfs(u,x);
		siz[x]+=siz[u];
	}
	ans.PB(min(siz[x],n-siz[x]));
}
void solve(){
	cin>>n;
	FOR(i,1,n)v[i].clear();
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	int sum=0;ans.clear();
	dfs(1,-1);ans.pop_back();n--;
	int m;cin>>m;
	FOR(i,1,m)cin>>pri[i];
	sort(pri+1,pri+m+1,greater<int>());
	while(m<n){
		pri[++m]=1;
	}
	sort(ALL(ans),greater<int>());
	int it=1,cnt=1;
	for(auto u:ans){
		int t=1;
		while(it-cnt<=m-n){
			t=t*pri[it++]%mod;
		}
		sum=(sum+u*(n-u+1)%mod*t%mod)%mod;
		cnt++;
	}
	cout<<sum<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}