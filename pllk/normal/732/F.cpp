#include <iostream>
#include <vector>

#define F first
#define S second

using namespace std;
struct Bridges {
	vector<int> c, h;
	void dfs(vector<pair<int, int> >* g, int x, int pe, int d, vector<int>& ns) {
		if (h[x]) return;
		h[x]=d;
		ns.push_back(x);
		for (auto nx:g[x]) {
			if (nx.S!=pe) {
				dfs(g, nx.F, nx.S, d+1, ns);
				h[x]=min(h[x], h[nx.F]);
			}
		}
		if (h[x]==d) {
			while (ns.size()>0) {
				int t=ns.back();
				c[t]=x;
				ns.pop_back();
				if (t==x) break;
			}
		}
	}
	Bridges(vector<pair<int, int> >* g, int n) : c(n+1), h(n+1) {
		vector<int> ns;
		for (int i=1;i<=n;i++) {
			dfs(g, i, -1, 1, ns);
		}
	}
};

int n, m;
vector<pair<int,int>> g[404040];
int c[404040];
int u, z;

int e[404040];
int f[404040][2];
int q[404040];

void lol(int s) {
    if (e[s]) return;
    e[s] = 1;
    for (int i = 0; i < g[s].size(); i++) {
        if (!q[g[s][i].second]) {
            f[g[s][i].second][0] = g[s][i].first;
            f[g[s][i].second][1] = s;
            q[g[s][i].second] = 1;
        }
        lol(g[s][i].first);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }
    Bridges b(g,n);
    for (int i = 1; i <= n; i++) {
        c[b.c[i]]++;
        if (c[b.c[i]] > u) {
            u = c[b.c[i]];
            z = i;
        }
    }
    cout << u << "\n";
    lol(z);
    for (int i = 1; i <= m; i++) {
        cout << f[i][0] << " " << f[i][1] << "\n";
    }
}