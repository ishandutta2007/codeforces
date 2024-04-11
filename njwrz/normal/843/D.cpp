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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int to[100005],len[100005];ll dis[100005],lstdis[100005];
V<int> v[100005];
int n,m,Q; 
const ll inf=1e18;
V<int> hav[100005];
int vis[100005];
int q[100005],s,t;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>Q;
	FOR(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].PB(i);
		to[i]=y;len[i]=z;
	}
	FOR(i,1,n)dis[i]=inf;
	priority_queue<P<ll,int>,V<P<ll,int> > ,greater<P<ll,int> > > q2;
	q2.emplace(MP(0,1));dis[1]=0;
	while(!q2.empty()){
		P<ll,int> now=q2.top();q2.pop();
		if(now.F!=dis[now.S])continue;
		for(auto u:v[now.S])if(len[u]+now.F<dis[to[u]]){
			dis[to[u]]=len[u]+now.F;
			q2.emplace(MP(dis[to[u]],to[u]));
		}
	}
	FOR(_,1,Q){
		int tap;
		cin>>tap;
		if(tap==1){
			int x;
			cin>>x;
			if(dis[x]==inf){
				cout<<-1<<'\n';continue;
			}
			cout<<dis[x]<<'\n';
		}else{
			int x;
			cin>>x;
			FOR(j,1,x){
				int t;
				cin>>t;
				len[t]++;
			}
			FOR(i,0,n)hav[i].clear(),vis[i]=0;
			hav[0].PB(1);
			FOR(i,1,n)lstdis[i]=dis[i],dis[i]=inf;
			dis[1]=0;
			FOR(nowd,0,n){
				s=1;t=0;
				for(auto u:hav[nowd])if(!vis[u]){
					q[++t]=u;vis[u]=1;dis[u]=lstdis[u]+nowd;
				}
				while(s<=t){
					int now=q[s++];
					for(auto u:v[now]){
						if(!vis[to[u]]&&dis[to[u]]>dis[now]+len[u]&&dis[now]+len[u]-lstdis[to[u]]<=n){
							dis[to[u]]=dis[now]+len[u];
							int del=dis[to[u]]-lstdis[to[u]];
							if(del>nowd)hav[del].PB(to[u]);else q[++t]=to[u],vis[to[u]]=1;
						}
					}
				}
			}
		}
	}
	RE 0;
}