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
int n;
V<P<int,int> > g,l;
V<int> v[100005]; 
int dfs(int x,int y){
	int re=x,cnt=0;
	for(auto u:v[x])if(u!=y){
		int t=dfs(u,x);
		if(t==-1)continue;
		cnt++;
		if(cnt==1)re=t;
		else if(cnt==2){
			if(y!=-1)l.PB(MP(x,y));
			g.PB(MP(re,t));
			re=-1;
		}else l.PB(MP(x,u)),g.PB(MP(t,u));
	}
	RE re;
}
void solve(){
	cin>>n;
	g.clear();l.clear();
	FOR(i,1,n)v[i].clear();
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	int t=dfs(1,-1);
	if(t!=-1){
		g.PB(MP(1,t));
	}
	V<int> p;
	for(auto u:g)p.PB(u.F),p.PB(u.S);
	cout<<l.size()<<'\n';
	int cnt=1;
	for(auto u:l){
		cout<<u.F<<' '<<u.S<<' '<<p[cnt]<<' '<<p[cnt+1]<<'\n';cnt+=2;
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