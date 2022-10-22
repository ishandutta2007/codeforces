#pragma GCC optimize("Ofast","inline","unroll-loops")
#include<bits/stdc++.h>
#define ll long long
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
template <class Cap, class Cost> struct mcf_graph {
  public:
    mcf_graph() {}
    mcf_graph(int n) : _n(n), g(n) {}

    int ad(int from, int to, Cap cap, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        int m = (pos.size());
        pos.push_back({from, (g[from].size())});
        int from_id = (g[from].size());
        int to_id = (g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap, cost});
        g[to].push_back(_edge{from, from_id, 0, -cost});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
    };

    edge get_edge(int i) {
        int m = (pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{
            pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,
        };
    }
    std::vector<edge> edges() {
        int m = (pos.size());
        std::vector<edge> result(m);
        for (int i = 0; i < m; i++) {
            result[i] = get_edge(i);
        }
        return result;
    }

    std::pair<Cap, Cost> flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
        return slope(s, t, flow_limit).back();
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
        return slope(s, t, std::numeric_limits<Cap>::max());
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);
        std::vector<Cost> dual(_n, 0), dist(_n);
        std::vector<int> pv(_n), pe(_n);
        std::vector<bool> vis(_n);
        auto dual_ref = [&]() {
            std::fill(dist.begin(), dist.end(),
                      std::numeric_limits<Cost>::max());
            std::fill(pv.begin(), pv.end(), -1);
            std::fill(pe.begin(), pe.end(), -1);
            std::fill(vis.begin(), vis.end(), false);
            struct Q {
                Cost key;
                int to;
                bool operator<(Q r) const { return key > r.key; }
            };
            std::priority_queue<Q> que;
            dist[s] = 0;
            que.push(Q{0, s});
            while (!que.empty()) {
                int v = que.top().to;
                que.pop();
                if (vis[v]) continue;
                vis[v] = true;
                if (v == t) break;
                for (int i = 0; i < (g[v].size()); i++) {
                    auto e = g[v][i];
                    if (vis[e.to] || !e.cap) continue;
                    Cost cost = e.cost - dual[e.to] + dual[v];
                    if (dist[e.to] - dist[v] > cost) {
                        dist[e.to] = dist[v] + cost;
                        pv[e.to] = v;
                        pe[e.to] = i;
                        que.push(Q{dist[e.to], e.to});
                    }
                }
            }
            if (!vis[t]) {
                return false;
            }

            for (int v = 0; v < _n; v++) {
                if (!vis[v]) continue;
                dual[v] -= dist[t] - dist[v];
            }
            return true;
        };
        Cap flow = 0;
        Cost cost = 0, prev_cost_per_flow = -1;
        std::vector<std::pair<Cap, Cost>> result;
        result.push_back({flow, cost});
        while (flow < flow_limit) {
            if (!dual_ref()) break;
            Cap c = flow_limit - flow;
            for (int v = t; v != s; v = pv[v]) {
                c = std::min(c, g[pv[v]][pe[v]].cap);
            }
            for (int v = t; v != s; v = pv[v]) {
                auto& e = g[pv[v]][pe[v]];
                e.cap -= c;
                g[v][e.rev].cap += c;
            }
            Cost d = -dual[s];
            flow += c;
            cost += c * d;
            if (prev_cost_per_flow == d) {
                result.pop_back();
            }
            result.push_back({flow, cost});
            prev_cost_per_flow = d;
        }
        return result;
    }

  private:
    int _n;

    struct _edge {
        int to, rev;
        Cap cap;
        Cost cost;
    };

    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};
int n;
P<ll,ll> p[4405];
int it[4405];
int ti;
bool cmp1(int x,int y){
	if(p[x].F!=p[y].F)RE p[x].F<p[y].F;
	else RE MP(p[x].F+p[x].S*ti,x)>MP(p[y].F+p[y].S*ti,y);
}
bool cmp2(int x,int y){
	RE MP(p[x].F+p[x].S*ti,x)<MP(p[y].F+p[y].S*ti,y);
}
ll num[4405],num2[4405];
bool check(int x){
	ti=x;
	FOR(i,1,n+n)it[i]=i;
	sort(it+1,it+n+n+1,cmp1);
	ll maxi=0;
	int len=0;
	FOR(i,1,n+n){
		gmax(maxi,1ll*p[it[i]].S*ti+p[it[i]].F);
		if(it[i]<=n)num[++len]=maxi;
	}
	FOR(i,n+1,n+n)num2[i-n]=p[i].F+p[i].S*ti;
	sort(num2+1,num2+n+1);
	FOR(i,1,n)if(num[i]<num2[i])RE 0;
	RE 1;
}
signed main(){
//	freopen("in.txt","r",stdin);
//	freopen("deal.in","r",stdin);
//	freopen("deal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n+n)cin>>p[i].S>>p[i].F;
	int l=0,r=1e9,mid,ans=-1;
	while(r>=l){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	if(ans==-1){
		cout<<-1;RE 0;
	}
	cout<<ans<<' ';
	int S=4*n+1,T=S+1;
	ti=ans;
	mcf_graph<int,int> F(T+2);
	FOR(i,1,n)F.ad(S,i,1,0);
	FOR(i,n+1,n+n)F.ad(i,T,1,0);
	FOR(i,n+1,n+n)it[i]=i;
	sort(it+n+1,it+n+n+1,cmp1);
	FOR(i,n+2,n+n)F.ad(i+n,i+n-1,n,0);
	FOR(i,n+1,n+n)F.ad(i+n,it[i],1,0);
	FOR(i,1,n){
		for(int j=n+n;j>n;j--)if(p[it[j]].F<=p[i].F){
			F.ad(i,j+n,1,1);break;
		}
	}
	FOR(i,n+1,n+n)it[i]=i;
	sort(it+n+1,it+n+n+1,cmp2);
	FOR(i,n+2,n+n)F.ad(i+n+n,i+n+n-1,n,0);
	FOR(i,n+1,n+n)F.ad(i+n+n,it[i],1,1);
	FOR(i,1,n){
		ll maxi=0;
		FOR(j,1,n+n)if(p[j].F<=p[i].F)gmax(maxi,p[j].F+p[j].S*ti); 
		for(int j=n+n;j>n;j--)if(p[it[j]].F+p[it[j]].S*ti<=maxi){
			F.ad(i,j+n+n,1,1);break;
		}
		for(int j=n+n;j>n;j--)if(p[it[j]].F+p[it[j]].S*ti<=p[i].F+p[i].S*ti){
			F.ad(i,j+n+n,1,0);break;
		}
	}
	P<int,int> t=F.flow(S,T);
	cout<<t.S;
	RE 0;
}