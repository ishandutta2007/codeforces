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
int a[505],maxi=1e9;
int check(int x,int y){
	int t=x/(y+1),res=x%(y+1);
	if(!res){
		RE t;
	}else {
//		if(x==461613425&&y==936334)cout<<t<<' '<<res<<'\n';
		if(y-res<=t){
			RE t+1;
		}else RE -1;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1e18;
	for(int i=1;i*i<=maxi;i++){
		int sum=0;
		bool ff=1;
		FOR(j,1,n){
			int t=check(a[j],i);
			if(t==-1){
				ff=0;break;
			}else sum+=t;
		}
		if(ff)gmin(ans,sum);
		int ni=a[1]/i;
		if(ni==0)continue;
		if(check(a[1],ni)!=-1){
			sum=i;
			ff=1;
			FOR(j,2,n){
				int t=check(a[j],ni);
				if(t==-1){
					ff=0;break;
				} else sum+=t;
			}
			if(ff)gmin(ans,sum);
		}
		ni--;
		if(ni==0)continue;
		if(check(a[1],ni)!=-1){
			sum=check(a[1],ni);
			ff=1;
			FOR(j,2,n){
				int t=check(a[j],ni);
				if(t==-1){
					ff=0;break;
				} else sum+=t;
			}
			if(ff)gmin(ans,sum);
		}
	}
	cout<<ans;
	RE 0;
}