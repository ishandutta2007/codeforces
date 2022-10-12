#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    long long res=0;
    vector<long long> a(n);
    for(auto &nx : a){
      cin >> nx;
      res+=nx;
    }
    if(res<n){cout << "1\n";}
    else if(res==n){cout << "0\n";}
    else{cout << res-n << '\n';}
  }
  return 0;
}