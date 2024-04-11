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
  int n;
  cin>>n;
  vecint c(n);
  REP(i,n) cin>>c[i];
  constexpr int INF = 1e8;
  vector made(n+1, vecint(n, INF));
  REP(i,n) {
    made[1][i] = 1;
    if (i < n-1 && c[i] == c[i+1]) {
      made[2][i] = 1;
    }
  }
  FOR(len,2,n+1){
    REP(i,n) {
      if (i+len > n) break;
      if (c[i] == c[i+len-1]) {
        made[len][i] = min(made[len][i], made[len-2][i+1]);
      }
      FOR(k,1,len) {
        int left = made[k][i];
        int right = made[len-k][i+k];
        made[len][i] = min(made[len][i], left + right);
      }
    }
  }
  cout<<made[n][0]<<endl;
  return 0;
}