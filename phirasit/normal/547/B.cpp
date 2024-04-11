#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
  int a, b, sz;
  int mx;
  int l, r;
  node *lf, *rg;
  node(int _a, int _b) : 
    lf(NULL), rg(NULL), a(_a), b(_b), l(0), r(0), mx(0), sz(_b-_a+1) {}
};

const int N = 200010;

node *head;
int ans[N];
int arr[N], idx[N];
int n;

node* init(int a, int b) {
  node *p = new node(a, b);
  if(a < b) {
    int mid = (a + b) / 2;
    p->lf = init(a, mid);
    p->rg = init(mid+1, b);
  }
  return p;
}
void update(node *p, int idx) {
  if(p->a >= p->b) {
    p->l = p->r = p->mx = 1;
    return;
  }
  int mid = (p->a + p->b) / 2;
  update(idx <= mid ? p->lf : p->rg, idx);
  p->l = p->lf->l + (p->lf->l == p->lf->sz ? p->rg->l : 0);
  p->r = p->rg->r + (p->rg->r == p->rg->sz ? p->lf->r : 0);
  p->mx = max(p->lf->r + p->rg->l, max(p->lf->mx, p->rg->mx));
}
int main() {

  scanf("%d", &n);
  for(int i = 0;i < n;i++) {
    scanf("%d", &arr[i]);
    idx[i] = i;
  }
  sort(idx, idx + n, [&](int id1, int id2) {
    return arr[id1] > arr[id2];
  });

  head = init(0, n-1);
  for(int i = 0;i < n;i++) {
    update(head, idx[i]);
    ans[head->mx] = max(ans[head->mx], arr[idx[i]]);
  }
  for(int i = n-1;i >= 1;i--) {
    ans[i] = max(ans[i], ans[i+1]);
  }
  for(int i = 1;i <= n;i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}