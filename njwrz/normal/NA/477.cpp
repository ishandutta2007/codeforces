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
void solve(){
	int n;
	int x;
	cin>>n;
	int sum1,sum0;
	sum1=sum0=0;
	V<int> v1,v0;
	int cnt=0;
	FOR(i,1,n){
		cin>>x;
		if(x<0){
			v1.PB(-x);
			sum1+=-x;
		}else if(x>0){
			v0.PB(x);
			sum0+=x;
		}else cnt++;
	}
	if(sum0<sum1){
		cout<<"YES\n";
		for(auto u:v1)cout<<-u<<' ';
		FOR(i,1,cnt)cout<<0<<' ';
		for(auto u:v0)cout<<u<<' ';
	}else if(sum0>sum1){
		cout<<"YES\n";
		for(auto u:v0)cout<<u<<' ';
		FOR(i,1,cnt)cout<<0<<' ';
		for(auto u:v1)cout<<-u<<' ';
	}else cout<<"NO";
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve(); 
	RE 0;
}