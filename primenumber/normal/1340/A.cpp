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
  int t;
  cin>>t;
  REP(casen,t) {
    int n;
    cin>>n;
    vecint a(n);
    REP(i,n) cin>>a[i];
    vecint b(n);
    REP(i,n) {
      b[a[i]-1] = i;
    }
    vecint hist(n+1, 1);
    hist[n] = 0;
    priority_queue<pair<int,int>> q;
    REP(i,n) q.emplace(1, i);
    bool ok = true;
    set<int> rem;
    REP(i,n+1) rem.insert(i);
    REP(i,n) {
      while (true) {
        auto [x,y] = q.top();
        if (rem.count(y) != 0) break;
        q.pop();
      }
      int want = b[i];
      //cerr<<want<<" "<<hist[want]<<" "<<q.top().first<<" ";
      if (hist[want] != q.top().first) ok = false;
      int nx = *rem.upper_bound(want);
      //cerr<<nx<<endl;
      hist[nx] += hist[want];
      if (nx < n) {
        q.emplace(hist[nx], nx);
      }
      hist[want] = 0;
      rem.erase(want);
    }
    if (ok) {
      cout<<"Yes\n";
    } else {
      cout<<"No\n";
    }
  }
  return 0;
}