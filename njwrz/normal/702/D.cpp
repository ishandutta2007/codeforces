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
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int d,k,a,b,t;
	cin>>d>>k>>a>>b>>t;
	if(b<a){
		cout<<d*b;RE 0;
	}
	if(k>=d){
		cout<<a*d;RE 0;
	}
	if(a*k+t>b*k){
		int res=d-k;
		cout<<res*b+a*k;RE 0;
	}
	int tim=d/k,res=d%k;
	cout<<min(tim*(a*k+t)+res*a,tim*(a*k+t)-t+res*b);
	RE 0;
}