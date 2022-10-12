#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for(auto &nx : a){cin >> nx;}
  sort(a.begin(),a.end());
  if(a[0]==a[n-1]){
    cout << 0 << ' ' << (n*(n-1)/2) << '\n';
    return 0;
  }
  long long mi=0,ma=0;
  for(int i=0;i<n;i++){
    if(a[0]==a[i]){mi++;}
    if(a[n-1]==a[i]){ma++;}
  }
  cout << a[n-1]-a[0] << ' ' << mi*ma << '\n';
  return 0;
}