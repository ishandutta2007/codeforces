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
int p[35],s[35];
void solve(){
	int x,y;
	cin>>x>>y;FILL(p,0);FILL(s,0);
	int max1,max2;
	max1=max2=0;
	rep(i,0,30){
		if(x&(1<<i))p[i]=1;
	}
	rep(i,0,30){
		if(y&(1<<i))s[i]=1;
	}
	for(int i=29;i>=0;i--){
		if(p[i]&&!s[i]){
			cout<<"NO\n";RE ;
		}
		if(!p[i]&&s[i])break;
	}
	int cnt=0;
	rep(i,0,30){
		cnt+=p[i];
		cnt-=s[i];
		if(cnt<0){
			cout<<"NO\n";RE ;
		}
	}
	cout<<"YES\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n){
		solve();
	}
	RE 0;
}