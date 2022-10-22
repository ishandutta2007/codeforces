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
#define rc ((x<<1)|1)
using namespace std;
int L[200005],R[200005];
void solve(){
	int n,l,r;
	cin>>n>>l>>r;
	FOR(i,1,n)L[i]=R[i]=0;
	FOR(i,1,l){
		int x;
		cin>>x;
		L[x]++;
	}
	FOR(i,1,r){
		int x;
		cin>>x;
		R[x]++;
	}
	FOR(i,1,n){
		int T=min(L[i],R[i]);
		L[i]-=T;R[i]-=T;
		l-=T,r-=T;
	}
	if(l<r){
		FOR(i,1,n)swap(L[i],R[i]);
		swap(l,r);
	}
	int ans=0,d=l-r;;
	FOR(i,1,n){
		if(L[i]>R[i]){
			int t=(L[i]-R[i])/2;
			if(d>=2*t){
				d-=2*t;
				L[i]-=t*2;ans+=t;
			}else L[i]-=d,ans+=d/2,d=0;
		}
	}
	if(d){
		ans+=d/2;
		int sum=0;
		FOR(i,1,n)sum+=L[i]+R[i];
		cout<<ans+sum/2<<'\n';
		RE;
	}
	FOR(i,1,n){
		ans+=max(0,L[i]-R[i]);
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}