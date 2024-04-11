#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int const TEN = 10000000;
char BUF[223456789];
char * buf = BUF;

void * operator new(size_t n) {
  void * ret = buf;
  buf += n;
  return ret;
}

void operator delete(void * f) {}

int ans;

int a[123];
long long n, k;

vector<pair<int, int> > w[10][2];
vector<int> small;
vector<pair<int, long long> > first;

void go(int x, int len, int num) {
  if (x == len) {
    w[a[0]][a[0] < a[1]].push_back(make_pair((int) (num % n), num));
    return;
  }
  for (int d = 0; d < 10; d++) {
    if (x > 0 && d == a[x - 1]) continue;
    if (x > 1 && (a[x - 2] < a[x - 1]) != (a[x - 1] > d)) continue;
    a[x] = d;
    go(x + 1, len, num * 10 + d);
  }
}

void go2(int x, int len, int num) {
  if (x > 0 && num % n == 0) {
    small.push_back(num);    
  }
  if (x == len) {
    return;
  }
  for (int d = 0; d < 10; d++) {
    if (x == 0 && d == 0) continue;
    if (x > 0 && d == a[x - 1]) continue;
    if (x > 1 && (a[x - 2] < a[x - 1]) != (a[x - 1] > d)) continue;
    a[x] = d;
    go2(x + 1, len, num * 10 + d);
  }
}

void go3(int x, int len, int num) {
  if (x > 0) first.push_back(make_pair(num, (long long) num * TEN % n));    
  if (x == len) {
    return;
  }
  for (int d = 0; d < 10; d++) {
    if (x == 0 && d == 0) continue;
    if (x > 0 && d == a[x - 1]) continue;
    if (x > 1 && (a[x - 2] < a[x - 1]) != (a[x - 1] > d)) continue;
    a[x] = d;
    go3(x + 1, len, num * 10 + d);
  }
}

int main() {
  scanf("%I64d%I64d", &n, &k);
  go2(0, 7, 0);
  std::sort(small.begin(), small.end());
  if (k <= (int) small.size()) {
    printf("%d\n", small[k - 1]);
    return 0;
  }
  k -= small.size();
  go(0, 7, 0);
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 2; j++) std::sort(w[i][j].begin(), w[i][j].end());
  go3(0, 7, 0);
  std::sort(first.begin(), first.end());
  for (auto p : first) {
    int cn = 0;
    if (p.first > 9) a[cn++] = p.first / 10 % 10;
    a[cn++] = p.first % 10;
    long long need = (n - p.second) % n;
    if (need > TEN) continue;
    for (int d = 0; d < 10; d++) {
      if (cn > 0 && d == a[cn - 1]) continue;
      if (cn > 1 && (a[cn - 2] < a[cn - 1]) != (a[cn - 1] > d)) continue;
      int f = a[cn - 1] > d;
      auto & q = w[d][f];
      auto it1 = lower_bound(q.begin(), q.end(), make_pair((int) need, 0));
      auto it2 = upper_bound(q.begin(), q.end(), make_pair((int) need, 10000000));
      int got = it2 - it1;
      if (got < k) k -= got; else {
        long long ans = (long long) p.first * TEN + ((it1 + (k - 1))->second);
        printf("%I64d\n", ans);
        return 0;
      }
    } 
  }
  puts("-1");
}