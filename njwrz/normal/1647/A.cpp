#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
#define int long long
#define lb long double
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
	int n;
	cin>>n;
	if(n%3==2){
		FOR(i,1,n/3)cout<<2<<1;
		cout<<2;
	}else if(n%3==0){
		FOR(i,1,n/3)cout<<2<<1;
	}else{
		FOR(i,1,n/3)cout<<1<<2;
		cout<<1;
	}
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve(); 
	RE 0;
}