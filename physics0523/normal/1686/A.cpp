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
    vector<int> a(n);
    int sig=0;
    for(auto &nx : a){
      cin >> nx;
      sig+=nx;
    }
    bool fl=false;
    for(auto &nx : a){
      if(nx*(n-1)==sig-nx){fl=true;}
    }
    if(fl){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}