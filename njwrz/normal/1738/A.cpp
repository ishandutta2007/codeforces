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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int a[100005];
void solve(){
	int ans=0,n;
	cin>>n;
	V<int> v1,v2;
	FOR(i,1,n){
		cin>>a[i];
	}
	int sum=0;
	FOR(i,1,n){
		int x;
		cin>>x;sum+=x;
		if(a[i])v1.PB(x);else v2.PB(x);
	}
	int t=min(v1.size(),v2.size());
	sort(ALL(v1));
	sort(ALL(v2));reverse(ALL(v1));reverse(ALL(v2));
	if(v1.size()==v2.size()){
		cout<<sum*2-min(v1.back(),v2.back())<<'\n';
	}else{
		if(v1.size()>v2.size())swap(v1,v2);
		rep(i,0,t)sum+=v1[i]+v2[i];
		cout<<sum<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}