#include<bits/stdc++.h>

using namespace std;

void remchar(string &s,char c){
  string t;
  for(auto &nx : s){
    if(nx==c){continue;}
    t.push_back(nx);
  }
  s.swap(t);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    vector<vector<int>> mem(26);
    string s;
    cin >> s;
    int l=s.size();
    int fl=0;
    for(int i=0;i<l;i++){fl|=(1<<(s[i]-'a'));}
    while(fl){
      int cfl=0,lim;
      l=s.size();
      for(int i=l-1;i>=0;i--){
        cfl|=(1<<(s[i]-'a'));
        if(cfl==fl){lim=i;break;}
      }
      int tg=0;
      for(int i=0;i<=lim;i++){
        if(s[tg]<s[i]){tg=i;}
      }
      cout << s[tg];
      char tc=s[tg];
      fl^=(1<<(tc-'a'));
      s.erase(0,tg+1);
      remchar(s,tc);
    }cout << '\n';
  }
  return 0;
}