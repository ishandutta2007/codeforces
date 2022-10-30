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
int n,k,q,a[100005],p[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q>>k;
	FOR(i,1,n)cin>>a[i];
	FOR(i,3,n){
		p[i]=p[i-1]+a[i]-a[i-2]-2;
	}
	FOR(i,1,q){
		int l,r;
		cin>>l>>r;
		if(l==r){
			cout<<k-1;
		}else {
			int now=p[r]-p[l+1];
			now+=k-a[r-1]-1;
			now+=a[l+1]-2;
			cout<<now;
		}
		cout<<'\n';
	}
	RE 0;
}