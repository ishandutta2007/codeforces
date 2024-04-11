#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  sort(a.begin(),a.end());
  int t=-1,res=2e9;
  for(int ct=1;ct<=100;ct++){
    int cres=0;
    for(auto &nx : a){
      cres+=min({abs(nx-ct),abs(nx-ct-1),abs(nx-ct+1)});
    }
    if(cres<res){
      res=cres;
      t=ct;
    }
  }

  cout << t << ' ' << res << '\n';
  return 0;
}