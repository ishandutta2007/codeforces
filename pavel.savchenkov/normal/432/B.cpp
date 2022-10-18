#include <cstdio>

using namespace std;

const int MAXN = int(1e5) + 10;

int cntx[MAXN];
int cnty[MAXN];
int x[MAXN];
int y[MAXN];
int n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    --x[i];
    --y[i];
    ++cntx[x[i]];
    ++cnty[y[i]];
  }

  for (int i = 0; i < n; ++i) {
    --cntx[x[i]];
    --cnty[y[i]];
   
    int add = cntx[y[i]];
    printf("%d %d\n", (n - 1 + add),  (n - 1 - add));

    ++cntx[x[i]];
    ++cnty[y[i]];
  }
  return 0;
}