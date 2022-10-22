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
int l[200005],r[200005],h[200005];
void solve(){
	int n;
	cin>>n;
	FOR(i,0,n)l[i]=r[i]=h[i]=0;
	int k;
	cin>>k;
	FOR(i,1,n)cin>>h[i];
	l[1]=r[1]=h[1]+1;
	FOR(i,2,n){
		if(r[i]<l[i]){
			cout<<"NO\n";RE ;
		}
		if(l[i-1]-k+1-h[i]-1>k-1){
			cout<<"NO\n";RE;
		}
		if(r[i-1]+k-1<h[i]+1){
			cout<<"NO\n";RE;
		}
		l[i]=max(h[i]+1,l[i-1]-k+1);
		r[i]=min(r[i-1]+k-1,h[i]+k);
//		cout<<l[i]<<' '<<r[i]<<'\n';
	}
	if(l[n]!=h[n]+1){
		cout<<"NO\n";
	}else cout<<"YES\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}