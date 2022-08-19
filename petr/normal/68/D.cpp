#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

struct node {
  int left;
  int right;
  int sum;

  node() {
    left = 0;
    right = 0;
    sum = 0;
  }
};

int main() {
  int h;
  int q;
  scanf("%d", &h);
  scanf("%d", &q);
  char query[10];
  vector<node> nodes(q * (h + 2) + 10);
  int lastnode = 1;
  vector<int> path(h + 2, 0);
  for (int i = 0; i < q; ++i) {
    scanf("%s", query);
    if (query[0] == 'a') {
      int plen = 0;
      int val;
      scanf("%d", &val);
      int extra;
      scanf("%d", &extra);
      while (1) {
        path[plen++] = val;
    if (val == 1) break;
    val /= 2;
      }
      int at = 1;
      for (int i = plen - 2; i >= 0; --i) {
        nodes[at].sum += extra;
        val = path[i];
    if (val % 2 == 0) {
      if (nodes[at].left == 0) {
        nodes[at].left = ++lastnode;
      }
      at = nodes[at].left;
    } else {
      if (nodes[at].right == 0) {
        nodes[at].right = ++lastnode;
      }
      at = nodes[at].right;
    }
      }
      nodes[at].sum += extra;
    } else {
      double res = 0.0;
      int at = 1;
      double pr = 1.0;
      int maxOther = 0;
      while (at != 0) {
        pr *= 0.5;
        int left = nodes[nodes[at].left].sum;
    int right = nodes[nodes[at].right].sum;
    int cur = nodes[at].sum - left - right;
    int stop = max(left, right) + cur;
    res += pr * max(maxOther, stop);
    maxOther = max(maxOther, min(left, right) + cur);
    if (left > right) at = nodes[at].left; else at = nodes[at].right;

      }
      res += pr * maxOther;
      printf("%.10lf\n", res);
    }
  }
  return 0;
}