#include <bits/stdc++.h>

struct node {
  int val;
  int ne;
};

node ask(int v) {
  printf("? %d\n", v);
  fflush(stdout);
  int val, ne;
  scanf("%d%d", &val, &ne);
  return {val, ne};  
}

int RND() {
  int ret = rand() << 15 | rand();
  return ret;
}

int main() {
  int n, start, x;
  scanf("%d%d%d", &n, &start, &x);
  srand(time(NULL));
  node ff = ask(start);
  int best = ff.val;
  int pos = ff.ne;
  if (best >= x) {
    printf("! %d\n", best);
    fflush(stdout);
    return 0;
  }
  for (int i = 0; i < 990; i++) {
    int v = RND() % n + 1;
    node f = ask(v);
    if (f.val < x && f.val > best) {
      best = f.val;
      pos = f.ne;
    }
  }
  for (int i = 0; pos >= 0 && i < 990; i++) {
    node f = ask(pos);
    best = f.val;
    pos = f.ne;
    if (best >= x) break;
  }
  printf("! %d\n", best >= x ? best : -1);
  fflush(stdout);
}