#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  double x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  x2 -= x1;
  y2 -= y1;
  x1 = 0; y1 = 0;
  double v,t;
  cin>>v>>t;
  double vx,vy,wx,wy;
  cin>>vx>>vy>>wx>>wy;
  double xt = x1 + t*vx;
  double yt = y1 + t*vy;
  double dtx = abs(x2-xt);
  double dty = abs(y2-yt);
  double d = sqrt(dtx*dtx + dty*dty);
  if (d <= t*v) {
    double lo = 0;
    double hi = t;
    REP(i,100) {
      double mid = (hi + lo) / 2;
      double xm = mid * vx;
      double ym = mid * vy;
      double dmx = abs(xm - x2);
      double dmy = abs(ym - y2);
      double dm = sqrt(dmx*dmx + dmy*dmy);
      if (dm / v > mid) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    cout<<fixed<<setprecision(10)<<lo<<endl;
  } else {
    double mnv = v - sqrt(wx*wx + wy*wy);
    double d2x = abs(xt-x2);
    double d2y = abs(yt-y2);
    double mxd = sqrt(d2x*d2x + d2y*d2y);
    double lo = 0;
    double hi = mxd / mnv;
    REP(i,100) {
      double mid = (hi + lo) / 2;
      double xm = x2 - mid * wx;
      double ym = y2 - mid * wy;
      double dmx = abs(xm - xt);
      double dmy = abs(ym - yt);
      double dm = sqrt(dmx*dmx + dmy*dmy);
      if (dm / v > t + mid) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    cout<<fixed<<setprecision(10)<<lo + t<<endl;
  }
  return 0;
}