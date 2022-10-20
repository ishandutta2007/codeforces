#include <bits/stdc++.h>
#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 1010;

int n, m, res;
int xoa[N], tr[N];
string s[N];

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> s[i];
  for(int i = 1; i <= n; i++) tr[i] = 0;
  for(int i = 0; i < m; i++) {
    int flag = 0;
    for(int j = 2; j <= n; j++)
    if(s[j][i] < s[j - 1][i] && tr[j] == 0) {
      flag = 1;
      break;
    }
    if(flag) res++;
    else {
      for(int j = 2; j <= n; j++)
        if(s[j][i] > s[j - 1][i]) tr[j] = 1;
    }
  }
  cout << res;
  return 0;
}