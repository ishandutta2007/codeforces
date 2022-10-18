#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define sz(c) ((int) (c).size())
#define pb push_back

const int MOD = int(1e9 + 7);
const int MAXN = int(3e5 + 5);

void add(int& x, int y) {
	if  ((x += y) >= MOD) {
		x -= MOD;
	}
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

struct Node {
	map <char, Node*> next;
	Node* link;
	int len;
	int cnt[3];

	Node() {
		link = nullptr;
		len = 0;
		memset (cnt, 0, sizeof cnt);
	}
};

int ans[MAXN];

struct SuffixAutomaton {
	Node* root;
	vector <Node*> nodes;

	Node* new_node() {
		nodes.pb(new Node());
		return nodes.back();
	}

	void add_char(char c, Node*& last) {
		Node* cur = new_node();
		cur->len = last->len + 1;

		Node* p = last;
		while (p && !p->next.count(c)) {
			p->next[c] = cur;
			p = p->link;
		}

		if  (!p) {
			cur->link = root;
			last = cur;
			return;
		}

		Node* q = p->next[c];
		if  (q->len == p->len + 1) {
			cur->link = q;
			last = cur;
			return;
		}

		Node* clone = new_node();
		clone->next = q->next;
		clone->link = q->link;
		clone->len = p->len + 1;
		while (p && p->next.count(c) && p->next[c] == q) {
			p->next[c] = clone;
			p = p->link;
		}
		cur->link = clone;
		q->link = clone;
		last = cur;
	}

	SuffixAutomaton() {}

	SuffixAutomaton(const string& s) {
		root = new_node();

		Node* last = root;
		forn(i, sz(s)) {
			add_char(s[i], last);
		}
	}

	void push_cnt() {
		sort(nodes.begin(), nodes.end(), [] (Node* v1, Node* v2) { return v1->len > v2->len; });

		for (Node* v : nodes) {
			if  (v->link) {
				forn(i, 3) {
					v->link->cnt[i] += v->cnt[i];
				}
			}
		}
	}

	void add_ans() {
		for (Node* v : nodes) {
			if  (v->link) {
				int l = v->link->len + 1;
				int r = v->len;
				int val = mul(v->cnt[0], mul(v->cnt[1], v->cnt[2]));

				add(ans[l], val);
				add(ans[r + 1], - val + MOD);
			}
		}
	}
};

void put_cnt(Node* v, const string& s, int pos, int id) {
	++v->cnt[id];
	
	if  (pos == sz(s)) {
		return;
	}

	put_cnt(v->next[s[pos]], s, pos + 1, id);
}

SuffixAutomaton aut;

int main() {
	string s1, s2, s3;
	getline(cin, s1);
	getline(cin, s2);
	getline(cin, s3);
	aut = SuffixAutomaton(s1 + "#" + s2 + "$" + s3);

	put_cnt(aut.root, s1, 0, 0);
	put_cnt(aut.root, s2, 0, 1);
	put_cnt(aut.root, s3, 0, 2);
	aut.push_cnt();
	aut.add_ans();

	forn(i, MAXN - 1) {
		add(ans[i + 1], ans[i]);
	}

	forn(i, min(sz(s1), min(sz(s2), sz(s3)))) {
		printf("%d ", ans[i + 1]);
	}
	return 0;
}