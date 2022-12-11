#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

#include <malloc.h>
#include <stdlib.h>

#define N 100010
#define LG_N 17
#define MOD 1000000007ll

using namespace std;

struct Node {
	int a, b;
	long long val, val2, val3;
	struct Node *lf, *rg;
};
typedef struct Node node;
typedef pair<int, int> PII;

long long sum[N];

node *head[N];
vector<PII> adj[N];
PII P[N];

int n, m, s, t;

node* new_node(int a, int b) {
	node *p = (node*)malloc(sizeof(node));
	p->a = a, p->b = b;
	p->lf = p->rg = NULL;
	p->val = 0ll;
	return p;
}
long long hash(long long a, long long b) {
	if(a == b && 0 <= a && a <= 1) {
		return a;
	}else {
		long long val = (a + 4 * b) + (a ^ MOD) - (b >> 2);
		while(val == 0 || val == 1) {
			val += 4 * a + (b ^ 230) + 5 * (b-a) ;
		}
		return val;
	}
}
long long hash2(long long a, long long b) {
	if(a == b && 0 <= a && a <= 1) {
		return a;
	}else {
		long long val = (8 * (b - a) + a / (30 + MOD) ^ b);
		while(val == 0 || val == 1) {
			val += (a == 0ll ? b : (b/a)) + 10 * b / 2 + 45 ^ a + (MOD * b) ^ a;
		}
		return val;
	}
}
long long hash3(long long a, long long b) {
	if(a == b && 0 <= a && a <= 1) {
		return a;
	}else {
		long long val = (b * (a % 2340) << 3) + (a-b) ^ MOD;
		while(val == 0 || val == 1) {
			val += a / 40 + b * (b-a) ^ MOD;
		}
		return val;
	}
}
bool node_less(node* d1, node* d2, long long s, long long s2) {
	if(d2 == NULL) {
		return true;
	}
	if(d1->lf == NULL) {
		return d1->val < d2->val;
	}else {
		if(s == -1 && 0 <= d1->val && d1->val <= 1) s = d1->val;
		if(s2 == -1 && 0 <= d2->val && d2->val <= 1) s2 = d2->val;
		if(s != -1 && s2 != -1) {
			return s < s2;
		}
		long long h1 = d1->rg->val;
		long long h2 = d1->rg->val2;
		long long h3 = d1->rg->val3;
		long long H1 = d2->rg->val;
		long long H2 = d2->rg->val2;
		long long H3 = d2->rg->val3;
		if(s != -1) {
			h1 = h2 = h3 = s;
		}
		if(s2 != -1) {
			H1 = H2 = H3 = s2;
		}
		if(h1 == H1 && h2 == H2 && h3 == H3) {
			return node_less(d1->lf, d2->lf, s, s2);
		}else {
			return node_less(d1->rg, d2->rg, s, s2);
		}
	}
}
int search(node *h, int x) {
	if(h->val == 1 || x > h->b) {
		return -1;
	}else if(h->val == 0 || h->a >= h->b) {
		return max(x, h->a);
	}else {
		int r = search(h->lf, x);
		if(r != -1) {
			return r;
		}else {
			return search(h->rg, x);
		}
	}
}
node* update(node *h, int x, int y, long long s) {
	node *p = new_node(h->a, h->b);
	if(p->a >= p->b) {
		p->val = p->val2 = p->val3 = (p->a == y);
//	}else if(x <= p->a && p->b < y) {
//		p->val = p->val2 = p->val3 = 0ll;
//		p->lf = h->lf;
//		p->rg = h->rg;
	}else {
		int mid = (p->a + p->b) / 2;
		long long h1, h2, h3, H1, H2, H3;
		if(s == -1 && (0 <= h->val && h->val <= 1)) {
			s = h->val;
		}
		if(x <= mid) {
			p->lf = update(h->lf, x, y, s);
			h1 = p->lf->val;
			h2 = p->lf->val2;
			h3 = p->lf->val3;
		}else {
			p->lf = h->lf;
			if(s != -1) {
				h1 = h2 = h3 = s;
			}else {
				h1 = h->lf->val;
				h2 = h->lf->val2;
				h3 = h->lf->val3;
			}
		}
		if(mid+1 <= y) {
			p->rg = update(h->rg, x, y, s);
			H1 = p->rg->val;
			H2 = p->rg->val2;
			H3 = p->rg->val3;
		}else {
			p->rg = h->rg;
			if(s != -1) {
				H1 = H2 = H3 = s;
			}else {
				H1 = h->rg->val;
				H2 = h->rg->val2;
				H3 = h->rg->val3;
			}
		}
		p->val = hash(h1, H1);
		p->val2 = hash2(h2, H2);
		p->val3 = hash3(h3, H3);
	}
	return p;
}
node* init_tree(int a, int b) {
	node *p = new_node(a, b);
	if(a < b) {
		int mid = (a + b) / 2;
		p->lf = init_tree(a, mid);
		p->rg = init_tree(mid+1, b);
		p->val = hash(p->lf->val, p->rg->val);
		p->val2 = hash2(p->lf->val2, p->rg->val2);
		p->val3 = hash3(p->lf->val3, p->rg->val3);
	}else {
		p->val = p->val2 = p->val3 = 0ll;
	}
	return p;
}

class Data {
	public :
		int u;
		int p, x;
		node *tree;
		Data(int _u, int _p, int _x) : u(_u), p(_p), x(_x) {
			tree = update(head[p], x, search(head[p], x), -1);
		}
};

typedef class Data data;
priority_queue<data> heap;

bool operator<(data D1, data D2) {
	return node_less(D2.tree, D1.tree, -1, -1);
}

int main() {
	cin >> n >> m;
	int mx = 0;
	for(int i = 0;i < m;i++) {
		int u, v, x;
		cin >> u >> v >> x;
		adj[u].push_back({v, x});
		adj[v].push_back({u, x});
		mx = max(mx, x);
	}
	cin >> s >> t;
	
	for(int i = 1;i <= n;i++) {
		head[i] = NULL;
		P[i] = {-1, -1};
	}

	sum[0] = 1ll;
	for(int i = 1;i <= mx;i++) {
		sum[i] = (2 * sum[i-1]) % MOD;
	}
	
	head[s] = init_tree(0, LG_N*N);
	P[s] = {-2, -2};
	
	for(int i = 0;i < adj[s].size();i++) {
		int v = adj[s][i].first, x = adj[s][i].second;
		heap.push(data(v, s, x));
	}
	
	
	while(!heap.empty()) {
		data top = heap.top();
		heap.pop();
		if(P[top.u].first != -1) {
			continue;
		}
		head[top.u] = top.tree;
		P[top.u] = {top.p, top.x};
		for(int i = 0;i < adj[top.u].size();i++) {
			int v = adj[top.u][i].first, x = adj[top.u][i].second;
			if(P[v].first == -1) {
				heap.push(data(v, top.u, x));
			}
		}	
	}
	
	if(P[t].first == -1) {
		cout << -1 << endl;
		return 0;
	}
	
	int u = t;
	stack<int> Path;
	long long ans = 0ll;
	while(u != -2) {
		Path.push(u);
		if(P[u].second >= 0) {
			ans = (ans + sum[P[u].second]) % MOD;
		}
		u = P[u].first;
	}
	cout << ans << endl;
	cout << Path.size() << endl;
	while(!Path.empty()) {
		cout << Path.top() << " ";
		Path.pop();
	}
	cout << endl;
	
	return 0;
}