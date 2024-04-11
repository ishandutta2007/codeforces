#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }
int n, m;
string s[1000002];

bool val(int i, int j) {
	return (i < n && j < m && s[i][j] == '.'); 
}

struct Dominator{
    struct min_DSU{
        vector<int> par, val;
        vector<int> const&semi;
        min_DSU(int N, vector<int> const&semi):par(N, -1),val(N), semi(semi){
            iota(val.begin(), val.end(), 0);
        }
        void comp(int x){
            if(par[par[x]]!=-1){
                comp(par[x]);
                if(semi[val[par[x]]]<semi[val[x]])
                    val[x] = val[par[x]];
                par[x]=par[par[x]];
            }
        }
        int f(int x){
            if(par[x]==-1) return x;
            comp(x);
            return val[x];
        }
        void link(int x, int p){
            par[x] = p;
        }
    };
    int N;
    vector<vector<int> > G, rG;
    vector<int> idom, order;
    Dominator(int _N):N(_N), G(N), rG(N){ }
    void add_edge(int a, int b){
        G[a].emplace_back(b);
        rG[b].emplace_back(a);
    }
    vector<int> calc_dominators(int S){
        idom.assign(N, -1);
        vector<int> par(N, -1), semi(N, -1);
        vector<vector<int> > bu(N);
        stack<int> s;
        s.emplace(S);
        while(!s.empty()){
            int a=s.top();s.pop();
            if(semi[a]==-1){
                semi[a] = order.size();
                order.emplace_back(a);
                for(int i=0;i<(int)G[a].size();++i){
                    if(semi[G[a][i]]==-1){
                        par[G[a][i]]=a;
                        s.push(G[a][i]);
                    }
                }
            }
        }
        min_DSU uni(N, semi);
        for(int i=(int)order.size()-1;i>0;--i){
            int w=order[i];
            for(int f:rG[w]){
                int oval = semi[uni.f(f)];
                if(oval>=0 && semi[w]>oval) semi[w] = oval;
            }
            bu[order[semi[w]]].push_back(w);
            uni.link(w, par[w]);
            for(int v:bu[par[w]]){
                int u=uni.f(v);
				idom[v] = semi[u] < semi[v] ? u : par[w];
            }
            bu[par[w]].clear();
        }
        for(int i=1;i<(int)order.size();++i){
            int w=order[i];
            if(idom[w] != order[semi[w]])
                idom[w] = idom[idom[w]];
        }
        idom[S]=-1;
        return idom;
    }
};

int vert(int i, int j) {
	return (i * m + j);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> s[i];
	Dominator d(n * m);
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '#') continue; 
			if (val(i + 1, j))
				d.add_edge(vert(i, j), vert(i + 1, j));
			if (val(i, j + 1))
				d.add_edge(vert(i, j), vert(i, j + 1));
		}
	d.calc_dominators(0);
	if (d.idom[n * m - 1] == -1) {
		cout << 0;
	} else if(d.idom[n * m - 1] == 0) {
		cout << 2;
	} else {
		cout << 1;
	}
}