#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    bool fl=false;
    for(int i=0;i<8;i++){
      int l=s.size(),v=0;
      for(int j=0;j<l;j++){
        if(i&(1<<(s[j]-'A'))){v++;}else{v--;}
        if(v<0){break;}
      }
      if(v==0){fl=true;break;}
    }
    if(fl){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}