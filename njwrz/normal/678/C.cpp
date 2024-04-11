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
int n,a,b,q,p;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>a>>b>>p>>q;
	int ta,tb,tc;
	int c=a/__gcd(a,b)*b;
	tc=n/c;
	ta=n/a-tc;
	tb=n/b-tc;
	cout<<ta*p+tb*q+tc*max(p,q);
	RE 0;
}