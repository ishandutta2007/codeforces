#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (k > n) {
    puts("-1");
    return 0;
  }
  if (n == 1) {
    puts("a");
    return 0;
  }
  if (k == 1) {
    puts("-1");
    return 0;
  }
  int m = n - (k - 2);
  for (int i = 0; i < m; i++) putchar('a' + i % 2);
  for (int i = 2; i < k; i++) {
    putchar('a' + i);
  }
  puts("");
}