#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define F first
#define S second

// https://github.com/Laakeri/contestlib/blob/master/src/graph/bridges.cpp
struct Bridges {
	vector<int> c, h;
	void dfs(vector<pair<int, int> >* g, int x, int pe, int d, vector<int>& ns){
		if (h[x]) return;
		h[x]=d;ns.push_back(x);
		for (auto nx:g[x]) {
			if (nx.S!=pe) {
				dfs(g, nx.F, nx.S, d+1, ns);
				h[x]=min(h[x], h[nx.F]);
			}
		}
		if (h[x]==d) {
			while (ns.size()>0) {
				int t=ns.back();c[t]=x;
				ns.pop_back();
				if (t==x) break;
			}
		}
	}
	Bridges(vector<pair<int, int> >* g, int n) : c(n+1), h(n+1) {
		vector<int> ns;
		for (int i=1;i<=n;i++) dfs(g, i, -1, 1, ns);
	}
};

int n, m;
vector<pair<int,int>> v[303030];
vector<pair<int,int>> d;
set<pair<int,int>> inc;
vector<int> w[303030];

int z[303030];
int pc, ps;

void dfs(int q, int s, int c) {
    if (z[s] == q) return;
    if (c > pc) {pc = c; ps = s;}
    z[s] = q;
    for (auto x : w[s]) dfs(q,x,c+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
        d.push_back({a,b});
    }
    Bridges b(v,n);
    int a;
    for (auto x : d) {
        int s1 = b.c[x.first];
        int s2 = b.c[x.second];
        if (s1 == s2) continue;
        if (s1 > s2) swap(s1,s2);
        if (inc.count({s1,s2})) continue;
        inc.insert({s1,s2});
        w[s1].push_back(s2);
        w[s2].push_back(s1);
        a = s1;
    }
    dfs(1,a,0);
    pc = 0;
    dfs(2,ps,0);
    cout << pc << "\n";
}