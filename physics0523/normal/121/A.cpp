#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<long long> a;
  for(int dg=1;dg<=10;dg++){
    for(int i=0;i<(1<<dg);i++){
      long long v=0;
      for(int j=0;j<dg;j++){
        v*=10;
        if(i&(1<<j)){v+=7;}
        else{v+=4;}
      }
      a.push_back(v);
    }
  }
  a.push_back(0);
  sort(a.begin(),a.end());
  long long l,r,res=0;
  cin >> l >> r;
  for(int i=1;i<a.size();i++){
    long long cl=max(l,a[i-1]+1);
    long long cr=min(r,a[i]);
    // cout << cl << ' ' << cr << '\n';
    if(cl<=cr){
      // cout << cl << ' ' << cr << ' ' << a[i] << '\n';
      res+=(cr-cl+1)*a[i];
    }
  }
  cout << res << '\n';
  return 0;
}