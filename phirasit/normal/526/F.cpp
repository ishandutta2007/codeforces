#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

#include <malloc.h>
#include <stdlib.h>

#define N 300010

using namespace std;

typedef struct Node {
	int a, b;
	int mn, cnt, lz;
	struct Node *lf, *rg;
}node;

int stk_mx[N], stk_mn[N], sz_mx = 0, sz_mn = 0;
int arr[N];
int n;

node* init(int a, int b) {
	node *p = (node*)malloc(sizeof(node));
	p->a = a;
	p->b = b;
	p->mn = a;
	p->cnt = 1;
	p->lz = 0;
	p->lf = p->rg = NULL;
	if(a < b) {
		int mid = (a + b) / 2;
		p->lf = init(a, mid);
		p->rg = init(mid+1, b);
	}
	return p;
}
void propagate(node *p) {
	if(p->lz != 0) {
		p->lf->mn += p->lz;
		p->lf->lz += p->lz;
		p->rg->mn += p->lz;
		p->rg->lz += p->lz;
		p->lz = 0;
	}
}
void update(node *p, int a, int b, int val) {
	if(b < p->a || p->b < a) {
		return;
	}
	if(a <= p->a && p->b <= b) {
		p->mn += val;
		p->lz += val;
		return;
	}
	propagate(p);
	update(p->lf, a, b, val);
	update(p->rg, a, b, val);
	int mn = (p->lf->mn < p->rg->mn ? p->lf->mn : p->rg->mn);
	p->mn = mn;
	p->cnt = (mn == p->lf->mn ? p->lf->cnt : 0) + (mn == p->rg->mn ? p->rg->cnt : 0);
}
int query(node *p, int idx) {
	if(p->b <= idx) {
		return p->mn == 0 ? p->cnt : 0;
	}
	if(p->a > idx) {
		return 0;
	}
	propagate(p);
	return query(p->lf, idx) + query(p->rg, idx);
}
int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) {
		int r, c;
		scanf("%d%d", &r, &c);
		arr[r] = c;
	}
	
	node *head = init(1, n);
	stk_mx[sz_mx++] = 0;
	stk_mn[sz_mn++] = 0;
	
	long long ans = 0ll;
	for(int i = 1;i <= n;i++) {
		while(sz_mx > 1 && arr[stk_mx[sz_mx-1]] < arr[i]) {
			update(head, stk_mx[sz_mx-2] + 1, stk_mx[sz_mx-1], -arr[stk_mx[sz_mx-1]]);
			sz_mx--;
		}
		while(sz_mn > 1 && arr[stk_mn[sz_mn-1]] > arr[i]) {
			update(head, stk_mn[sz_mn-2] + 1, stk_mn[sz_mn-1], +arr[stk_mn[sz_mn-1]]);
			sz_mn--; 
		}
		stk_mx[sz_mx++] = i;
		stk_mn[sz_mn++] = i;
		update(head, 1, n, -1);
		update(head, stk_mx[sz_mx-2] + 1, stk_mx[sz_mx-1], +arr[i]);
		update(head, stk_mn[sz_mn-2] + 1, stk_mn[sz_mn-1], -arr[i]); 
		ans += (long long) query(head, i);
	}
	
	printf("%I64d\n", ans);
	
	return 0;
}