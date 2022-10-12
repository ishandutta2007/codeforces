#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    char mx='a';
    for(auto &nx : s){mx=max(mx,nx);}
    for(char i=mx;i>='a';i--){
      if(s.empty()){
        s="err";break;
      }
      string t;
      if(s[0]==i){
        for(int j=1;j<s.size();j++){t.push_back(s[j]);}
        s=t;
      }
      else if(s.back()==i){
        s.pop_back();
      }
      else{break;}
    }
    if(s.empty()){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}