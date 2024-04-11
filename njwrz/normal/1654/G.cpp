#include<bits/stdc++.h>
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
int n,d[200005],need[200005],ans[200005];
V<int> v[200005],pos[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	queue<int> q;
	FILL(d,-1);
	FOR(i,1,n){
		int x;
		cin>>x;
		if(x)q.emplace(i),d[i]=0;
	}
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto u:v[x])if(d[u]==-1){
			d[u]=d[x]+1;
			q.emplace(u);
		}
	}
	FOR(i,1,n){
		for(auto u:v[i])if(d[u]==d[i]){
			pos[d[u]].PB(i);break;
		}
	}
	FOR(i,1,n)ans[i]=d[i];
	FOR(now,0,n)if(!pos[now].empty()){
		FOR(i,1,n)need[i]=1e9;
		deque<int> q;
		for(auto u:pos[now])need[u]=now,q.PB(u);
		while(!q.empty()){
			int x=q.front();q.pop_front();
			for(auto u:v[x])if(d[u]>=d[x]){
				if(d[u]>d[x]&&need[u]>need[x]&&need[x]>=d[u]-1){
					need[u]=need[x];
					q.PF(u);
				}else if(need[u]>need[x]+1){
					need[u]=need[x]+1;
					q.PB(u);
				}
			}
		}
		FOR(i,1,n){
			if(need[i]<d[i]){
				gmax(ans[i],d[i]*2-now);
			}
		}
	}
	FOR(i,1,n)cout<<ans[i]<<' ';
	RE 0;
}