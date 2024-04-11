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
    if(s.size()==2){cout << s[1] << '\n';continue;}
    char res='9';
    for(auto &nx : s){res=min(res,nx);}
    cout << res << '\n';
  }
  return 0;
}