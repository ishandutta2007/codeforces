#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

struct Node {
	int a, b, l, r, hs;
	long long mx;
	struct Node *lf, *rg;
};

typedef struct Node node;

int w, h, n;

node *H, *V;

node* init(int a, int b) {
	node *p = (node*)malloc(sizeof(node));
	p->a = p->r = a;
	p->b = p->l = b;
	p->mx = b-a;
	p->hs = 0;
	if(a >= b) {
		p->lf = p->rg = NULL;
	}else {
		int mid = (a + b) / 2;
		p->lf = init(a, mid);
		p->rg = init(mid+1, b);
	}
	return p;
}
void update(node *p, int idx) {
	p->hs = 1;
	if(p->a >= p->b) {
		p->mx = 0;
		p->l = p->r = p->a;
	}else {
		int mid = (p->a + p->b) / 2;
		update(idx <= mid ? p->lf : p->rg, idx);
		p->l = (p->lf->hs ? p->lf->l : p->rg->l);
		p->r = (p->rg->hs ? p->rg->r : p->lf->r);
		p->mx = max((long long)p->rg->l - p->lf->r, max(p->lf->mx, p->rg->mx));
	}
}
int main() {
	cin >> w >> h >> n;
	H = init(0, h);
	V = init(0, w);
	for(int i = 0;i < n;i++) {
		string s;
		int val;
		cin >> s >> val;
		if(s == "H") {
			update(H, val);
		}else {
			update(V, val);
		}
		cout << ((H->mx) * (V->mx)) << endl;
	}
	return 0;
}