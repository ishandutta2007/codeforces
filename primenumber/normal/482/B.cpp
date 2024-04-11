#include <bits/stdc++.h>

#define REP(i,n)  for(int i=0;i<(int)(n);++i)

using namespace std;

typedef vector<int> vecint;

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vecint> sbo(30,vecint(n+1,0));
  vector<tuple<int,int,int>> lms;
  REP(i,m) {
    int l,r,q;
    cin>>l>>r>>q;
    --l;
    lms.emplace_back(l,r,q);
    REP(j,30) {
      if ((q>>j)&1) {
        sbo[j][l]++;
        sbo[j][r]--;
      }
    }
  }
  REP(i,30) {
    REP(j,n) {
      sbo[i][j+1] += sbo[i][j];
    }
  }
  vector<vecint> bts(30,vecint(n,0));
  vector<vecint> bsm(30,vecint(n+1,0));
  REP(i,30) {
    REP(j,n) {
      if(sbo[i][j] > 0) bts[i][j] = 1;
    }
  }
  REP(i,30) {
    partial_sum(begin(bts[i]),end(bts[i]),begin(bsm[i])+1);
  }
  bool ok = true;
  REP(i,m) {
    int l,r,q;
    tie(l,r,q) = lms[i];
    REP(j,30) {
      if (((q>>j)&1) == 0) {
        if (bsm[j][r] - bsm[j][l] == r - l) {
          ok = false;
        }
      }
    }
  }
  if (!ok) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    REP(i,n) {
      if (i) cout << ' ';
      int v = 0;
      REP(j,30) {
        v += bts[j][i] << j;
      }
      cout << v;
    }
    cout << endl;
  }
  return 0;
}