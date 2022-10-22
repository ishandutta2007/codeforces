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
	V<int> vx,vy;
	int x,y,l,r;
	cin>>x>>y>>l>>r;
	int t=1;
	while(t<=r){
		vx.PB(t);
		if(r/t>=x)t=t*x;else t=r+1;
	}
	t=1;
	while(t<=r){
		vy.PB(t);
		if(r/t>=y)t=t*y;else t=r+1;
	}
	V<int> v;
	for(auto u1:vx){
		for(auto u2:vy){
			int now=u1+u2;
			if(l<=now&&now<=r){
				v.PB(now);
			}
		}
	}
	sort(ALL(v));
	int lst=l-1,ans=0;
	for(auto u:v){
		gmax(ans,u-lst-1);
		lst=u;
	}
	gmax(ans,r-lst);
	cout<<ans;
	RE 0;
}