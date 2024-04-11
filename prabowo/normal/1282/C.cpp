#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, T, a, b;
int diff[N];
pair<int, int> prob[N];

void solve() {
  scanf("%d %d %d %d", &n, &T, &a, &b);

  int allA = 0, allB = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &diff[i]);
    if (diff[i]) ++allB;
    else ++allA;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &prob[i].first);
    prob[i].second = i;
  }

  if (1LL * allA * a + 1LL * allB * b <= T) {
    printf("%d\n", n);
    return;
  }

  sort(prob, prob + n);

  int ans = 0;
  int mustA = 0, mustB = 0;
  for (int i = 0; i < n;) {
    int dead = prob[i].first;

    long long taken = 1LL * mustA * a + 1LL * mustB * b;
    if (taken < dead) {
      int tmp = mustA + mustB;
      int left = dead - taken - 1;
      
      int moreA = min(left / a, allA - mustA);
      tmp += moreA;
      left -= moreA * a;

      int moreB = min(left / b, allB - mustB);
      tmp += moreB;
      left -= moreB * b;

      ans = max(ans, tmp);
    }

    int j = i;
    while (j < n && prob[j].first == dead) {
      if (diff[prob[j].second]) ++mustB;
      else ++mustA;
      ++j;
    }
    i = j;
  }

  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}