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
set<P<int,int> > v[300005];
int n,X,val[300005],fa[300005],vis[300005],a[300005];
int getfa(int x){
	RE fa[x]==x?x:(fa[x]=getfa(fa[x]));
} 
void merge(int x,int y){
	x=getfa(x);
	y=getfa(y);
	fa[x]=y;
	if(x!=y){
		val[y]+=val[x]-X;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m>>X;
	int sum=0;
	FOR(i,1,n)cin>>a[i],sum+=a[i],fa[i]=i,val[i]=a[i];
	if(sum<(n-1)*X){
		cout<<"NO\n";RE 0;
	}
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		if(getfa(x)!=getfa(y)){
			v[x].emplace(MP(y,i));v[y].emplace(MP(x,i));
		}
		merge(x,y);
	}
	cout<<"YES\n";
	queue<int> q;
	FOR(i,1,n)fa[i]=i,val[i]=a[i];
	FOR(i,1,n){
		if(v[i].size()==1){
			q.emplace(i);
		}
	}
	V<int> ans;
	FOR(i,2,n){
		int cur=q.front();
		q.pop();
		P<int,int> to=*v[cur].begin();
		if(val[getfa(cur)]+val[getfa(to.F)]>=X){
			cout<<to.S<<'\n';
			merge(cur,to.F);
		}else ans.PB(to.S);
		v[to.F].erase(MP(cur,to.S));
		if(v[to.F].size()==1)q.emplace(to.F);
	}
	reverse(ALL(ans));
	for(auto u:ans)cout<<u<<'\n';
	RE 0;
}