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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int maxi=1e16;
void solve(){
	int a[35],n,k;
	cin>>n>>k;
	FOR(i,1,n)cin>>a[i];
	int t=1;
	while(t<maxi)t*=k;
	while(t){
		FOR(i,1,n){
			if(a[i]>=t){
				a[i]-=t;break;
			}
		}
		t/=k;
	}
	FOR(i,1,n){
		if(a[i]){
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