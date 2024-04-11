#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,a,b,k;
  cin >> n >> a >> b >> k;
  vector<int>z;
  string s;
  cin >> s;
  z.push_back(0);
  int cur = 0;
  for(int i = 0;i<n;i++){
      if(s[i]=='1')z.push_back(i+1);
  }
  z.push_back(n+1);
  for(int j = 1;j<z.size();j++){
    cur += (z[j]-z[j-1]-1)/b;
  }
  vector<int>ans;
  int l;
  for(int i = 1;i<z.size();i++){
    if((z[i]-z[i-1]-1/b)==0)continue;
    if(cur<a)break;
    l = z[i-1]+b;
    while(l<z[i]&&cur>=a){
      ans.push_back(l);
      l+=b;
      cur--;
    }
  }
  cout << ans.size() << "\n";
  for(auto x : ans) 
    cout << x << " ";
  return 0;
}