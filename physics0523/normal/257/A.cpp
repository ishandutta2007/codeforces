#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  if(m<=k){cout << "0\n";return 0;}
  for(int i=0;i<n;i++){
    k--;
    k+=a[i];
    if(m<=k){
      cout << i+1 << '\n';
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}