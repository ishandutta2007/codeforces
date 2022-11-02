#include <bits/stdc++.h>
using namespace std;

int f(const vector<int> &tmp) {
  int res = 0;
  for (int i = 0; i < tmp.size(); i++) {
    int mini = 1000000000;
    for (int j = i; j < tmp.size(); j++) {
      mini = min(mini, tmp[j]);
      res += mini;
    }
  }
  return res;
}

vector <int> now;
int maxi;

int main() {
  int n,m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    now.push_back(i);
  }
  do {
    maxi = max(maxi, f(now));
  } while (next_permutation(now.begin(), now.end()));

  for (int i = 1; i <= n; i++) {
    now[i-1] = i;
  }
  int cnt = 0;
  do {
    if (f(now) == maxi) {
      if (cnt == m - 1) {
        for (int i = 0; i < n; i++) {
          printf("%d ", now[i]);
        }
        printf("\n");
        return 0;
      }
      ++cnt;
    }
  } while (next_permutation(now.begin(), now.end()));
}