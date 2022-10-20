#include <bits/stdc++.h>

using namespace std;

const int N = 2000;

int n;

int cnt[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int u;
    scanf("%d", &u);
    cnt[u]++;
  }
  for (int i = 1; i <= 1000; i++) {
    if (cnt[i] && cnt[i + 1] && cnt[i + 2]) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}