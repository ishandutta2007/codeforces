#include <bits/stdc++.h>

using namespace std;

const int N = 1003;

int n;
int a[N][N];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }

  vector < int > ans(n + 1);

  long long g = 1LL * a[1][2] * a[1][3] / a[2][3];
  ans[1] = sqrt(g);
  while(1LL * ans[1] * ans[1] < g) ++ans[1];

  for(int i = 1; i <= n; ++i) {
    if(i == 1) cout << ans[1] << " ";
    else cout << a[1][i] / ans[1] << " ";
  }

  return 0;
}