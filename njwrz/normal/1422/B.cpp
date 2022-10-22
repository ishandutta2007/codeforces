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
int a[105][105];
int check(int x,int y,int z,int t){
	int a[4]={x,y,z,t};
	sort(a,a+4);
	RE a[1]-a[0]+a[2]-a[1]+a[3]-a[1];
}
int check(int x,int y){
	RE abs(x-y);
}
void solve(){
	int n,m;
	cin>>n>>m;
	FOR(i,1,n){
		FOR(j,1,m)cin>>a[i][j];
	}
	int ans=0;
	FOR(i,1,n/2){
		FOR(j,1,m/2){
			ans+=check(a[i][j],a[i][m-j+1],a[n-i+1][j],a[n-i+1][m-j+1]);
		}
	}
	if(n&1){
		int i=n/2+1;
		FOR(j,1,m/2){
			ans+=check(a[i][j],a[i][m-j+1]);
		}
	} 
	if(m&1){
		int j=m/2+1;
		FOR(i,1,n/2){
			ans+=check(a[i][j],a[n-i+1][j]);
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	RE 0;
}