// TCR
// Find minimum-cost k-flow
// O(VE) normalizing and O(E log V) for each augmenting path
// getKFlow augments at most k flow and returns {flow, cost}
// Uses 1-indexing
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
const ll inf=1e18;
template<int V, int E> struct MinCostFlow {
	struct Edge {
		int a, b;
		ll ca, co;
	} es[E*2];
	int eu=0,nmz=0;
	vector<int> g[V+1];
	ll p[V+1],d[V+1];
	int fr[V+1],u[V+1];
	void addEdge(int a, int b, ll ca, ll co) {
		nmz=0;
		es[eu++]={a, b, ca, co};
		es[eu++]={b, a, 0, -co};
		g[a].push_back(eu-2);
		g[b].push_back(eu-1);
	}
	void normalize(int source) {
		if (nmz) return;nmz=1;
		for (int i=1;i<=V;i++) {
			p[i]=inf;u[i]=0;
		}
		p[source]=0;
		queue<int> q;q.push(source);
		while (!q.empty()){
			int x=q.front();
			u[x]=0;q.pop();
			for (int e:g[x]) {
				if (es[e].ca>0&&p[x]+es[e].co<p[es[e].b]) {
					p[es[e].b]=p[x]+es[e].co;
					if (!u[es[e].b]) {
						u[es[e].b]=1;
						q.push(es[e].b);
					}
				}
			}
		}
	}
	ll augment(int x, ll fl) {
		if (fr[x]==-1) return fl;
		ll r=augment(es[fr[x]].a, min(fl, es[fr[x]].ca));
		es[fr[x]].ca-=r;
		es[fr[x]^1].ca+=r;
		return r;
	}
	pair<ll, ll> flow(int source, int sink, ll mf) {
		priority_queue<pair<ll, int> > dij;
		for (int i=1;i<=V;i++) {
			u[i]=0;fr[i]=-1;d[i]=inf;
		}
		d[source]=0;
		dij.push({0, source});
		while (!dij.empty()) {
			auto x=dij.top();dij.pop();
			if (u[x.S]) continue;
			u[x.S]=1;
			for (int e:g[x.S]) {
				ll nd=d[x.S]+es[e].co+p[x.S]-p[es[e].b];
				if (es[e].ca>0&&nd<d[es[e].b]) {
					d[es[e].b]=nd;
					fr[es[e].b]=e;
					dij.push({-nd, es[e].b});
				}
			}
		}
		ll co=d[sink]+p[sink];
		for (int i=1;i<=V;i++) {
			if (fr[i]!=-1) p[i]+=d[i];
		}
		if (u[sink]) {
			ll fl=augment(sink, mf);
			return {fl, fl*co};
		}
		else return {0, 0};
	}
	pair<ll, ll> getKFlow(int source, int sink, ll k) {
		ll fl=0;ll co=0;
		normalize(source);
		while (1) {
			pair<ll, ll> t=flow(source, sink, k);
			fl+=t.F;k-=t.F;co+=t.S;
			if (k==0||t.F==0) break;
		}
		return {fl, co};
	}
};

int n, m;
int r[100][100];
int c[100][100];

int main() {
    cin >> n >> m;
    int u = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> r[i][j];
            c[i][j] = ++u;
        }
    }
    MinCostFlow<100*100+10,2*100*100+10> f;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m-1; j++) {
            int a = c[i][j];
            int b = c[i][j+1];
            if ((i+j)%2 == 1) swap(a,b);
            int w = r[i][j] != r[i][j+1];
            f.addEdge(a,b,1,w);
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n-1; i++) {
            int a = c[i][j];
            int b = c[i+1][j];
            if ((i+j)%2 == 1) swap(a,b);
            int w = r[i][j] != r[i+1][j];
            f.addEdge(a,b,1,w);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((i+j)%2 == 0) {
                f.addEdge(n*m+1,c[i][j],1,0);
            } else {
                f.addEdge(c[i][j],n*m+2,1,0);
            }
        }
    }
    auto g = f.getKFlow(n*m+1,n*m+2,(n*m)/2);
    cout << g.second << "\n";
}