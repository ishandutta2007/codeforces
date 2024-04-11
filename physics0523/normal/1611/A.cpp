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
    if((s[s.size()-1]-'0')%2==0){cout << "0\n";continue;}
    if((s[0]-'0')%2==0){cout << "1\n";continue;}
    bool ex=false;
    for(auto &nx : s){
      if((nx-'0')%2==0){ex=true;}
    }
    if(ex){cout << "2\n";}else{cout << "-1\n";}
  }
  return 0;
}