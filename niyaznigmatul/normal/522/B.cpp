#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

using namespace std;

const int N = 1234567;

int w[N], h[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", w + i, h + i);
  }
  h[n] = -1;
  int m1 = n, m2 = n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += w[i];
    if (h[i] > h[m1]) {
      m2 = m1;
      m1 = i;
    } else {
      if (h[i] > h[m2]) { 
        m2 = i;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) printf(" ");
    printf("%d", (sum - w[i]) * (i == m1 ? h[m2] : h[m1]));
  }
  printf("\n");
  return 0;
}