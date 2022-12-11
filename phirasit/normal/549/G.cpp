#include <stdio.h>
#include <stdlib.h>

const int N = 500010;
const int inf = -1u/2;

struct node {
  
  int sum, val, add, lz_val;
  int sz;
  node *lf, *rg, *parent;

  ~node(void) {
    delete lf;
    delete rg;
  }
};

node *head = NULL;

int arr[N];
int n, m;

inline int max(int a, int b) { return a > b ? a : b; }
inline int getsum(node *p) { return p == NULL ? 0 : p->sum; }
inline int getsize(node *p) { return p == NULL ? 0 : p->sz; }

void fix(node *p) {
  p->sum = getsum(p->lf) + p->val + getsum(p->rg);
  p->sz = getsize(p->lf) + 1 + getsize(p->rg);
}

void edit(node *p, int val) {
  p->val += val;
  p->lz_val += val;
}
void propagate(node *p) {
  if(p->lz_val != 0) {
    if(p->lf != NULL) {
      edit(p->lf, p->lz_val);
    }
    if(p->rg != NULL) {
      edit(p->rg, p->lz_val);
    }
    p->lz_val = 0;
  }

  fix(p);
}
node* init(int a, int b) {
  if(a > b) return NULL;
  int mid = (a + b) / 2;
  node *p = new node();
  p->val = arr[mid];
  p->lz_val = 0;
  p->lf = init(a, mid-1);
  p->rg = init(mid+1, b);
  if(p->lf != NULL) {
    p->lf->parent = p;
  }
  if(p->rg != NULL) {
    p->rg->parent = p;
  }
  fix(p);
  return p;
}
void rotate(node *p) {
  node *q = p->parent;
  node *r = q->parent;
  
  if(r != NULL) {
    if(r->lf == q) {
      r->lf = p;
    }else {
      r->rg = p;
    }
    p->parent = r;
  }else {
    p->parent = NULL;
  }

  if(q->lf == p) {
    q->lf = p->rg;
    if(q->lf != NULL) q->lf->parent = q;
    p->rg = q;
    p->rg->parent = p;
  }else {
    q->rg = p->lf;
    if(q->rg != NULL) q->rg->parent = q;
    p->lf = q;
    p->lf->parent = p;
  }

  fix(q);
  fix(p);
}
void splay(node *p) {
  while(p->parent != NULL) {
    node *q = p->parent;
    node *r = q->parent;
    if(r == NULL) {
      rotate(p);
    }else {
      if((r->lf != NULL and r->lf->rg == p) or (r->rg != NULL and r->rg->lf == p)) {
        rotate(p);
        rotate(p);
      }else {
        rotate(q);
        rotate(p);
      }
    }
  }
  head = p;
}
void dfs(node *p) {
  if(p == NULL) {
    return;
  }
  propagate(p);
  dfs(p->lf);
  printf("%d ", p->val);
  dfs(p->rg);
}
void search(node *p, int val, node *t) {
  while(true) {
    propagate(p);
    int x = val - getsize(p->lf);
    if(x <= p->val) {
      if(p->lf == NULL) {
        p->lf = t;
        t->val = val;
        t->parent = p;
        splay(t);
        if(t->lf != NULL) {
          edit(t->lf, 1);
        }
        return;
      }else {
        p = p->lf;
      }
    }else {
      val -= getsize(p->lf);
      if(x == p->val+1) {
        printf(":(\n");
        exit(0);
      }
      if(p->rg == NULL) {
        p->rg = t;
        t->val = val-1;
        t->parent = p;
        splay(t);
        if(t->lf != NULL) {
          edit(t->lf, 1);
        }
        return;
      }else {
        p = p->rg;
        val -= 1;
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  for(int i = 0;i < n;i++) {
    scanf("%d", &arr[i]);
  }
  for(int i = n-1;i >= 0;i--) {
    if(i == n-1) {
      head = init(i, i);
    }else {
      search(head, arr[i], init(i, i));
    }
  }
  dfs(head);
  printf("\n");
  return 0;
}