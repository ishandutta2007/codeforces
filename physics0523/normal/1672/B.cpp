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
    int l=s.size();
    if(s[l-1]=='A'){cout << "NO\n";continue;}
    int h=0;
    bool fl=true;
    for(auto &nx : s){
      if(nx=='A'){h++;}else{h--;}
      if(h<0){fl=false;break;}
    }
    if(fl){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}