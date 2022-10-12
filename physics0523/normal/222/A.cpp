#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  k--;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  for(int i=n;i<3*n;i++){
    a.push_back(a[i-n+k]);
  }
  map<int,int> mp;
  for(int i=0;i<n;i++){mp[a[i]]++;}
  for(int i=0;i<2*n;i++){
    if(mp[a[i]]==n){
      cout << i << '\n';
      return 0;
    }
    mp[a[i]]--;
    mp[a[i+n]]++;
  }
  cout << "-1\n";
  return 0;
}