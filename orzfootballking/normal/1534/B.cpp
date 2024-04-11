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
int h[400005];
void solve(){
	int x;
	cin>>x;
	FOR(i,1,x)cin>>h[i];
	int ans=0;
	h[x+1]=0;
	FOR(i,0,x){
		ans+=abs(h[i+1]-h[i]);
	}
	FOR(i,1,x){
		ans-=max(0ll,min(h[i]-h[i-1],h[i]-h[i+1]));
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