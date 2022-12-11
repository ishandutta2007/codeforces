#include <stdio.h>
#include <set>
#include <map>
#include <vector>

using namespace std;

const int N = 100010;
set<int> S1, S2;
vector<int> ls1, ls2;
int n, q;

struct Query {
  int x, y;
  char str[3];
  void read(void) {
    scanf("%d%d%s", &x, &y, str);
  }
  Query() {}
};

vector<Query> Q;

struct node {
  int a, b, val;
  node *lf, *rg;
  node(int _a, int _b) :
    a(_a), b(_b), lf(NULL), rg(NULL), val(0) {}
};

node *head1, *head2;

node* init(int a, int b) {
  node *q = new node(a, b);
  if(a < b) {
    int mid = (a + b) / 2;
    q->lf = init(a, mid);
    q->rg = init(mid+1, b);
  }
  return q;
}
void update(node *p, int a, int b, int val) {
  if(a <= p->a and p->b <= b) {
    p->val = max(p->val, val);
    return;
  }
  if(b < p->a or p->b < a) {
    return;
  }
  update(p->lf, a, b, val);
  update(p->rg, a, b, val);
}
int query(node *p, int idx) {
  if(p->a >= p->b) {
    return p->val;
  }
  int mid = (p->a + p->b) / 2;
  int r = query(idx <= mid ? p->lf : p->rg, idx);
  return max(p->val, r);
}
int lower(vector<int> &V, int x) {
  if(x < V.front()) return -1;
  int a = 0, b = V.size() - 1;
  while(a < b) {
    int mid = (a + b) / 2;
    if(x <= V[mid]) {
      b = mid;
    }else {
      a = mid + 1;
    }
  }
  return a;
}
int upper(vector<int> &V, int x) {
  if(x > V.back()) return V.size();
  int a = 0, b = V.size() - 1;
  while(a < b) {
    int mid = (a + b) / 2 + 1;
    if(x >= V[mid]) {
      a = mid;
    }else {
      b = mid - 1;
    }
  }
  return a;
}   
int main() {
  scanf("%d%d", &n, &q);
  Q.resize(q, Query());
  for(int i = 0;i < q;i++) {
    Q[i].read();
    S1.insert(Q[i].x);
    S2.insert(Q[i].y);
  }
  ls1 = vector<int>(S1.begin(), S1.end());
  ls2 = vector<int>(S2.begin(), S2.end());

  head1 = init(0, S1.size()-1);
  head2 = init(0, S2.size()-1);
  for(int i = 0;i < Q.size();i++) {
    Query q = Q[i];
    if(q.str[0] == 'U') {
      int idx = lower(ls1, q.x);
      int bs = q.y - query(head1, idx);
      printf("%d\n", bs);
      int l = upper(ls2, q.y-bs+1);
      int r = lower(ls2, q.y);
      if(l <= r) {
        update(head2, l, r, q.x);
      }
      update(head1, idx, idx, q.y);
    }else {
      int idx = lower(ls2, q.y);
      int bs = q.x - query(head2, idx);
      printf("%d\n", bs);
      int l = upper(ls1, q.x-bs+1);
      int r = lower(ls1, q.x);
      if(l <= r) {
        update(head1, l, r, q.y);
      }
      update(head2, idx, idx, q.x);
    }
  }
  return 0;
}