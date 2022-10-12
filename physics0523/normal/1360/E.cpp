#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<string> s(n);
    for(auto &nx : s){cin >> nx;}
    vector<string> cur(n);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){cur[i].push_back('0');}
    }
    for(int wave=2*(n-1);wave>=0;wave--){
      for(int i=0;i<n;i++){
        int tg=n-1;
        for(int j=0;j<n;j++){
          if(cur[i][j]=='1'){tg=j-1;break;}
        }
        if(tg>=0 && s[i][tg]=='1' && (i+tg)==wave){
          cur[i][tg]='1';
        }
      }
      for(int j=0;j<n;j++){
        int tg=n-1;
        for(int i=0;i<n;i++){
          if(cur[i][j]=='1'){tg=i-1;break;}
        }
        if(tg>=0 && s[tg][j]=='1' && (tg+j)==wave){
          cur[tg][j]='1';
        }
      }
    }
    //for(auto &nx : cur){cout << nx << '\n';}
    if(s==cur){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}