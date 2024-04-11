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
int n,m,cnt[55],used[55],add[55]; 
bool vis[55];
V<int> v[55],p;
P<int,int> it[55];
int fa[55];
int getfa(int x){
	if(x==fa[x])RE x;
	else RE fa[x]=getfa(fa[x]);
}
void update(int x,int y){
	x=getfa(x);
	y=getfa(y);
	fa[x]=y;
} 
void dfs(int x){
	if(vis[x])RE;
	vis[x]=1;
	p.PB(x);
	for(auto u:v[x]){
		dfs(u);
	} 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int x,y;
	FOR(i,1,m){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	int cnt=0;
	FOR(i,1,n)if(!vis[i]){
		p.clear();
		dfs(i);
		int lst=cnt;
		for(auto u:p){
			if(v[u].size()>2){
				cout<<"NO";RE 0;
			}
			if(v[u].size()==1){
				if(cnt&&it[cnt].S==0){
					it[cnt].S=u;
				}else{
					it[++cnt].F=u;
				}
			}
			if(v[u].empty()){
				it[++cnt]=MP(u,u);
			}
		}
		if(lst==cnt){
			if(p.size()==n){
				cout<<"YES\n0";RE 0;
			}else{
				cout<<"NO";RE 0;
			}
		}
	}
	FOR(i,1,n)fa[i]=i;
	FOR(i,1,cnt){
		if(it[i].F>it[i].S)swap(it[i].F,it[i].S);
		used[it[i].F]++;used[it[i].S]++;
		add[it[i].F]=add[it[i].S]=i;
	}
	sort(it+1,it+cnt+1);
	cout<<"YES\n";
	cout<<cnt<<'\n';
	FOR(i,1,n){
		while(used[i]){
			bool f=1;
			FOR(j,i+1,n)if(used[j]){
				if(getfa(add[i])!=getfa(add[j])){
					cout<<i<<' '<<j<<'\n';
					update(add[i],add[j]);
					used[i]--;used[j]--;
					f=0;
					break;
				}
			}
			if(f)break;
		}
	}
	FOR(i,1,n){
		while(used[i]){
			cout<<i<<' ';
			used[i]--;
		}
	}
	RE 0;
}