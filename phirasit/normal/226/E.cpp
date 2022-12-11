#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;
const int LG_N = 20;

struct node {
	int l, r, cnt;
	node *left, *right;
	node(int _l, int _r, int _c = 0) : l(_l), r(_r), cnt(_c) {}
};

node* init(int l, int r) {
	node *p = new node(l, r);
	if(l < r) {
		int mid = (l + r) / 2;
		p->left = init(l, mid);
		p->right = init(mid+1, r);
	}
	return p;
}
node* update(node *p, int idx) {
	node *q = new node(p->l, p->r, p->cnt + 1);
	if(p->l < p->r) {
		int mid = (p->l + p->r) / 2;
		q->left = (idx <= mid ? update(p->left, idx) : p->left);
		q->right = (idx > mid ? update(p->right, idx) : p->right);
	}
	return q;
}
int seg_query(node *p, int l, int r) {
	if(p->r < l or r < p->l) return 0;
	if(l <= p->l and p->r <= r) return p->cnt;
	return seg_query(p->left, l, r) + seg_query(p->right, l, r);
}

struct Query {
	int type, u, v, k, y;
	void read(void) {
		scanf("%d", &type);
		if(type == 1) {
			scanf("%d", &u);
		}else {
			scanf("%d%d%d%d", &u, &v, &k, &y);
		}
	}
} query[N];

node *head[N];

vector<int> adj[N];
int P[N][LG_N], H[N];

int attack_year[N];
int n, m;

int root = 1;

int count(int u, int v, int l, int r) {
	int ans = 0;
	if(l > 0) {
		ans += seg_query(head[u], 1, l-1);
		ans -= seg_query(head[v], 1, l-1);
	}
	if(r < m+1) {
		ans += seg_query(head[u], r+1, m+1);
		ans -= seg_query(head[v], r+1, m+1);	
	}
	return ans;
}
int my_advance(int u, int l) {
	for(int i = LG_N-1;i >= 0;i--) {
		if((1 << i) <= l) {
			l -= 1 << i;
			u = P[u][i];
		}
	}
	return u;
}
int lca(int u, int v) {
	if(H[u] < H[v]) swap(u, v);
	for(int i = LG_N-1;i >= 0;i--) {
		if(H[P[u][i]] >= H[v]) {
			u = P[u][i];
		}
	}
	if(u == v) return u;
	for(int i = LG_N-1;i >= 0;i--) {
		if(P[u][i] != P[v][i]) {
			u = P[u][i];
			v = P[v][i];
		}
	}
	return P[u][0];
}
void dfsInit(int u, int h) {
	H[u] = h;
	for(int i = 1;i < LG_N;i++) {
		P[u][i] = P[P[u][i-1]][i-1];
	}
	head[u] = update(u == root ? (head[0] = init(0, m+1)) : head[P[u][0]], attack_year[u]);
	for(int v : adj[u]) {
		dfsInit(v, h+1);
	}
}
int main() {

	scanf("%d", &n);
	for(int i = 1;i <= n;i++) {
		int u;
		scanf("%d", &u);
		if(u == 0) {
			root = i;
		}
		adj[u].push_back(i);
		P[i][0] = u;
	}

	scanf("%d", &m);
	for(int i = 1;i <= n;i++) {
		attack_year[i] = m + 1;
	}
	for(int i = 1;i <= m;i++) {
		query[i].read();
		if(query[i].type == 1) {
			attack_year[query[i].u] = i;
		}
	}

	H[0] = 0;
	dfsInit(root, 1);

	for(int i = 1;i <= m;i++) {
		if(query[i].type == 1) continue;
		int u = query[i].u, v = query[i].v, k = query[i].k, y = query[i].y;
		int l = lca(u, v);

		k += (attack_year[u] < y+1 or attack_year[u] > i);

		int lo = 0, hi = H[u] - H[l];
		while(lo < hi) {
			int mid = (lo + hi) / 2;
			if(count(u, my_advance(u, mid+1), y+1, i) >= k) {
				hi = mid;
			}else {
				lo = mid + 1;
			}
		}

		k -= count(u, my_advance(u, lo+1), y+1, i);
		u = my_advance(u, lo);

		if(k == 0) {
			printf("%d\n", (u == v ? -1 : u));
			continue;
		}	

		k = count(v, l, y+1, i) - k + 1;

		if(k >= 0) {
			lo = 0, hi = H[v] - H[l];
			while(lo < hi) {
				int mid = (lo + hi) / 2;
				if(count(v, my_advance(v, mid+1), y+1, i) >= k) {
					hi = mid;
				}else {
					lo = mid + 1;
				}
			}
			k -= count(v, my_advance(v, lo+1), y+1, i);
			v = my_advance(v, lo);
			if(lo == 0) {
				k = -1;
			}
		}

		if(k == 0) {
			printf("%d\n", v);
		}else {
			printf("-1\n");
		}
	}
	return 0;
}