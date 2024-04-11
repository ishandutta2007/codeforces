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

const int N = 123456;
const int MAX = 123456;

int a[N], user[N];
bool real_end[N];

int main() {
  int n, m, t;
  scanf("%d %d %d", &n, &m, &t);
  for (int i = 0; i < n; i++) {
    int hh, mm, ss;
    scanf("%d:%d:%d", &hh, &mm, &ss);
    a[i] = hh * 60 * 60 + mm * 60 + ss;
    real_end[i] = true;
  }
  int users = 0;
  int balance = 0, mx = 0;
  int pbeg = 0, pend = 0;
  for (int q = 0; ; q++) {
    while (pbeg < n && a[pbeg] == q) {
      if (balance < m) {
        balance++;
        if (balance > mx) mx = balance;
        user[pbeg] = ++users;
      } else {
        user[pbeg] = users;
        real_end[pbeg - 1] = false;
      }
      pbeg++;
    }
    while (pend < n && a[pend] + t - 1 == q) {
      if (real_end[pend]) {
        balance--;
      }
      pend++;
    }
    if (pbeg == n && pend == n) {
      break;
    }
  }
  if (mx != m) {
    puts("No solution");
    return 0;
  }
  printf("%d\n", users);
  for (int i = 0; i < n; i++) {
    printf("%d\n", user[i]);
  }
  return 0;
}