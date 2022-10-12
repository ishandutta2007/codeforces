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
  int sig=0,res=0;
  for(int i=0;i<n;i++){
    if(sig<=a[i]){res++;sig+=a[i];}
  }
  cout << res << '\n';
  return 0;
}