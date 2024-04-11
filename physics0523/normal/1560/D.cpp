#include<bits/stdc++.h>

using namespace std;

int f(string s,string t){
  int sp=0,tp=0,res=0;
  while(sp<s.size() && tp<t.size()){
    if(s[sp]==t[tp]){sp++;tp++;}
    else{res++;sp++;}
  }
  res+=(s.size()-sp);
  res+=(t.size()-tp);
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
    int res=114514;
    for(int i=0;i<=62;i++){
      res=min(f(s,to_string((1ll<<i))),res);
    }
    cout << res << '\n';
  }
  return 0;
}