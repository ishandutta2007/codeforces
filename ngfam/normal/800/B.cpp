#include <bits/stdc++.h>

using namespace std;

typedef pair<double,double> Point;

const int N = 1010;

int n;
Point a[N];

Point Make(Point u, Point v){
  u.first -= v.first;
  u.second -= v.second;
  return u;
}

double CCW(Point u, Point v){
  return abs(u.first * v.second - u.second * v.first);
}

double Kc(Point u, Point v){
  return sqrt((u.first - v.first) * (u.first - v.first) + (u.second - v.second) * (u.second - v.second));
}

double Dist(Point u, Point v, Point k){
  return CCW(Make(u, v), Make(k, v)) / Kc(v, k);
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i].first >> a[i].second;
  }
  a[++n] = a[1];
  a[++n] = a[2];
  double ans = 0, Low = 0, High = 1e9;
  for(int Bs = 1; Bs <= 60; ++Bs){
    double Val = (Low + High) / 2;
    bool stop = false;
    for(int i = 1; i < n - 1; ++i){
      if(Dist(a[i + 1], a[i], a[i + 2]) / 2 <= Val){
        stop = true;
        break;
      }
    }
    if(stop == true){
      High = Val;
    }
    else{
      Low = Val;
      ans = Val;
    }
  }
  cout << fixed << setprecision(6) << ans;
  return 0;
}