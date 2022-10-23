#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    vector<int> rx(8,0);
    for(int i=0;i<8;i++){
      string s;
      cin >> s;
      for(int j=0;j<8;j++){
        if(s[j]=='R'){rx[i]++;}
      }
    }
    string res="B";
    for(auto &nx : rx){if(nx==8){res="R";}}
    cout << res << "\n";
  }
  return 0;
}