#include <bits/stdc++.h>

using namespace std;

long long x, y;
long long f[66][2][2][2][2];
int ok[66][2][2][2][2];

long long calc(int i, int la, int ga, int lb, int gb){
  if(i == -1){
    return 0;
  }
  if(ok[i][la][ga][lb][gb] == 1){
    return f[i][la][ga][lb][gb];
  }
  ok[i][la][ga][lb][gb] = 1;
  int fa = 0, ta = 1, fb = 0, tb = 1;
  int bitx = (x >> i) & 1;
  int bity = (y >> i) & 1;
  if(la == 1){
    fa = bitx;
  }
  if(ga == 1){
    ta = bity;
  }
  if(lb == 1){
    fb = bitx;
  }
  if(gb == 1){
    tb = bity;
  }
  long long answer = 0;
  for(int ca = fa; ca <= ta; ++ca){
    for(int cb = fb; cb <= tb; ++cb){
      long long solve = (ca ^ cb) * (1LL << i) + calc(i - 1, la && (ca == fa), ga && (ca == ta), lb && (cb == fb), gb && (cb == tb));
      answer = max(answer, solve);
    }
  }
  return f[i][la][ga][lb][gb] = answer;
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  cin >> x >> y;
  cout << calc(63, 1, 1, 1, 1);
  return 0;
}