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
int dp[100005][1<<7];
int n,k,p,qz; 
struct node{
	int x;
	V<int> v;
}a[100005];
bool cmp(node s1,node s2){
	RE s1.x>s2.x;
}
int count(int x){
	int re=0;
	while(x){
		x=x&(x-1);re++;
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>p>>k;
	FOR(i,1,n)cin>>a[i].x;
	FOR(i,1,n){
		a[i].v.resize(p);
		rep(j,0,p)cin>>a[i].v[j];
	}
	sort(a+1,a+n+1,cmp);
	int c;
	rep(i,0,n){
		rep(j,0,(1<<p)){
			c=i-count(j);
			if(c<0)continue;
			gmax(dp[i+1][j],dp[i][j]);
			if(c<k)gmax(dp[i+1][j],dp[i][j]+a[i+1].x);
			rep(mask,0,p){
				if(j&(1<<mask))continue;
				gmax(dp[i+1][j|(1<<mask)],dp[i][j]+a[i+1].v[mask]);
			}
		}
	}
	cout<<dp[n][(1<<p)-1];
	RE 0;
}