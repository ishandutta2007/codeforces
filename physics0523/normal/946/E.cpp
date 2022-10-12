#include<bits/stdc++.h>

using namespace std;

string subt1(string s){
  for(int i=s.size()-1;i>=0;i--){
    if(s[i]!='0'){
      s[i]--;
      for(int j=i+1;j<s.size();j++){s[j]='9';}
      break;
    }
  }
  reverse(s.begin(),s.end());
  while(s.back()=='0'){s.pop_back();}
  reverse(s.begin(),s.end());
  return s;
}

int mask(string &s){
  int res=0;
  for(auto &nx : s){
    res^=(1<<(nx-'0'));
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    s=subt1(s);
    if(s.size()%2){s.pop_back();}
    string io="1";
    while(io.size()<s.size()){io.push_back('0');}
    if(s==io){
      for(int i=2;i<s.size();i++){
        cout << '9';
      }cout << '\n';
      continue;
    }
    string res=s;
    for(int i=0;(!res.empty() && i<20);i++){res.pop_back();}
    while(res.size()<s.size()){
      for(char add='9';add>='0';add--){
        string pre=res,suf;
        pre.push_back(add);
        int cm=mask(pre);
        for(int j=0;j<10;j++){
          if(cm&(1<<j)){suf.push_back('0'+j);}
        }
        if(pre.size()+suf.size()>s.size()){continue;}
        while(pre.size()+suf.size()<s.size()){suf.push_back('0');}
        sort(suf.begin(),suf.end());
        pre+=suf;
        if(pre<=s){
          res.push_back(add);
          break;
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}