#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  REP(cases,t) {
    int n;
    cin>>n;
    vecint a(n);
    for(auto& e:a) cin>>e;
    int m;
    cin>>m;
    vector<tuple<int,int>> vt;
    REP(i,m) {
      int p,s;
      cin>>p>>s;
      vt.emplace_back(p,s);
    }
    sort(begin(vt),end(vt));
    vector<tuple<int,int>> needs;
    for (auto [p,s] : vt) {
      while (!needs.empty()) {
        auto [tp,ts] = needs.back();
        if (ts <= s) {
          needs.pop_back();
        } else {
          break;
        }
      }
      needs.emplace_back(p, s);
    }
    bool ok = false;
    int pos = 0;
    REP(days,n) {
      int mx = 0;
      REP(i,n+1) {
        if (pos + i >= n) {
          ok = true;
          pos = n;
          break;
        }
        mx = max(mx, a[pos + i]);
        auto itr = lower_bound(begin(needs), end(needs), make_tuple(mx, i));
        int len = i+1;
        if (itr == end(needs)) {
          pos += i;
          break;
        } else if (get<1>(*itr) < len) {
          pos += i;
          break;
        }
      }
      if (ok) {
        cout << (days+1) << '\n';
        break;
      }
    }
    if (!ok) {
      cout<<-1<<'\n';
    }
  }
  cout<<flush;
  return 0;
}