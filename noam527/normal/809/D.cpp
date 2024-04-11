#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int rnd() {
	return ((rand() % (1 << 15)) << 16) + (rand() % (1 << 15));
}

struct node {
	node *l, *r;
	int val, key;
	int sz, tag;
	node(int value) {
		val = value;
		key = rnd();
		l = r = nullptr;
		sz = 1, tag = 0;
	}
	void push() {
		val += tag;
		if (l) l->tag += tag;
		if (r) r->tag += tag;
		tag = 0;
	}
	void upd() {
		sz = 1;
		if (l) sz += l->sz;
		if (r) sz += r->sz;
	}
	~node() {
		delete l;
		delete r;
	}
};

struct treap {
	node *root;
	treap() {
		srand(918273645);
		root = new node(0);
	}
	int size() {
		return root ? root->sz : 0;
	}
	// <
	void split(node *t, int val, node *&l, node *&r) {
		if (t == nullptr) {
			l = r = nullptr;
			return;
		}
		t->push();
		if (t->val < val) {
			split(t->r, val, l, r);
			t->r = l;
			l = t;
		}
		else {
			split(t->l, val, l, r);
			t->l = r;
			r = t;
		}
		t->upd();
	}
	// l->sz = sz
	void size_split(node *t, int sz, node *&l, node *&r) {
		if (t == nullptr) {
			l = r = nullptr;
			return;
		}
		t->push();
		int lsz = (t->l ? t->l->sz : 0); // index of t
		if (lsz < sz) {
			size_split(t->r, sz - lsz - 1, l, r);
			t->r = l;
			l = t;
		}
		else {
			size_split(t->l, sz, l, r);
			t->l = r;
			r = t;
		}
		t->upd();
	}
	node* merge(node *l, node *r) {
		if (!l || !r) return l ? l : r;
		if (l->key < r->key) {
			l->push();
			l->r = merge(l->r, r);
			l->upd();
			return l;
		}
		r->push();
		r->l = merge(l, r->l);
		r->upd();
		return r;
	}
	void upd(int st, int en) {
		// A, B, (C, D)
		node *t[4];
		split(root, st, t[0], t[1]);
		split(t[1], en, t[1], t[3]);
		if (t[3] != nullptr) {
//			cout << "special" << endl;
//			cout << "t[3]: "; print(t[3]); cout << endl;
			size_split(t[3], 1, t[2], t[3]);
			delete t[2];
//			cout << "t[3]: "; print(t[3]); cout << endl;
		}
		// t[0], st, t[1] + 1, t[3]
		if (t[1]) t[1]->tag++;
//		cout << "t[0]: "; print(t[0]); cout << endl;
//		cout << "t[1]: "; print(t[1]); cout << endl;
//		cout << "t[3]: "; print(t[3]); cout << endl;
		root = merge(merge(merge(t[0], new node(st)), t[1]), t[3]);
	}
	void print() {
		print(root);
		cout << endl;
	}
	void print(node *t) {
		if (t == nullptr) return;
		t->push();
		print(t->l);
		cout << t->val << " ";
		print(t->r);
	}
};

int n;
treap T;

int main() {
	fast;
	cin >> n;
	for (int i = 0, l, r; i < n; i++) {
		cin >> l >> r;
		T.upd(l, r);
//		cout << T.size() - 1 << endl;
//		cout << "order: ";
//		T.print();
	}
	cout << T.size() - 1 << endl;
}