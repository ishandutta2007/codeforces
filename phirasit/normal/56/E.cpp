#include <stdio.h>
#include <algorithm>
#include <malloc.h>
#include <stdlib.h>

#define N 100010

using namespace std;

typedef pair<int, int> pii;

typedef struct Node {
	int mx, a, b;
	struct Node *lf, *rg;
}node;

int dp[N], idx[N];
pii arr[N];
int n;

node* init(int a, int b) {
	node *p = (node*)malloc(sizeof(node));
	p->a = a;
	p->b = b;
	p->mx = 0;
	p->lf = p->rg = NULL;
	if(a < b) {
		int mid = (a + b) / 2;
		p->lf = init(a, mid);
		p->rg = init(mid+1, b);
	}
	return p;
}
void update(node *p, int idx, int val) {
	if(p->a >= p->b) {
		p->mx = val;
		return;
	}
	update(idx <= p->lf->b ? p->lf : p->rg, idx, val);
	p->mx = max(p->lf->mx, p->rg->mx);
}
int query(node *p, int idx) {
	if(p->b <= idx) {
		return p->mx;
	}
	if(p->a > idx) {
		return 0;
	}
	return max(query(p->lf, idx), query(p->rg, idx));
}
int cmp(int a, int b) {
	return arr[a] < arr[b];
}
int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d%d", &arr[i].first, &arr[i].second);
		idx[i] = i;
	}
	
	sort(idx, idx+n, cmp);	
	node *head = init(0, n-1);
	
	for(int i = n-1;i >= 0;i--) {
		int id = idx[i];
		int a = i, b = n-1;
		int p = arr[id].first + arr[id].second;
		while(a < b) {
			int mid = (a + b) / 2 + 1;
			if(arr[idx[mid]].first < p) {
				a = mid;
			}else {
				b = mid - 1;
			}
		}
		dp[id] = (i == a ? 1 : query(head, a) - i);
		update(head, i, dp[id] + i);
	}
	for(int i = 0;i < n;i++) {
		printf("%d ", dp[i]);
	}
	printf("\n");
	return 0;
}