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
int n,last[100005],dis[100005],sq; 
V<int> s,v[100005];
bool vis[100005];
void dfs(int p){
	for(auto u:v[p]){
		if(u==last[p])continue;
		if(last[u]){
			if(dis[u]-dis[p]+1>=sq){
				cout<<"2\n"<<dis[u]-dis[p]+1<<'\n';
				while(u!=p){
					cout<<u<<' ';
					u=last[u];
				}
				cout<<p;
				exit(0);
			}
		}else{
			dis[u]=dis[p]+1;
			last[u]=p;
			dfs(u);
		}
	}
	s.PB(p);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m,x,y;
	cin>>n>>m;
	sq=sqrt(n);
	if(sq*sq<n)sq++;
	FOR(i,1,m){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	last[1]=-1;
	dfs(1);
	cout<<"1\n";
	int cnt=0;
	for(auto u:s)if(!vis[u]&&++cnt<=sq){
		cout<<u<<' ';
		for(auto f:v[u])vis[f]=1;
	}
	RE 0;
}