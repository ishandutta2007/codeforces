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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
void solve(){
	int ha,da,hb,db;
	cin>>ha>>da>>hb>>db;
	int k,a1,a2;
	cin>>k>>a2>>a1;
	FOR(i,0,k){
		int th=ha+i*a1,td=da+(k-i)*a2;
		int t1=(hb+td-1)/td,t2=(th+db-1)/db;
		if(t1<=t2){
			cout<<"YES\n";RE;
		}
	}
	cout<<"NO\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}