#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

const int MAXN = 300 + 10;

int n, m, k;

int main() {
  scanf("%d%d%d", &n, &m, &k);

  int num = 0;
  int pos = 0;
  for (int i = 0; i < n; ++i) {
    if  (i & 1) {
      for (int j = m - 1; j >= 0; --j) {
        int len = n * m / k;
        if  (num == k - 1) {
          len += (n * m) % k;
        }
         
        if  (pos == 0) {
          printf("%d ", len);
        }
        printf("%d %d ", i + 1, j + 1);

        ++pos;
        if  (pos == len) {
          puts("");
          ++num;
          pos = 0;
        }
      }
    } else {
      for (int j = 0; j < m; ++j) {
        int len = n * m / k;
        if  (num == k - 1) {
          len += (n * m) % k;
        }
         
        if  (pos == 0) {
          printf("%d ", len);
        }
        printf("%d %d ", i + 1, j + 1);

        ++pos;
        if  (pos == len) {
          puts("");
          ++num;
          pos = 0;
        }
      }
    }
  }

  return 0;
}