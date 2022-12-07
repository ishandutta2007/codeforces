#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const long long mod = 1e9 + 7;

int n, m;
char a[N];
char b[N];
int cnt[N];
long long x[N];
long long y[N];
long long pw[N];

long long ask(long long *arr, int l, int r){
  return (arr[r] - arr[l - 1] * pw[r - l + 1] + mod * mod) % mod;
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%s%s", a + 1, b + 1);
  n = strlen(a + 1);
  m = strlen(b + 1);
  for(int i = 1; i <= n; ++i){
    x[i] = (x[i - 1] * 31 + a[i] - 'a') % mod;
  }
  for(int i = 1; i <= m; ++i){
    y[i] = (y[i - 1] * 31 + b[i] - 'a') % mod;
  }
  pw[0] = 1;
  for(int i = 1; i <= max(m, n); ++i){
    pw[i] = (pw[i - 1] * 31) % mod;
  }
  int answer = 0;
  for(int i = 1; i < N; ++i){
    if(n % i == 0 && m % i == 0){
      //cerr << i << endl;
      if(ask(x, 1, n - i) != ask(x, i + 1, n) && i != n){
        continue;
      }
      if(ask(y, 1, m - i) != ask(y, i + 1, m) && i != m){
        continue;
      }
      if(ask(x, 1, i) != ask(y, 1, i)){
        continue;
      }
      ++answer;
    }
  }
  cout << answer;
  return 0;
}