#include <bits/stdc++.h>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)

using namespace std;

typedef vector<int> vecint;

int main()
{
  int n;
  cin>>n;
  vecint v(n);
  REP(i,n) cin>>v[i];
  int mxr = n-1;
  REP(i,n-1) if(v[i] > v[i+1]){
    mxr = i;
    break;
  }
  if(mxr == n-1) {
    cout << 0 << endl;
    return 0;
  }
  int mxd = 0;
  REP(i,n-1) if(v[n-i-1] < v[n-i-2]) {
    mxd = n-i-1;
    break;
  }
  //cout<<mxr<<' '<<mxd<<endl;
  if (mxr+1 == mxd && v.front() >= v.back())
    cout << n-mxd << endl;
  else
    cout << -1 << endl;
  return 0;
}