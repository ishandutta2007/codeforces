#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

const int MAXN = (int) 2e5;

int p[MAXN + 1], which[MAXN + 1];

struct DSU {
	vector<int> par, sz;
	stack<int> stk;
	vector<set<int>> vals;
	vector<vector<int>> pos;
	int n;

	DSU(int _n) {
		n = _n;
		par.resize(n + 1);
		sz.resize(n + 1, 1);
		vals.resize(n + 1);
		pos.resize(n + 1);
		for(int i = 1; i <= n; i++) {
			vals[i].insert(p[i]);
			pos[i].push_back(i);
		}
	}

	int root(int x) {
		return (par[x] == 0 ? x : root(par[x]));
	}

	void join(int x, int y) {
		x = root(x), y = root(y);
		if(sz[x] > sz[y]) {
			swap(x, y);
		}
		if(x != y) {
			par[x] = y;
			sz[y] += sz[x];
			stk.push(x);

			for(auto it : vals[x]) {
				if(it != 0) {
					vals[y].insert(it);
					pos[which[it]].push_back(y);
				}
			}
		}
		else {
			stk.push(-1);
		}
	}

	void undo() {
		int x = stk.top();
		if(x != -1) {
			int y = par[x];
			sz[y] -= sz[x];
			par[x] = 0;

			for(auto it : vals[x]) {
				if(it != 0) {
					vals[y].erase(it);
					pos[which[it]].pop_back();
				}
			}
		}
		stk.pop();
	}
};

 
int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, m, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> q;
    for(i = 1; i <= n; i++) {
    	cin >> p[i];
    	which[p[i]] = i;
    }

    vector<int> a(m + 1), b(m + 1);
    for(i = 1; i <= m; i++) {
    	cin >> a[i] >> b[i];
    }

    vector<int> type(q + 1), info(q + 1);
    vector<bool> vis(m + 1);
    for(i = 1; i <= q; i++) {
    	cin >> type[i] >> info[i];
    	if(type[i] == 2) {
    		vis[info[i]] = true;
    	}
    }

    DSU dsu(n);
    for(i = 1; i <= m; i++) {
    	if(vis[i] == false) {
    		dsu.join(a[i], b[i]);
    	}
    }
    for(i = q; i >= 1; i--) {
    	if(type[i] == 2) {
    		dsu.join(a[info[i]], b[info[i]]);
    	}
    }

    for(i = 1; i <= q; i++) {
    	if(type[i] == 1) {
    		int nod = dsu.root(info[i]);
    		int u = which[*prev(dsu.vals[nod].end())];
    		cout << p[u] << "\n";

    		if(p[u] != 0) {
	    		for(auto id : dsu.pos[u]) {
	    			dsu.vals[id].erase(p[u]);
	    			dsu.vals[id].insert(0);
	    		}
	    		p[u] = 0;
    		}
    	}
    	else {
    		dsu.undo();
    	}
    } 
 
    return 0;
}