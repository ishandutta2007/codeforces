#include <stdio.h>
#include <vector>
#include <malloc.h>
#include <stdlib.h>

#define N 100010
#define INF (-1u/2)

using namespace std;

typedef struct Node {
	int a, b, mn;
	struct Node *lf, *rg;
}node;

vector<int> rwV[N], colV[N];
node *head_rw[N], *head_col[N];
int n, m, k, q;

node* init(int a, int b) {
	node* p = (node*)malloc(sizeof(node));
	p->a = a;
	p->b = b;
	p->mn = 0;
	if(a < b) {
		int mid = (a + b) / 2;
		p->lf = init(a, mid);
		p->rg = init(mid+1, b);
	}else {
		p->lf = p->rg = NULL;
	}
	return p;
}
node* update(node* p, int idx, int val) {
	node *q = (node*)malloc(sizeof(node));
	q->a = p->a;
	q->b = p->b;
	if(p->a >= p->b) {
		q->mn = val;
		q->lf = NULL;
		q->rg = NULL;
	}else {
		int mid = (p->a + p->b) / 2;
		q->lf = (idx <= mid ? update(p->lf, idx, val) : p->lf);
		q->rg = (idx > mid ? update(p->rg, idx, val) : p->rg);
		q->mn = min(q->lf->mn, q->rg->mn);
	}
	return q;
}
int query(node *p, int x, int y) {
	if(x <= p->a && p->b <= y) {
		return p->mn;
	}
	if(y < p->a || x > p->b) {
		return INF;
	}
	return min(query(p->lf, x, y), query(p->rg, x, y));
}
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(int i = 0;i < k;i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		rwV[y].push_back(x);
		colV[x].push_back(y);
	}
	head_rw[0] = init(1, n);
	for(int i = 1;i <= m;i++) {
		head_rw[i] = head_rw[i-1];
		for(int c : rwV[i]) {
			head_rw[i] = update(head_rw[i], c, i);
		}
	}
	head_col[0] = init(1, m);
	for(int i = 1;i <= n;i++) {
		head_col[i] = head_col[i-1];
		for(int r : colV[i]) {
			head_col[i] = update(head_col[i], r, i);
		}
	}
	for(int i = 0;i < q;i++) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int r1 = query(head_rw[y2], x1, x2);
		int r2 = query(head_col[x2], y1, y2);
		printf("%s\n", (r1 >= y1 || r2 >= x1) ? "YES" : "NO");
	}
	return 0;
}