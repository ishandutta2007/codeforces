#include <stdio.h>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

struct node {
  long long mn, lz;
  int a, b;
  node *lf, *rg;
  node(int _a, int _b) : a(_a), b(_b), lf(NULL), rg(NULL) {}
};

const int N = 200010;
const long long inf = 100000000000000000ll;
node *head;
long long arr[N];
int n, m;

void propagate(node *p) {
  p->lf->mn += p->lz;
  p->lf->lz += p->lz;
  p->rg->mn += p->lz;
  p->rg->lz += p->lz;
  p->lz = 0;
}
void update(node *p, int a, int b, long long val) {
  if(a <= p->a and p->b <= b) {
    p->mn += val;
    p->lz += val;
    return;
  }
  if(b < p->a or p->b < a) {
    return;
  }
  propagate(p);
  update(p->lf, a, b, val);
  update(p->rg, a, b, val);
  p->mn = min(p->lf->mn, p->rg->mn);
}
long long query(node *p, int a, int b) {
  if(a <= p->a and p->b <= b) {
    return p->mn;
  }
  if(b < p->a or p->b < a) {
    return inf;
  }
  propagate(p);
  return min(query(p->lf, a, b), query(p->rg, a, b));
}
node* init(int a, int b) {
  node *p = new node(a, b);
  p->lz = 0ll;
  if(a < b) {
    int mid = (a + b) / 2;
    p->lf = init(a, mid);
    p->rg = init(mid+1, b);
    p->mn = min(p->lf->mn, p->rg->mn);
  }else {
    p->mn = arr[a];
  }
  return p;
}
char read(int &x) {
  char ch;
  scanf("%d%c", &x, &ch);
  return ch;
}
int main() {
  read(n);
  for(int i = 0;i < n;i++) {
    int val;
    read(val);
    arr[i] = (long long) val;
  }
  head = init(0, n-1);
  read(m);
  for(int i = 0;i < m;i++) {
    vector<int> ops;
    while(1) {
      int data;
      char res = read(data);
      ops.push_back(data);
      if(res == '\n') {
        break;
      }
    }
    int l = ops[0], r = ops[1];
    if(ops.size() == 2) {
      if(l <= r) {
        printf("%I64d\n", query(head, l, r));
      }else {
        printf("%I64d\n", min(query(head, 0, r), query(head, l, n-1)));
      }
    }else {
      long long val = ops[2];
      if(l <= r) {
        update(head, l, r, val);
      }else {
        update(head, 0, r, val);
        update(head, l, n-1, val);
      }
    }
  }
  return 0;
}