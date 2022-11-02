#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

vector <int> all[300010];
int a[300010];

struct Treap {
	struct Node {
		int x, fix, size;
		Node *left, *right;
		Node() {}
		Node(int _x, Node *l = NULL, Node *r = NULL) {
			x = _x, left = l, right = r, fix = rand(), size = 1;
		}
		void pushup() {size = (left ? left->size : 0) + (right ? right->size : 0) + 1;}
	}*T;
	typedef pair <Node *, Node *> pnn;
	void init() {T = NULL;}
	Node *merge(Node *l, Node *r) {
		if (!l || !r) return l ? l : r;
		if (l->fix < r->fix) {
			l->right = merge(l->right, r);
			l->pushup();
			return l;
		} else {
			r->left = merge(l, r->left);
			r->pushup();
			return r;
		}
	}
	pnn split(Node *T, int x) {
		if (!T) return pnn(NULL, NULL);
		if (x < T->x) {
			pnn t = split(T->left, x);
			T->left = t.se, T->pushup();
			return mp(t.fi, T);
		} else {
			pnn t = split(T->right, x);
			T->right = t.fi, T->pushup();
			return mp(T, t.se);
		}
	}
	void insert(int x) {
		pnn t1 = split(T, x - 1);
		T = merge(t1.fi, merge(new Node(x), t1.se));
	}
	int query1(int x) {
		pnn t1 = split(T, x);
		int ans = t1.fi ? t1.fi->size : 0;
		T = merge(t1.fi, t1.se);
		return ans;
	}
};

struct Node {
	int sum;
	Node *lson, *rson;
	Node() {sum = 0, lson = rson = NULL;}
	Node(int x) {sum = x, lson = rson = NULL;}
	void pushup() {sum = lson->sum + rson->sum;}
}*T = NULL;

void Build(Node *&T, int l, int r) {
	T = new Node();
	if (l == r) return ;
	int mid = l + r >> 1;
	Build(T->lson, l, mid), Build(T->rson, mid + 1, r);
}

Node *Update(Node *T, int l, int r, int pos, int x) {
	if (l == r) return new Node(T->sum + x);
	int mid = l + r >> 1;
	Node *now = new Node(); now->lson = T->lson, now->rson = T->rson; 
	if (pos <= mid) now->lson = Update(T->lson, l, mid, pos, x);
	else now->rson = Update(T->rson, mid + 1, r, pos, x);
	now->pushup();
	return now;
}

int Query(Node *T, int l, int r, int L, int R) {
	if (l == L && r == R) return T->sum;
	int mid = l + r >> 1;
	if (R <= mid) return Query(T->lson, l, mid, L, R);
	if (L > mid) return Query(T->rson, mid + 1, r, L, R);
	return Query(T->lson, l, mid, L, mid) + Query(T->rson, mid + 1, r, mid + 1, R);
}

Node *rt[300010];
int last[300010];
int ans[300010][2];

int main () {
	srand((int)time(NULL));
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &a[i]);
		all[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		last[i] = m + 1;
	}
	Build(rt[m + 1], 1, m + 1);
	for (int i = m; i >= 1; i--) {
		rt[i] = rt[i + 1];
		rt[i] = Update(rt[i], 1, m + 1, last[a[i]], 1);
		last[a[i]] = i;
	}
	Treap T; T.init();
	for (int i = n; i >= 1; i--) {
		int ll, rr;
		if (!all[i].size()) ll = i;
		else ll = 1;
		if (!all[i].size()) rr = i + (T.T ? T.T->size : 0);
		else {
			rr = i + T.query1(all[i][0]);
			all[i].push_back(m + 1);
			for (int j = 0; j < (int)all[i].size() - 1; j++) {
				if (all[i][j] + 1 == all[i][j + 1]) continue; 
				int xx = Query(rt[all[i][j] + 1], 1, m + 1, all[i][j + 1], m + 1);
				int yy = Query(rt[all[i][j + 1]], 1, m + 1, all[i][j + 1], m + 1);
				rr = max(rr, 1 + xx - yy);
			}
		}
		ans[i][0] = ll, ans[i][1] = rr;
		if (all[i].size()) T.insert(all[i][0]);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d %d\n", ans[i][0], ans[i][1]);
	}
	return 0;
}