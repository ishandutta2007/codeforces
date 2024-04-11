#include <bits/stdc++.h>

using namespace std;

bool zero(string a){
  if(a.size()==1)return false;
  if(a[0]=='0')return true;
  return false;
}

int c(string a){
  int r = 1;
  int ans = 0;
  for(int i = a.size()-1;i>=0;i--){
    ans+=(a[i]-48)*r;
    r*=10;
  }
  return ans;
}

int main(){
  string s;
  cin >> s;
  int n = s.size();
  string v1,v2,v3;
  int ans = -1;
  int cur;
  for(int i = 1;i<n-1;i++){
    for(int j = i;j<n-1;j++){
      v1=s.substr(0,i); 
      v2=s.substr(i,j-i+1);
      v3=s.substr(j+1,n-j);
      if(zero(v1) or zero(v2) or zero(v3))continue;
      if(v1.size()>7 or v2.size()>7 or v3.size()>7)continue;
      if(c(v1)>1e6 or c(v2)>1e6 or c(v3)>1e6)continue;
      cur = c(v1)+c(v2)+c(v3);
      ans=max(ans,cur);
    }
  } 
  cout << ans << "\n";
  return 0;
}