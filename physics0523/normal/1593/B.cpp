#include<bits/stdc++.h>

using namespace std;

vector<string> suf={"52","05","57","00"};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    int res=100;
    for(auto &tg : suf){
      int pt=0,sig=0;
      for(int i=0;i<s.size();i++){
        if(tg[pt]==s[i]){pt++;}
        else{sig++;}
        if(pt==2){break;}
        if(i==s.size()-1){sig=1000;}
      }
      res=min(res,sig);
    }
    cout << res << '\n';
  }
  return 0;
}