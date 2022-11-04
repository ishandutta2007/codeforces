#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int MAXN = (int) 1e5;

vector<pair<int, int>> g[8 * MAXN + 1];

int id_leaf[MAXN + 1], id = 0;
pair<int, int> ids[8 * MAXN + 1];

void build(int nod, int left, int right) {
	if(left == right) {
		id_leaf[left] = ++id;
		ids[nod] = {id, id};
		return ;
	}

	ids[nod] = {id + 1, id + 2};
	id += 2;

	int mid = (left + right) / 2;
	build(2 * nod, left, mid);
	build(2 * nod + 1, mid + 1, right);
}

void query(int nod, int left, int right, int l, int r, int v, int w, int type) {
	if(l <= left && right <= r) {
		if(type == 2) {
			g[id_leaf[v]].push_back({ids[nod].first, w});
		}
		else {
			g[ids[nod].second].push_back({id_leaf[v], w});
		}
		return ;
	}
	int mid = (left + right) / 2;
	if(l <= mid) query(2 * nod, left, mid, l, r, v, w, type);
	if(mid < r) query(2 * nod + 1, mid + 1, right, l, r, v, w, type);
}


ll dst[8 * MAXN + 1];
bool vis[8 * MAXN + 1];


int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
   	int i, n, q, s;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q >> s;

    build(1, 1, n);
    for(i = 1; i <= 4 * n; i++) {
    	g[ids[i].first].push_back({ids[2 * i].first, 0});
    	g[ids[i].first].push_back({ids[2 * i + 1].first, 0});
    	g[ids[2 * i].second].push_back({ids[i].second, 0});
    	g[ids[2 * i + 1].second].push_back({ids[i].second, 0});
    }

    while(q--) {
    	int type;
    	cin >> type;
    	if(type == 1) {
    		int v, u, w;
    		cin >> v >> u >> w;
    		g[id_leaf[v]].push_back({id_leaf[u], w});
    	}
    	else {
    		int v, l, r, w;
    		cin >> v >> l >> r >> w;
    		query(1, 1, n, l, r, v, w, type);
    	}
    }

    priority_queue<pair<ll, int>> pq;
    for(i = 1; i <= 8 * n; i++) {
    	dst[i] = 1e18;
    }

    dst[id_leaf[s]] = 0;
    pq.push({0, id_leaf[s]});

    while(pq.size()) {
    	auto cur = pq.top();
    	pq.pop();

    	if(vis[cur.second]) continue;
    	vis[cur.second] = 1;

    	for(auto it : g[cur.second]) {
    		if(dst[it.first] > -cur.first + it.second) {
    			dst[it.first] = -cur.first + it.second;
    			pq.push({-dst[it.first], it.first});
    		}
    	}
    }

    for(i = 1; i <= n; i++) {
    	int cur = id_leaf[i];
    	if(dst[cur] == 1e18) dst[cur] = -1;
    	cout << dst[cur] << " ";
    }
    
    return 0;
}