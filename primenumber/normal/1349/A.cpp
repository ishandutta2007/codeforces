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
  vecint a(n);
  for(auto&&e:a)cin>>e;
  int m = a.back();
  a.pop_back();
  map<int,int> fct;
  for (int i = 2; i*i <= m; ++i) {
    while ((m % i) == 0) {
      ++fct[i];
      m /= i;
    }
  }
  if (m > 1) ++fct[m];
  map<int,int> snd;
  for (auto&&[p,cnt] : fct) {
    snd[p] = 20;
  }
  set<int> erased;
  for(auto&& e:a) {
    for(auto itr = begin(fct); itr != end(fct);) {
      auto&&[p,cnt] = *itr;
      int ec = 0;
      while (e % p == 0) {
        ++ec;
        e /= p;
      }
      if (ec <= cnt) {
        if (cnt == 0) {
          snd.erase(p);
          itr = fct.erase(itr);
          erased.insert(p);
        } else {
          snd[p] = cnt;
          cnt = ec;
          ++itr;
        }
      } else if (ec < snd[p]) {
        snd[p] = ec;
        ++itr;
      } else {
        ++itr;
      }
    }
    if (e > 1) {
      for (int i = 2; i*i <= e; ++i) {
        int cnt = 0;
        while ((e % i) == 0) {
          ++cnt;
          e /= i;
        }
        if (cnt > 0 && erased.count(i) == 0) {
          fct[i] = 0;
          snd[i] = cnt;
        }
      }
      if (e > 1 && erased.count(e) == 0) {
        fct[e] = 0;
        ++snd[e];
      }
    }
  }
  ll ans = 1;
  for (auto&&[p,cnt]:snd) {
    REP(i,cnt) {
      ans *= p;
    }
  }
  cout<<ans<<endl;
  return 0;
}