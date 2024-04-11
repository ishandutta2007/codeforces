#include <iostream>
#include <algorithm>

#include <stdlib.h>
#include <malloc.h>

#define N 100010
#define SQN 940
#define MX_SQN 881920

using namespace std;

struct Node {
	int zero, val, a, b;
	struct Node *lf, *rg;
};

typedef struct Node node;

node *head;
int Gnum[MX_SQN];

long long arr[N];
int n;

node *tmp;

node* new_node(int a, int b) {
	node *p = (node*)malloc(sizeof(node));
	p->a = a, p->b = b;
	p->val = 0;
	p->zero = 1;
	p->lf = p->rg = NULL;
	return p;
}
node* init_tree(int a, int b) {
	node *p = new_node(a, b);
	if(a >= b &&  a== 0) {
		tmp = p;
	}
	if(a < b) {
		int mid = (a + b) / 2;
		p->lf = init_tree(a, mid);
		p->rg = init_tree(mid+1, b);
	}
	return p;
}
void update(node *p, int idx, int val) {
	if(p->lf == NULL) {
		p->val += val;
		p->zero = (p->val == 0);
	}else {
		int mid = (p->a + p->b) / 2;
		update(idx <= mid ? p->lf : p->rg, idx, val);
		p->zero = p->lf->zero | p->rg->zero;
	}
}
void reset(node *p) {
	if(p == NULL) {
		return;
	}
	p->val = 0;
	p->zero = 1;
	reset(p->lf);
	reset(p->rg);
}
int query(node *p) {
	if(p->lf == NULL) {
		return p->a;
	}
	return query(p->lf->zero ? p->lf : p->rg);
}
int main() {
	cin >> n;
	for(int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
	head = init_tree(0, SQN);
	long long l = 2, r = 1;
	for(int i = 0;i < MX_SQN;i++) {
		if(i < 4) {
			Gnum[i] = 0;
			continue;
		}
		long long x = l * l;
		while(x * x < i) {
			update(head, Gnum[l++], -1);
			x = l * l;
		}
		while((r+1) * (r+1) <= i) {
			update(head, Gnum[++r], 1);
		}
		Gnum[i] = query(head);
	}
	l = 2;
	r = 1;
	int ans = 0;
	reset(head);
	for(int i = 0;i < n;i++) {
		if(arr[i] < 4) {
			continue;
		}
		long long x = l * l;
		while(x * x < arr[i]) {
			update(head, Gnum[l++], -1);
			x = l * l;
		}
		while((r+1) * (r+1) <= arr[i]) {
			update(head, Gnum[++r], 1);
		}
		ans ^= query(head);
	}
	cout << (ans ? "Furlo" : "Rublo") << endl;
	return 0;
}