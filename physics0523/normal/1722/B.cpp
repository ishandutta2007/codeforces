#include<bits/stdc++.h>

using namespace std;

void cvrt(string &s){
  for(auto &nx : s){
    if(nx=='G'){nx='B';}
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l;
    cin >> l;
    string s1;
    string s2;
    cin >> s1 >> s2;
    cvrt(s1);
    cvrt(s2);
    if(s1==s2){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}