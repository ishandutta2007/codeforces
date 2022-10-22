#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define lb long double
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
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
using namespace __gnu_pbds;
int n,m;
V<P<int,int> > v[200005];
priority_queue<P<int,int>,V<P<int,int> >,greater<P<int,int> > > q;
int dis[200005],lst[200005],siz[200005] ;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int s;
	cin>>n>>m>>s;
	FOR(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].PB(MP(y,z));
		v[y].PB(MP(x,z));
	}
	FOR(i,1,n)if(i!=s)dis[i]=1e18;
	for(auto u:v[s]){
		if(dis[u.F]>u.S){
			dis[u.F]=u.S;
			q.emplace(MP(u.S,u.F));
			lst[u.F]=u.F;
		}
	}
	while(!q.empty()){
		P<int,int> now=q.top();
		q.pop();
		if(now.F!=dis[now.S])continue;
		for(auto u:v[now.S])if(u.F!=s){
			if(dis[u.F]>u.S+now.F){
				dis[u.F]=u.S+now.F;
				lst[u.F]=lst[now.S];
				q.emplace(MP(dis[u.F],u.F));
			}else if(dis[u.F]==u.S+now.F){
				if(lst[now.S]!=lst[u.F])lst[u.F]=u.F;
			}
		}
	}
	int ans=0;
	FOR(i,1,n)if(i!=s){
		siz[lst[i]]++;
	}
	FOR(i,1,n)gmax(ans,siz[i]);
	cout<<ans;
	RE 0;
}