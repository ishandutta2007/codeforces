#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#define MN 100000
#define MV 300000

using std::min;
using std::map;
using std::vector;

using ll = long long;

const ll INF = 1e18;

struct Edge{
	int v,w;
};

int n,m,k;
int x[MN+5];

int pid_used;
map<int,int> pid[MN+5];
vector<Edge> e[MV+5];
ll f[MV+5];

int getId(int x,int y){
	if(pid[x].count(y)) return pid[x][y];
	else return pid[x][y] = ++pid_used;
}

void solve(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	for(int i=1;i<=k;i++){
		int a,b,c,d,h;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&h);
		e[getId(a,b)].push_back({getId(c,d),h});
	}
	getId(1,1),getId(n,m);
	for(int i=1;i<=pid_used;i++)
		f[i] = INF;
	f[getId(1,1)] = 0;
	for(int i=1;i<=n;i++){
		//l to r
		{
			ll ov = INF;
			for(auto it = pid[i].begin();it!=pid[i].end();it++){
				int p = (*it).first;
				int u = (*it).second;
				ll dv = (ll)p*x[i];
				if(f[u]<ov+dv){
					ov = f[u]-dv;
				}
				f[u] = min(f[u],ov+dv);
			}
		}
		//r to l
		{
			ll ov = INF;
			for(auto it = pid[i].rbegin();it!=pid[i].rend();it++){
				int p = (*it).first;
				int u = (*it).second;
				ll dv = (ll)(m-p)*x[i];
				if(f[u]<ov+dv){
					ov = f[u]-dv;
				}
				f[u] = min(f[u],ov+dv);
			}
		}
		for(auto p:pid[i]){
			int u = p.second;
			if(f[u]==INF) continue;
			for(Edge edge:e[u]){
				f[edge.v] = min(f[edge.v],f[u]-edge.w);
			}
		}
	}
	if(f[getId(n,m)]==INF){
		puts("NO ESCAPE");
	}else{
		printf("%lld\n",f[getId(n,m)]);
	}
	//clear
	for(int i=1;i<=pid_used;i++)
		e[i].clear();
	for(int i=1;i<=n;i++)
		pid[i].clear();
	pid_used = 0;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}