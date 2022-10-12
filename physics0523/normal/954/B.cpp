#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  int res=n;
  for(int i=1;i<=n;i++){
    string mem;
    for(int j=0;j<i;j++){mem.push_back(s[j]);}
    mem=mem+mem;
    if(mem.size()>n){break;}
    bool isok=true;
    for(int j=0;j<mem.size();j++){
      if(s[j]!=mem[j]){isok=false;}
    }
    if(isok){res=min(n-i+1,res);}
  }
  cout << res << '\n';
  return 0;
}