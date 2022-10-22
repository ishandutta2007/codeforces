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
  int t;
  cin>>t;
  while(t--) {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int old = -1e8;
    vecint spans;
    int score = 0;
    REP(i,n) {
      if (s[i] == 'W') {
        score += 1;
        if (i > 0 && s[i-1] == 'W') score += 1;
      }
    }
    REP(i,n-1) {
      if (s[i] == 'L' && s[i+1] == 'W') {
        if (old >= 0) spans.push_back(i - old);
      } else if (s[i] == 'W' && s[i+1] == 'L') {
        old = i;
      }
    }
    int fst = n;
    REP(i,n) {
      if (s[i] == 'W') fst = min(fst, i);
    }
    int lst = (old >= 0 && s.back() == 'L') ? (n - 1 - old) : 0;
    int rem = fst + lst;
    sort(ALL(spans));
    for (auto&& len : spans) {
      if (len <= k) {
        k -= len;
        score += 2 * len + 1;
      } else {
        score += 2 * k;
        k = 0;
      }
    }
    if (score > 0) {
      score += 2 * min(k, rem);
    } else if (min(k, rem) > 0){
      score += 2 * min(k, rem) - 1;
    }
    cout<<score<<"\n";
  }
  return 0;
}