#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n;
double a[N];
double f[N];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen("1.out", "w", stdout);
  #endif // pts
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  double ans = a[n], sum = 1 - a[n];
  for(int i = n - 1; i >= 1; --i){
    double calc = ans * (1 - a[i]) + a[i] * sum;
    if(ans > calc){
      break;
    }
    ans = calc;
    sum *= (1 - a[i]);
  }
  cout << fixed << setprecision(10) << ans;
  return 0;
}