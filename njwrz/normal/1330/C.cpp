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
int l[100005],ans[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;int sum=0;
	FOR(i,1,m)cin>>l[i],sum+=l[i];
	if(sum<n){
		cout<<-1;RE 0;
	}
	sum-=n;
	int r=n+1,t;
	for(int i=m;i>=1;i--){
		r=min(n-l[i]+1,r-1);
		if(r<=0){
			cout<<-1;RE 0;
		} 
		ans[i]=r;
	}
	ans[1]=1;
	rep(i,1,m){
		ans[i+1]=min(ans[i+1],ans[i]+l[i]);
	}
	FOR(i,1,m)cout<<ans[i]<<' ';
	RE 0;
}