#include<bits/stdc++.h>

using namespace std;

int sum(char a,char b){
  return (a-'0')+(b-'0');
}

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
    string res;
    res.push_back('1');
    for(int i=1;i<l;i++){
      if(sum(s[i-1],res[i-1])==sum(s[i],'1')){res.push_back('0');}
      else{res.push_back('1');}
    }
    cout << res << '\n';
  }
  return 0;
}