#include <cstdio>


char a[50001];

int main() {
  int c = getchar();
  while (c <= 32) c = getchar();
  int n = 0;
  while (c > 32) {
    a[n++] = c;
    c = getchar();
  }
  for (int len = 1; 2 * len <= n; len++) {
      int cur = len;
    int cn = 0;    
    int j = len;
/*    while (j < 2 * len) cn += a[j] != a[j - len], j++;
    while (j < n && cn != 0) {
      char x = a[j];
      char y = a[j - len];
      char z = a[j - len - len];
      cn += (x != y) - (y != z); 
      ++j;
    }
    if (cn != 0) {
      continue;
    }
    int cur = j - len;
  //    printf("%d %d %d\n", len, cur, j);
  */
    while (n - j >= len) {
      int z = cur - len;
      int k = j;
      int end = k + len;
      while (k < end && a[z] == a[k]) {
        ++z;
        ++k;
      }
      if (k == end) {
        j = end;
        continue;
      }
      while (j <= k) {
        a[cur++] = a[j++];
      }
    }
    while (j < n) {
      a[cur++] = a[j++];
    }
    n = cur;
  }
  for (int i = 0; i < n; i++) putchar(a[i]);
  puts("");
}