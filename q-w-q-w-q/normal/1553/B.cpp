#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int t, n, m;
char a[505], b[1001];
int main() {
  cin >> t;
  while (t--) {
    scanf("%s%s", a + 1, b + 1), n = strlen(a + 1), m = strlen(b + 1);
    bool ok = 0;
    for (int i = 1; i <= n && !ok; i++) {
      int cnt = 1;
      for (int j = i; j <= n && !ok; j++, cnt++) {
        if (b[cnt] != a[j]) break;
        if (cnt == m) ok = 1;
        int tp = cnt;
        if (m - tp > j - 1) continue;
        int k = j;
        while (tp < m) {
          tp++, k--;
          if (a[k] != b[tp]) break;
          if (tp == m) ok = 1;
        }
      }
    }
    puts(ok ? "YES" : "NO");
  }
}