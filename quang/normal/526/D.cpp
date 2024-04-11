#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

char a[N];
int n, k;
int t[N];

int main() {
  //freopen("D.inp", "r", stdin);
  scanf("%d %d", &n, &k);
  scanf("%s", a + 1);
  int cur = 0;
  t[1] = 0;
  for (int i = 2; i <= n; i++) {
    while (cur && a[i] != a[cur + 1]) {
      cur = t[cur];
    }
    cur += (a[i] == a[cur + 1]);
    t[i] = cur;
  }
  for (int i = 1; i <= n; i++) {
    int len = i - t[i];
    int cnt = i / len;
    int cntg = cnt / k;
    int leng = cntg * len;
    int lenlast = i - leng * k;
    cout << (lenlast <= leng);
  }
  return 0;
}