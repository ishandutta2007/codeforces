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
int a[105]; 
void solve(){
	int n,d;
	cin>>n>>d;
	FOR(i,1,n)cin>>a[i];
	bool f=1;
	FOR(i,1,n){
		if(a[i]>d){
			f=0;break;
		}
	}
	if(f){
		cout<<"YES\n";RE ;
	}
	sort(a+1,a+n+1);
	if(a[1]+a[2]<=d){
		cout<<"YES\n";
	}else cout<<"NO\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}