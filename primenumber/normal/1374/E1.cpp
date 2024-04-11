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
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  vecint both, alice, bob;
  REP(i,n) {
    int t,a,b;
    cin>>t>>a>>b;
    if (a&&b) {
      both.push_back(t);
    } else if (a) {
      alice.push_back(t);
    } else if (b) {
      bob.push_back(t);
    }
  }
  sort(ALL(alice));
  sort(ALL(bob));
  int m = min(size(alice), size(bob));
  REP(i,m) {
    both.push_back(alice[i] + bob[i]);
  }
  sort(ALL(both));
  if (size(both) < k) {
    cout<<-1<<endl;
  } else {
    int sum = 0;
    REP(i,k) sum += both[i];
    cout<<sum<<endl;
  }
  return 0;
}