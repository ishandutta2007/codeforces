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
  for(auto&& e:a)cin>>e;
  vecint rna(n);
  rna[0] = 0xFFFFFFFF;
  REP(i,n-1) {
    int j = n-1-i;
    rna[i+1] = rna[i] & ~a[j];
  }
  int fna = 0xFFFFFFFF;
  int mx = 0;
  int mxi = 0;
  REP(i,n) {
    int j = n-(i+1);
    int val = fna & a[i] & rna[j];
    if (val > mx) {
      mx = val;
      mxi = i;
    }
    fna &= ~a[i];
  }
  cout<<a[mxi];
  REP(i,n) {
    if (i == mxi) continue;
    cout<<' '<<a[i];
  }
  cout<<endl;
  return 0;
}