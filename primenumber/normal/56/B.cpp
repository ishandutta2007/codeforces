#include <bits/stdc++.h>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)

using namespace std;

typedef vector<int> vecint;

int main()
{
  int n;
  cin>>n;
  vector<int> a(n);
  REP(i,n) cin>>a[i];
  int l = n-1;
  int r = 0;
  REP(i,n) {
    if (a[i] != i+1) {
      l = min(l, i);
      r = max(r, i);
    }
  }
  bool ok = true;
  for(int i=l; i<= r; ++i) {
    if (a[i] != l+1 + (r-i)) {
      ok = false;
    }
  }
  if (ok && l<r) {
    cout << (l+1) << ' ' << (r+1) << endl;
  } else {
    cout << "0 0" << endl;
  }
  return 0;
}