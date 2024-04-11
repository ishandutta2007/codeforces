#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
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
int n;
int ans[105];
signed main(){
	cin>>n;
	V<P<int,int> > v;
	FOR(i,1,n){
		cout<<"? ";
		rep(j,1,n)cout<<1<<' ';
		cout<<n-i+1<<'\n';
		cout.flush() ;
		int t;
		cin>>t;
		if(t){
			if(!ans[n]){
				ans[n]=i;
			}
			v.PB(MP(n-i,t));
		}
	}
	if(!ans[n])ans[n]=n;
	for(auto u:v){
		ans[u.S]=ans[n]+u.F;
	}
	FOR(i,1,n){
		cout<<"? ";
		rep(j,1,n)cout<<n-i+1<<' ';
		cout<<1<<'\n';
		cout.flush() ;
		int t;
		cin>>t;
		if(t){
			ans[t]=ans[n]-(n-i);
		}
	}
	cout<<"! ";
	FOR(i,1,n)cout<<ans[i]<<' ';
	RE 0;
}