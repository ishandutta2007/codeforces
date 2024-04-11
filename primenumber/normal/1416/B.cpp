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
  REP(cnum,t) {
    int n;
    cin>>n;
    vecint a(n);
    REP(i,n) cin>>a[i];
    int sum = 0;
    REP(i,n) sum += a[i];
    if (sum % n != 0) {
      cout<<-1<<"\n";
      continue;
    }
    cout << 3*n - 3 << "\n";
    FOR(i,1,n) {
      int idx = i+1;
      int rem = a[i] % idx;
      int need = (idx - rem) % idx;
      cout << 1 << " " << idx << " " << need << "\n";
      a[i] += need;
      a[0] -= need;
      int x = a[i] / idx;
      cout << (i+1) << " " << 1 << " " << x << "\n";
      a[0] += x * idx;
      a[i] -= x * idx;
    }
    int coeff = sum / n;
    FOR(i,1,n) {
      int idx = i+1;
      cout << 1 << " " << idx << " " << coeff << "\n";
    }
  }
  return 0;
}