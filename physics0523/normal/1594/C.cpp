#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l;
    string c,s;
    cin >> l >> c >> s;
    bool fl=true;
    for(auto &nx : s){
      if(nx!=c[0]){fl=false;}
    }
    if(fl){cout << "0\n";continue;}
    int res=-1;
    for(int i=2;i<=l;i++){
      bool fl=true;
      for(int j=i;j<=l;j+=i){
        if(s[j-1]!=c[0]){fl=false;break;}
      }
      if(fl){res=i;break;}
    }
    if(res!=-1){
      cout << "1\n" << res << '\n';
      continue;
    }
    cout << 2 << '\n';
    cout << l-1 << ' ' << l << '\n';
  }
  return 0;
}