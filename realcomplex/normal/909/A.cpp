#include <bits/stdc++.h>

using namespace std;

int main(){
  string a,b;
  cin >> a >> b;
  string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
  string cur;
  string c1,c2;
  for(int i = 0;i<a.size();i++){
    c1+=a[i];
    for(int j = 0;j<b.size();j++){
      c2+=b[j];
      cur=c1+c2;
      ans=min(ans,cur);
    }
    c2.clear();
  }
  cout << ans;
  return 0;
}