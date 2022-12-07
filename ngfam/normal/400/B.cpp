#include <bits/stdc++.h>

using namespace std;

const int N = 1111;

int n, m, ok[N], ans;
char arr[N][N];

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen("1.out", "w", stdout);
  #endif // ONLINE_JUDGE
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%s", arr[i] + 1);
    int dwarf, candy;
    for(int j = 1; j <= m; ++j){
      if(arr[i][j] == 'G'){
        dwarf = j;
      }
      if(arr[i][j] == 'S'){
        candy = j;
      }
    }
    if(candy < dwarf){
      puts("-1");
      return 0;
    }
    ans += (!ok[candy - dwarf]);
    ok[candy - dwarf] = 1;
  }
  cout << ans;
  return 0;
}