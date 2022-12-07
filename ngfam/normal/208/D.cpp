#include <bits/stdc++.h>

using namespace std;

const int N = 111;

int n;
int a[N];
long long x[N];
long long ans[N];

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // ONLINE_JUDGE
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }
  for(int i = 1; i <= 5; ++i){
    scanf("%lld", x + i);
  }
  long long current = 0;
  for(int i = 1; i <= n; ++i){
    current += a[i];
    for(int j = 5; j >= 1; --j){
      ans[j] += current / x[j];
      current %= x[j];
    }
  }
  for(int i = 1; i <= 5; ++i){
    cout << ans[i] << " ";
  }
  cout << endl;
  cout << current;
  return 0;
}