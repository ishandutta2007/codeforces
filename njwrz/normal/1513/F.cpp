//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='

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
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
V<int> v[400005];
int n;
P<int,int> a[200005];
V<int> p; 
int maxi[400005];
void update(int x,int y){
	while(x<=2*n){
		gmax(maxi[x],y);
		x+=x&-x;
	}
}
int get(int x){
	int re=0;
	while(x){
		gmax(re,maxi[x]);
		x-=x&-x;
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int ans=0;
	FOR(i,1,n)cin>>a[i].F,p.PB(a[i].F);
	FOR(i,1,n)cin>>a[i].S,p.PB(a[i].S),ans+=abs(a[i].F-a[i].S);
	int sum=ans;
	sort(ALL(p));
	p.erase(unique(ALL(p)),p.end());
	sort(a+1,a+n+1);
	FOR(i,1,n)a[i].F=lwb(ALL(p),a[i].F)-p.begin()+1,a[i].S=lwb(ALL(p),a[i].S)-p.begin()+1;
	FOR(i,1,n)if(a[i].S>=a[i].F)v[a[i].S].PB(i);
	FOR(i,1,n){
		FOR(j,a[i-1].F+1,a[i].F){
			for(auto u:v[j]){
				update(a[u].F,a[u].S);
			}
		}
		if(a[i].S<=a[i].F&&get(a[i].S))gmin(ans,sum-2*(p[get(a[i].S)-1]-p[a[i].S-1]));
	}
	FILL(maxi,0);
	FOR(i,1,n){
		if(a[i].S>=a[i].F)update(a[i].F,a[i].S);
		if(a[i].S<=a[i].F){;
			if(get(a[i].S)>=a[i].F)gmin(ans,sum-2*(p[a[i].F-1]-p[a[i].S-1]));
		}
	}
	FOR(i,1,p.size())v[i].clear();
	FOR(i,1,n){
		swap(a[i].F,a[i].S);
	}
	FILL(maxi,0);
	sort(a+1,a+n+1);
	FOR(i,1,n)if(a[i].S>=a[i].F)v[a[i].S].PB(i);
	FOR(i,1,n){
		FOR(j,a[i-1].F+1,a[i].F){
			for(auto u:v[j]){
				update(a[u].F,a[u].S);
			}
		}
		if(a[i].S<=a[i].F&&get(a[i].S))gmin(ans,sum-2*(p[get(a[i].S)-1]-p[a[i].S-1]));
	}
	FILL(maxi,0);
	FOR(i,1,n){
		if(a[i].S>=a[i].F)update(a[i].F,a[i].S);
		if(a[i].S<=a[i].F){
			if(get(a[i].S)>=a[i].F)gmin(ans,sum-2*(p[a[i].F-1]-p[a[i].S-1]));
		}
	}
	cout<<ans;
	RE 0;
}