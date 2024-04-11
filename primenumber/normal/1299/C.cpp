#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  vector<double> va(n);
  REP(i,n) {
    int a;
    cin>>a;
    va[i] = a;
  }
  vector<tuple<double,int>> vt;
  REP(i,n) {
    double avg = va[i];
    int w = 1;
    while (!vt.empty()) {
      double bavg;
      int bw;
      tie(bavg, bw) = vt.back();
      if (bavg <= avg) break;
      vt.pop_back();
      double sum = bavg * bw + avg * w;
      w += bw;
      avg = sum / w;
    }
    vt.emplace_back(avg, w);
  }
  for(auto&& t:vt) {
    double avg;
    int w;
    tie(avg, w) = t;
    REP(i,w) {
      printf("%.10f\n", avg);
    }
  }
  return 0;
}