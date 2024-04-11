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
//
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
int n,m;
P<int,P<int,int> > g[200005];
set<int> v[200005]; 
int fa[200005];
int getfa(int x){
	if(fa[x]==x)RE x;
	else RE fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
	x=getfa(x);
	y=getfa(y);
	fa[x]=y;
}
int fa2[200005];
int getfa2(int x){
	if(fa2[x]==x)RE x;
	else RE fa2[x]=getfa2(fa2[x]);
}
void merge2(int x,int y){
	x=getfa2(x);
	y=getfa2(y);
	fa2[x]=y;
}
set<int> s;
int t;
bool vis[200005];
void dfs(int x){
	vis[x]=1;s.erase(x);
	for(set<int>::iterator iter=s.begin();iter!=s.end();){
		int now=*iter;
		if(!v[x].count(now)){
			t--;
			merge(x,now);
			dfs(now);
		}
		iter=s.upb(now);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)fa[i]=i,s.insert(i),fa2[i]=i;
	t=n*(n-1)/2-m;
	FOR(i,1,m){
		cin>>g[i].S.F>>g[i].S.S>>g[i].F;
		v[g[i].S.F].emplace(g[i].S.S);
		v[g[i].S.S].emplace(g[i].S.F);
	}
	sort(g+1,g+m+1);
	FOR(i,1,n){
		if(!vis[i])dfs(i);
	}
	int add;
	if(t!=0)add=0;else{
		add=0;
		FOR(i,1,m)add^=g[i].F;
	}
	int ans=0;
//	cout<<add<<'\n';
	FOR(i,1,m){
//		cout<<getfa(g[i].S.F)<<' '<<getfa(g[i].S.S)<<'\n';
		if(getfa(g[i].S.F)!=getfa(g[i].S.S)){
			merge(g[i].S.F,g[i].S.S);
			merge2(g[i].S.F,g[i].S.S);
			ans+=g[i].F;
		}else{
			if(getfa2(g[i].S.F)!=getfa2(g[i].S.S)){
				merge2(g[i].S.F,g[i].S.S);
				gmin(add,g[i].F);
			}
		}
	}
	cout<<ans+add;
	RE 0;
}