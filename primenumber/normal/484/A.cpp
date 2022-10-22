#include <bits/stdc++.h>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define EACH(i,x)   for(auto & i : x)
#define ALL(x)      begin(x),end(x)

using namespace std;

typedef vector<int> vecint;

int l2(int64_t x) {
  return x ? (l2(x/2)+1) : 0;
}

int64_t flb(int64_t x, int64_t n) {
  REP(i,n) {
    x |= INT64_C(1) << i;
  }
  return x;
}

int main()
{
  int n;
  cin>>n;
  REP(cnt,n) {
    int64_t l,r;
    cin>>l>>r;
    ++r;
    if (l2(l) != l2(r)) {
      cout<<flb(0,l2(r)-1)<<endl;
    }else {
      int m=l2(l);
      REP(i,m) {
        int v=m-i-1;
        if(((l>>v)&1) == ((r>>v)&1)) continue;
        cout << flb(l,v) << endl;
        break;
      }
    }
  }
  return 0;
}