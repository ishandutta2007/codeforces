//satyaki3794
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
 
ll pwr(ll base, ll p, ll mod=MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}
 
 
ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}

struct edge{
    int a, b, cap, flow;
    edge(){}
    edge(int a, int b, int cap, int flow){
        this->a = a;
        this->b = b;
        this->cap = cap;
        this->flow = flow;
    }
};
 

int src, sink, ptr[1205], dist[1205];
vector<edge> edge_list;
vector<int> adj[1205];
 
 
void add_edge(int a, int b, int cap){
    adj[a].pb((int)edge_list.size());
    edge_list.pb(edge(a, b, cap, 0));
    adj[b].pb((int)edge_list.size());
    edge_list.pb(edge(b, a, 0, 0));
}
 
 
bool bfs(){
 
    memset(dist, -1, sizeof(dist));
    queue<int> qq;
    dist[src] = 0;
    qq.push(src);
    while(!qq.empty()){
 
        int v = qq.front();
        qq.pop();
 
        for(int i=0;i<(int)adj[v].size();i++){
            int e = adj[v][i];
            int vv = edge_list[e].b;
            if(dist[vv] == -1 && edge_list[e].flow < edge_list[e].cap){
                dist[vv] = dist[v]+1;
                qq.push(vv);
            }
        }
    }
    return dist[sink] != -1;
}
 
 
int dfs(int v, int flow){
    if(v == sink || flow == 0)  return flow;
    for(;ptr[v]<(int)adj[v].size();ptr[v]++){
        int id = adj[v][ptr[v]];
        int vv = edge_list[id].b;
        if(dist[vv] != dist[v]+1)   continue;
        int pushed = dfs(vv, min(flow, edge_list[id].cap - edge_list[id].flow));
        if(pushed){
            edge_list[id].flow += pushed;
            edge_list[1^id].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}
 
 
int dinitz(){
    int flow = 0;
    while(1){
        if(!bfs())  break;
        memset(ptr, 0, sizeof(ptr));
        while(int pushed = dfs(src, MOD))
            flow += pushed;
    }
    return flow;
}


int n, e, cnt[605], adj_[605][605];



int count_reachable(int mid){
	src = 0;	sink = 2*n+1;
	edge_list.clear();
	for(int i=src;i<=sink;i++){
		adj[i].clear();
	}
	for(int i=1;i<=n;i++){
		add_edge(src, i, cnt[i]);
		add_edge(n+i, sink, 1);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(adj_[i][j] <= mid)
				add_edge(i, n+j, 1);
	int ans = dinitz();
// cout<<"count_reachable "<<mid<<" returns "<<ans<<endl;
	return ans;
}


int main(){
 
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int sz, k;
    scanf("%d%d%d%d", &n, &e, &sz, &k);
    while(sz--){
    	int a;
    	scanf("%d", &a);
    	cnt[a]++;
    }

    for(int i=1;i<=n;i++)
    	for(int j=1;j<=n;j++){
    		adj_[i][j] = MOD;
    		adj_[i][i] = 0;
    	}

    while(e--){
    	int a, b, c;
    	scanf("%d%d%d", &a, &b, &c);
    	adj_[a][b] = adj_[b][a] = min(adj_[a][b], c);
    }

    for(int k=1;k<=n;k++)
    	for(int i=1;i<=n;i++)
    		for(int j=1;j<=n;j++)
    			adj_[i][j] = min(adj_[i][j], adj_[i][k] + adj_[k][j]);

    int lo = 0, hi = 1731312, ans = MOD;
    while(lo <= hi){
    	int mid = (lo + hi)/2;
    	if(count_reachable(mid) >= k){
    		ans = min(ans, mid);
    		hi = mid-1;
    	}
    	else{
    		lo = mid+1;
    	}
    }

    if(ans == MOD)	ans = -1;
    printf("%d\n", ans);
    return 0;
}