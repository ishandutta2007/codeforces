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
    string pat;
    int fl=0;
    for(int i=0;i<s.size();i++){
      if(fl&(1<<(s[i]-'a'))){break;}
      fl|=(1<<(s[i]-'a'));
      pat.push_back(s[i]);
    }
    while(pat.size()<s.size()){pat=pat+pat;}
    bool isok=true;
    for(int i=0;i<s.size();i++){
      if(s[i]!=pat[i]){isok=false;break;}
    }
    if(isok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}