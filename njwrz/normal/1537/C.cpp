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
int a[200005];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	int mini=1e9;
	rep(i,1,n){
		gmin(mini,a[i+1]-a[i]);
		if(a[i]==a[i+1]){
			V<int> v;
			FOR(j,i+2,n)v.PB(a[j]);
			rep(j,1,i)v.PB(a[j]);
			cout<<a[i]<<' ';
			for(auto u:v)cout<<u<<' ';
			cout<<a[i]<<' ';
			cout<<'\n';RE;
		}
	}
	rep(i,1,n){
		if(a[i]+mini==a[i+1]){
			V<int> v;
			FOR(j,i+2,n)v.PB(a[j]);
			rep(j,1,i)v.PB(a[j]);
			cout<<a[i]<<' ';
			for(auto u:v)cout<<u<<' ';
			cout<<a[i+1]<<' ';
			cout<<'\n';RE ;
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