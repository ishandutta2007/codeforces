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
P<int,int> p[300005];
int n;
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>p[i].F>>p[i].S;
	rep(i,1,n)gmin(p[i].S,p[i+1].F);
	gmin(p[n].S,p[1].F);
	int mini=1e17,sum=0;
	FOR(i,1,n)gmin(mini,p[i].S),sum=sum+p[i].F-p[i].S;
	sum=sum+mini;
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