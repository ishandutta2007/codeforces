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
double p[200005];
int n;
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int k;
	cin>>n>>k;
	FOR(i,1,n){
		int x;
		cin>>x;
		p[i]=p[i-1]+x;
	}
	double ans=0;
	FOR(i,1,n-k+1){
		ans=ans+(p[i+k-1]-p[i-1])/(n-k+1);
	}
	printf("%.10f",ans);
	RE 0;
}