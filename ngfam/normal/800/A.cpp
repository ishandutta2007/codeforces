#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, p;
int a[N];
int b[N];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d%d", &n, &p);
  long long sum = 0;
  for(int i = 1; i <= n; ++i){
    scanf("%d%d", a + i, b + i);
    sum += a[i];
  }
  if(p >= sum){
    puts("-1");
    return 0;
  }
  double Low = 0, High = 1e10, ans = 0;
  for(int Bs = 1; Bs <= 60; ++Bs){
    double Val = (Low + High) / 2;
    double Total = 0;
    for(int i = 1; i <= n; ++i){
      Total += max(0.0, double(a[i]) * Val - b[i]);
    }
    if(Total / double(p) <= Val){
      ans = Val;
      Low = Val;
    }
    else{
      High = Val;
    }
  }
  cout << fixed << setprecision(6) << ans;
  return 0;
}