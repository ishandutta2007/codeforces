#include<bits/stdc++.h>

using namespace std;

int main(){
  string s,res;
  cin >> s;
  int l=s.size(),n=0;
  for(int i=0;i<l;i++){
    if(n!=0){
      if(res[n-1]==s[i]){
        res.erase(n-1,1);n--;
      }
      else{res.push_back(s[i]);n++;}
    }
    else{res.push_back(s[i]);n++;}
  }
  cout << res << '\n';
  return 0;
}