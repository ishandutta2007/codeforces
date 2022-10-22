/*

DP





ll int
 dp 










*/
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
int in[200005],w[200005];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n)cin>>w[i],in[i]=0;
	int x,y;
	rep(i,1,n){
		cin>>x>>y;
		in[x]++;
		in[y]++;
	}
	V<int> v;
	FOR(i,1,n)if(in[i]>1){
		rep(j,1,in[i])v.PB(w[i]);
	}
	sort(ALL(v));
	int ans=0;
	FOR(i,1,n)ans+=w[i];
	rep(i,1,n){
		cout<<ans<<' ';
		if(!v.empty()){
			ans+=v.back();v.pop_back();
		}
	}
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}