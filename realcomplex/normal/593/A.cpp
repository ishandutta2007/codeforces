#include <bits/stdc++.h>

using namespace std;

bool has(char a,char b,string s){
  for(auto x : s)if(x!=a&&x!=b)return false;
  return true;
}

int main(){
  int n;
  cin >> n;
  string k[n];
  for(int i = 0;i<n;i++){
    cin >> k[i];
  }
  int ans = 0;
  int cur;
  for(char x = 'a';x<='z';x++){
    for(char y = x+1;y<='z';y++){
      cur=0;
      for(int i = 0;i<n;i++){
        if(has(x,y,k[i]))cur+=k[i].size();
      }
      ans=max(ans,cur);
    }
  }
  cout << ans;
  return 0;
}