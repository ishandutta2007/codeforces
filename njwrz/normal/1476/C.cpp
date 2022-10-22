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
int a[100005],b[100005],c[100005];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n){
		cin>>c[i];
	}
	FOR(i,1,n){
		cin>>a[i];
	}
	FOR(i,1,n){
		cin>>b[i];
	}
	int now=c[n]-1,ans=0;
	for(int i=n-1;i>=1;i--){
		now+=2;
		if(a[i+1]==b[i+1]){
			gmax(ans,now);
			now=c[i]-1;
		}else{
			gmax(ans,now+abs(a[i+1]-b[i+1]));
			now=now+c[i]-1-abs(a[i+1]-b[i+1]);
			gmax(now,c[i]-1);
		}
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