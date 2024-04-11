#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  int p=0,q=0,r=0;
  for(auto &nx : a){
    int np,nq,nr;
    int d1=0,d2=0;
    if(nx&1){d1=1;}
    if(nx&2){d2=1;}
    np=max(p,max(q,r));
    nq=max(p,r)+d1;
    nr=max(p,q)+d2;
    p=np;q=nq;r=nr;
    //cout << p << ' ' << q << ' ' << r << '\n';
  }
  cout << n-max(p,max(q,r)) << '\n';
  return 0;
}