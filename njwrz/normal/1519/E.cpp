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
P<int,int> p[400005]; 
P<int,int> solve(int x,int y){
	int t=__gcd(x,y);
	x/=t;y/=t;
	RE MP(x,y);
}
map<P<int,int>,int> m;
V<int> v[400005];
V<P<int,int> > ans;
int vis[400005];
bool f[400005];
V<int> era[400005],it[400005];
void erase(int x,int fa){
	V<int> re;
	for(auto u:era[x])f[u]=1;
	for(auto u:it[x])if(!f[u]&&(p[u].F==fa||p[u].S==fa)){
		re.PB(u);
	}
	for(auto u:it[x])if(!f[u]&&p[u].F!=fa&&p[u].S!=fa){
		re.PB(u);
	}
	for(auto u:era[x])f[u]=0;
	it[x]=re;
}
void dfs(int x,int fa){
	vis[x]=1;
	for(auto u:v[x])if(!vis[u])dfs(u,x);
	erase(x,fa);
	while(it[x].size()>1){
		int t=it[x].back();it[x].pop_back();
		era[p[t].F^p[t].S^x].PB(t);
		ans.PB(MP(t,it[x].back()));
		t=it[x].back();
		era[p[t].F^p[t].S^x].PB(t);
		it[x].pop_back();
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int cnt=0;
	FOR(i,1,n){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		P<int,int> t=solve((a+b)*d,b*c);
		if(!m[t])m[t]=++cnt;
		p[i].F=m[t];
		t=solve(a*d,(c+d)*b);
		if(!m[t])m[t]=++cnt;
		p[i].S=m[t];
		v[p[i].F].PB(p[i].S);
		v[p[i].S].PB(p[i].F);
		it[p[i].F].PB(i);
		it[p[i].S].PB(i);
	}
	FOR(i,1,cnt){
		sort(ALL(v[i]));
		v[i].erase(unique(ALL(v[i])),v[i].end());
	}
	FOR(i,1,cnt)if(!vis[i]){
		dfs(i,-1);
	}
	cout<<ans.size()<<'\n';
	for(auto u:ans)cout<<u.F<<' '<<u.S<<'\n';
	RE 0;
}