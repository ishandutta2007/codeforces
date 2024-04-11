#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

const int MAXN = 3000 + 10;

int a[MAXN];
int b[MAXN];

int main() {
  int n, v;
  scanf("%d%d", &n, &v);

  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
  }

  int res = 0;
  for (int i = 0; i < MAXN; ++i) {
    int can = v;

    for (int j = 0; j < n; ++j) {
        if  (a[j] == i - 1) {
            int cur = min(can, b[j]);
            can -= cur;
            b[j] -= cur;
        }
    }

    for (int j = 0; j < n; ++j) {
        if  (a[j] == i) {
            int cur = min(can, b[j]);
            can -= cur;
            b[j] -= cur;
        }
    }

    res += v - can;
  }

  printf("%d\n", res);
  return 0;
}