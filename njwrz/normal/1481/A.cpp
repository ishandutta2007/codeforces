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
int cnt[4];
void solve(){
	FILL(cnt,0);
	string s;
	int x,y;
	cin>>x>>y;
	cin>>s;
	for(auto u:s){
		if(u=='U'){
			cnt[0]++;
		}else if(u=='D'){
			cnt[1]++;
		}else if(u=='L'){
			cnt[2]++;
		}else if(u=='R')cnt[3]++;
	}
	if(x<0){
		if(cnt[2]<-x){
			cout<<"NO\n";RE;
		}
	}else{
		if(cnt[3]<x){
			cout<<"NO\n";RE ;
		}
	}
	if(y<0){
		if(cnt[1]<-y){
			cout<<"NO\n";RE ;
		}
	}else{
		if(cnt[0]<y){
			cout<<"NO\n";RE;
		}
	}
	cout<<"YES\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}