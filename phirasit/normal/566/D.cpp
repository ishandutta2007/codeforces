#include <stdio.h>
#include <assert.h>

const int N = 200010;

int P1[N], P2[N];
int n, q;

int find(int *P, int j) {
  if(P[j] == j) {
    return j;
  }else {
    return P[j] = find(P, P[j]);
  }
}
void merge(int *P, int i, int j) {
  P[find(P, j)] = find(P, i);
}
int main() {
  scanf("%d%d", &n, &q);
  for(int i = 1;i <= n;i++) {
    P1[i] = P2[i] = i;
  }
  for(int i = 0;i < q;i++) {
    int type;
    scanf("%d", &type);
    if(type == 1) {
      int x, y;
      scanf("%d%d", &x, &y);
      merge(P1, x, y);
    }else if(type == 2) {
      int x, y;
      scanf("%d%d", &x, &y);
      assert(x <= y);
      while(find(P2, x) != find(P2, y)) {
        merge(P1, x, find(P2, x) + 1);
        merge(P2, find(P2, x) + 1, x);
      }
    }else {
      int x, y;
      scanf("%d%d", &x, &y);
      printf("%s\n", find(P1, x) == find(P1, y) ? "YES" : "NO");
    }
  }
  return 0;
}