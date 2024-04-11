#include <bits/stdc++.h>

using namespace std;

const int N = 1100;

int n;
char a[N];
int cnt[30];

int main() {
  scanf("%d", &n);
  scanf("%s", a);
  for (int i = 0; i < n; i++) {
    if (a[i] >= 'a')
    cnt[a[i] - 'a'] = 1;
    else {
      cnt[a[i] - 'A'] = 1;
    }
  }
  for (int i = 0; i < 26; i++) {
    if (!cnt[i]) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
}