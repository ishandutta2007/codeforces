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
int it[200005];
V<P<int,int> > v[200005];
int d[200005];
int cnt,s[200005],num[200005],to[200005],ct,in[200005],pp,p[200005];
bool vis[200005];
void dfs(int x,int fa){
	vis[x]=1;to[x]=p[x]=++pp;s[++cnt]=x;in[x]=1;
	for(auto u:v[x]){
		if(vis[u.F]){
			if(in[u.F])gmin(to[x],p[u.F]);
		}else{
			d[u.F]=d[x]+u.S;
			dfs(u.F,x);
			gmin(to[x],to[u.F]);
		}
	}
	if(to[x]==p[x]){
		++ct;
		do{
			it[s[cnt]]=ct;in[s[cnt]]=0;
		}while(s[cnt--]!=x);
	}
}
void dfs2(int x,int fa){
	vis[x]=1;
	for(auto u:v[x]){
		if(vis[u.F]){
			if(it[x]==it[u.F]){
				num[it[x]]=__gcd(num[it[x]],d[x]-d[u.F]+u.S);
			}
		}else{
			dfs2(u.F,x);
		}
	}
}
void solve(){
	int n,m;
	cin>>n>>m;
	FOR(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].PB(MP(y,z));
	}
	FOR(i,1,n)if(!vis[i])dfs(i,-1);
	FILL(vis,0);
	FOR(i,1,n)if(!vis[i])dfs2(i,-1);
	int q;
	cin>>q;
	FOR(i,1,q){
		int x,si,ti;
		cin>>x>>si>>ti;
		if(si%__gcd(ti,num[it[x]])==0){
			cout<<"YES\n";
		}else cout<<"NO\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t=1; 
	while(t--)solve();
	RE 0;
}