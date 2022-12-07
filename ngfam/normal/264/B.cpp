#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];
int f[N];
int g[N];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }
  int answer = 0;
  for(int i = 1; i <= n; ++i){
    f[i] = 1;
    for(int x = 2; x * x <= a[i]; ++x){
      if(a[i] % x != 0){
        continue;
      }
      f[i] = max(f[i], g[x] + 1);
      f[i] = max(f[i], g[a[i] / x] + 1);
    }
    if(a[i] != 1) f[i] = max(f[i], g[a[i]] + 1);
    for(int x = 2; x * x <= a[i]; ++x){
      if(a[i] % x != 0){
        continue;
      }
      g[x] = max(g[x], f[i]);
      g[a[i] / x] = max(g[a[i] / x] , f[i]);
    }
    if(a[i] != 1) g[a[i]] = max(g[a[i]], f[i]);
    answer = max(answer, f[i]);
  }
  cout << answer;
  return 0;
}