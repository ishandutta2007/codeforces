#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l;
    string s;
    cin >> l >> s;
    decltype(s)::iterator result = std::unique(s.begin(),s.end());
    s.erase(result,s.end());
    sort(s.begin(),s.end());
    bool fl=true;
    for(int i=1;i<s.size();i++){
      if(s[i-1]==s[i]){fl=false;}
    }
    if(fl){cout << "YES\n";}else{cout << "NO\n";}
  }
  return 0;
}