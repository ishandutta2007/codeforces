#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
bool turn[N];

int ask(vector<int> v) {
  printf("%d", (int) v.size());
  for (int u: v) printf(" %d", u+1);
  printf("\n");

  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  if (ret == -1) exit(0);
  return ret - 1;
}

void asktoggle(vector<int> v) {
  for (int u: v) turn[u] = true;
  int x = ask(v);
  for (int i = x; i < x + v.size(); ++i) {
    turn[i % n] = false;
  }
}

void done() {
  printf("0\n");
  fflush(stdout);
  exit(0);
}

int solve() {
  scanf("%d", &n);
  if (n <= 3) {
    done();
    return 0;
  }

  int opt = 1, maxi = 0;
  for (int k = 2; k <= n; ++k) {
    int on = n - (n+k-1)/k - (k-1);
    if (on > maxi) {
      opt = k;
      maxi = on;
    }
  }

  for (int i = 0; i < maxi; ++i) {
    vector<int> v;
    for (int j = 0; j < n; ++j) {
      if (j % opt == 0) continue;
      if (turn[j]) continue;
      v.push_back(j);
      if (v.size() == opt) break;
    }
    asktoggle(v);
  }

  done();
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}