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
    string s;
    vector<int> b(32,0);
    for(int i=0;i<n;i++){
      cin >> s;
      for(auto &nx : s){b[nx-'a']++;}
    }
    bool iserr=false;
    for(auto &nx : b){
      if(nx%n){iserr=true;}
    }
    if(iserr){cout << "NO\n";}else{cout << "YES\n";}
  }
  return 0;
}