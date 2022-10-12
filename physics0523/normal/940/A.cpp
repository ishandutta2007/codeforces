#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,d;
  cin >> n >> d;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  a.push_back(1e9);
  sort(a.begin(),a.end());
  int res=n-1;
  int l=0,r=0;
  while(l<n){
    if(a[r]-a[l]<=d){
      res=min(n-(r-l+1),res);
      r++;
    }
    else{l++;}
  }
  cout << res << '\n';
  return 0;
}