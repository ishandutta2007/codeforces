/*

DP





ll int
 dp 










*/
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
using namespace std;
set<int> v[3005];
V<int> ans;
int n,m; 
bool f[3005];
void dfs(int x){
	if(f[x])RE;
	f[x]=1;
	for(auto u:v[x])dfs(u);
} 
void get(int x){
	while(!v[x].empty()){
		int t=*v[x].begin();
		v[x].erase(v[x].begin());
		v[t].erase(x);
		get(t);
	}
	ans.PB(x);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		v[x].emplace(y);
		v[y].emplace(x);
	}
	set<int> odd;
	FOR(i,1,n)if(v[i].size()&1)odd.emplace(i);
	if(odd.size()<=2){
		int t=1;
		FOR(i,1,n)if(v[i].size()&1)t=i;
		get(t);
		cout<<ans.size()<<'\n';
		for(auto u:ans)cout<<u<<' ';
		RE 0;
	}
	FOR(i,1,n){
		set<int> era;
		FILL(f,0);
		for(auto u:v[i]){
			if(v[u].size()&1){
				era.emplace(u);
			}
		}
		for(auto u:era){
			v[i].erase(u);
			v[u].erase(i);
			if(v[i].size()&1){
				odd.insert(i);
			}else odd.erase(i);
			odd.erase(u);
		}
		dfs(i);
//		cout<<odd.size()<<' '<<v[i].size()<<'\n';
		if(odd.size()>2||odd.size()==2&&!(v[i].size()&1)){
			for(auto u:era){
			v[i].insert(u);
			v[u].insert(i);
			if(v[i].size()&1){
				odd.insert(i);
			}else odd.erase(i);
			odd.insert(u);
			}
			continue;
		}
		bool ff=1;
		FOR(j,1,n){
			if(v[j].empty())f[j]=1; 
			if(!f[j])ff=0;
		}
		if(!odd.size()&&!ff){
			for(auto u:era){
				if(!f[u]){
//					cout<<u<<'\n';
//					FOR(j,1,n)cout<<f[j]<<' ';
//					cout<<"   ";
					dfs(u);
					ff=1;
					FOR(j,1,n){
//						cout<<f[j]<<' ';
						if(!f[j])ff=0;
					}
//					cout<<'\n';
					v[u].emplace(i);
					v[i].emplace(u);
					odd.emplace(u);
					odd.emplace(i);
					era.erase(u);
					break;
				}
			}
		}
		if(!ff){
			for(auto u:era){
			v[i].insert(u);
			v[u].insert(i);
			if(v[i].size()&1){
				odd.insert(i);
			}else odd.erase(i);
			odd.insert(u);
			}
			continue; 
		}
		get(i);
		cout<<ans.size()+era.size()*2+1<<'\n';
		for(auto u:ans)cout<<u<<' ';
		cout<<-1<<' ';
		for(auto u:era)cout<<u<<' '<<i<<' ';
		RE 0;
	}
	cout<<0;
	RE 0;
}