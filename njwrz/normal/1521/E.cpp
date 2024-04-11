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
int a[100005],m,k,b[700][700];
bool check(int x){
	V<P<int,int> > v;
	FOR(i,1,k)if(a[i])v.PB(MP(a[i],i));
	sort(ALL(v));
	reverse(ALL(v));v.PB(MP(1e9,0));
	reverse(ALL(v));
	int lst;
	for(int i=1;i<=x;i+=2){
		FOR(j,1,x){
			b[i][j]=v.back().S;lst=b[i][j];
			v.back().F--;
			if(v.back().F==0)v.pop_back();
		}
	}
	V<P<int,int> > g; 
	for(int i=1;i<=x;i+=2){
		FOR(j,1,x){
			if(b[i][j]==lst&&!(j&1)){
				g.PB(MP(i,j));
			}
		}
	}
	for(int i=1;i<=x;i+=2){
		for(int j=1;j<=x;j+=2){
			if(!g.empty()){
				swap(b[g.back().F][g.back().S],b[i][j]);
				g.pop_back();
			}
		}
	}
	for(int i=2;i<=x;i+=2){
		for(int j=1;j<=x;j+=2){
			b[i][j]=v.back().S;
			v.back().F--;
			if(v.back().F==0)v.pop_back();
		}
	}
	if(v.size()!=1)RE 0;
	rep(i,1,x){
		rep(j,1,x){
			if(b[i][j]==b[i+1][j+1]&&b[i][j]){
				RE 0;
			}
		}
	}
	FOR(i,2,x){
		rep(j,1,x){
			if(b[i][j]==b[i-1][j+1]&&b[i][j]){
				RE 0;
			}
		}
	} 
	RE 1;
}
void solve(){
	cin>>m>>k;
	FOR(i,1,k){
		cin>>a[i];
	}
	int l=sqrt(m),r=sqrt(m)*2+1,ans=r;
	while(r>=l){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}else l=mid+1;
	}
	check(ans);
	cout<<ans<<'\n';
	FOR(i,1,ans){
		FOR(j,1,ans)cout<<b[i][j]<<' ';
		cout<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}