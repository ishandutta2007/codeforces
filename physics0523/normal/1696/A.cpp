#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,z;
    cin >> n >> z;
    vector<long long> a(n);
    long long res=0;
    for(auto &nx : a){
      cin >> nx;
      res=max(res,(nx|z));
    }
    cout << res << '\n';
  }
  return 0;
}