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
int a[100005];
void solve(){
	int n;
	cin>>n;
	V<int> v1,v2;
	bool f=1;
	FOR(i,1,n){
		cin>>a[i];
		if(!a[i])f=0;
		if(a[i]<0)v1.PB(-a[i]);else v2.PB(a[i]);
	}
	int ans;
	if(!f)ans=0;else ans=-1e18;
	sort(ALL(v1),greater<int>());
	sort(ALL(v2),greater<int>());
	for(int i=0;i<=4;i+=2){
		int t=1;
		if(v1.size()>=i&&v2.size()>=5-i){
			rep(j,0,i)t*=v1[j];
			rep(j,0,5-i)t*=v2[j];
			gmax(ans,t);
		}
	}
	sort(ALL(v1));
	sort(ALL(v2));
	for(int i=1;i<=5;i+=2){
		int t=1;
		if(v1.size()>=i&&v2.size()>=5-i){
			rep(j,0,i)t*=v1[j];
			rep(j,0,5-i)t*=v2[j];
			gmax(ans,-t);
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