#include <bits/stdc++.h>
using namespace std;

typedef long long int LLI;

const LLI INF  = 1e16;

LLI f, T, t0;
LLI as[2];
LLI ts[2];
LLI ps[2];

LLI Calc() {
  LLI ans = INF;
  LLI C = t0*f-T;
  LLI lim = f/as[0ll] + (f%as[0ll] != 0ll);
  LLI k = as[0ll]*(ts[0ll]-t0);
  LLI h = as[1LL]*(t0-ts[1LL]);
  for (LLI x=0ll; x<=lim; x++, C+=k) {
    if (h > 0ll) {
      LLI y = C/h + (C%h != 0ll);
      if (C < 0ll) y = 0ll;
      y = max(0LL, y);
      //printf("h C -k*x-h*y: %lld %lld %lld %lld\n", h, C, x, y);
      if (as[0ll]*ts[0ll]*x+as[1LL]*ts[1LL]*y > T) {
        LLI asd = as[0ll]*x;
        LLI dfg = as[1LL]*y;
            //printf("%lld %lld\n", asd*ts[0ll], (f-asd)*ts[1LL]);
            //printf("%lld %lld\n", dfg*ts[1LL], (f-dfg)*ts[0ll]);
        if (asd*ts[0ll] + max(0LL, (f-asd))*ts[1LL] > T) {
          if (dfg*ts[1LL] + max(0LL, (f-dfg))*ts[0ll] > T) {
            continue;
          }
        }
      }
      ans = min(ans, ps[0ll]*x+ps[1LL]*y);
    } else if (h < 0ll) {
      LLI y = -C/-h;
      if (C > 0) continue;
      if (y < 0) continue;
      y = 0;
      ////printf("h C: %lld %lld %lld %lld\n", h, C, x, y);
      if (as[0ll]*ts[0ll]*x > T) {
        LLI asd = as[0ll]*x;
        LLI dfg = as[1LL]*y;
        if (asd*ts[0ll] + max(0LL, (f-asd))*ts[1LL] > T) {
          if (dfg*ts[1LL] + max(0LL, (f-dfg))*ts[0ll] > T) {
            continue;
          }
        }
      }
      ans = min(ans, ps[0ll]*x);
    } else {
      LLI y = 0;
      if (as[0ll]*ts[0ll]*x > T) {
        LLI asd = as[0ll]*x;
        LLI dfg = as[1LL]*y;
        if (asd*ts[0ll] + max(0LL, (f-asd))*ts[1LL] > T) {
          if (dfg*ts[1LL] + max(0LL, (f-dfg))*ts[0ll] > T) {
            continue;
          }
        }
      }
      if (C <= 0ll) ans = min(ans, ps[0ll]*x);
    }
  }
  return ans;
}


int main() {
  scanf("%lld%lld%lld", &f, &T, &t0);
  for (int i=0; i<2; i++) {
    scanf("%lld%lld%lld", &as[i], &ts[i], &ps[i]);
  }

  LLI ans = Calc();
  swap(as[0], as[1]);
  swap(ts[0], ts[1]);
  swap(ps[0], ps[1]);
  ans = min(Calc(), ans);
  
  if (ans == INF) puts("-1");
  else printf("%lld\n", ans);
}