#include<bits/stdc++.h>

using namespace std;

const int MAXN = 3003;

int n, k;
int a[MAXN];
int p[MAXN], q[MAXN];


int f[MAXN][MAXN];
int mp[MAXN];

/// prob gonna WA
/// weird shit problem :waturr:

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> k;
  for(int i = 0; i < n; ++i) cin >> a[i];

  if(n == 1) {
    cout << 1;
    return 0;
  }

  /***
    first it gets to x....xxxxxxx
    then it uses one turn to get -....-xxxxx

    this condition means that a[st] > 0 && p[en] < 100
    this is the case

    fuck you author
  ***/

  p[n - 1] = q[n - 1] = a[n - 1];
  for(int i = n - 2; i >= 0; --i) {
    p[i] = max(p[i + 1], a[i]);
    q[i] = min(q[i + 1], a[i]);
  }

  memset(f, 60, sizeof f);
  f[0][0] = 0;

  for(int i = 0; i < n; ++i) {
    for(int j = i; j < n; ++j) {
      if(i == j) {
        if(p[i + 1] > 0 && a[i] < 100) f[i + 1][i + 1] = min(f[i + 1][i + 1], f[i][i] + 1);
        if(p[i + 1] > 0 && a[i] > 0) f[i + 2][i + 2] = min(f[i + 2][i + 2], f[i][i] + 1);
        if(p[i + 1] < 100 && a[i] > 0) f[i][i + 2] = min(f[i][i + 2], f[i][j] + 1);
      }
      else {
        if(p[j] > 0 && a[i] < 100) f[j][j] = min(f[j][j], f[i][j] + 1);
        if(p[j] > 0 && a[i] > 0) f[j + 1][j + 1] = min(f[j + 1][j + 1], f[i][j] + 1);
        if(p[j] < 100 && a[i] > 0) f[i][j + 1] = min(f[i][j + 1], f[i][j] + 1);
      }
    }
  }

  /// seriously tf
  int answer = 0, add = 0;
  for(int st = 0; st < n; ++st) {
    answer += (f[st][st] <= k);
    for(int en = st + 2; en < n + 1; ++en) {
      if(f[st][en] <= k) answer++;
      if(en == n - 1 && a[en] > 0 && a[st] > 0 && f[st][en] + 1 <= k) {
        add = 1;
      }
    }
  }

  /// kill your coordinator as well

  if(f[n - 2][n - 2] + 1 <= k && a[n - 2] > 0 && a[n - 1] > 0) add = 1;

  cout << answer + add << endl;

  /// can not pass that many tests with the wrong observation can it

  return 0;
}