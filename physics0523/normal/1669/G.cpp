#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<string> s(n),res(n);
    for(int i=0;i<n;i++){
      cin >> s[i];
      for(int j=0;j<m;j++){res[i].push_back('.');}
    }
    for(int j=0;j<m;j++){
      int tg=n-1;
      for(int i=n-1;i>=0;i--){
        if(s[i][j]=='*'){
          res[tg][j]='*';
          tg--;
        }
        if(s[i][j]=='o'){
          res[i][j]='o';
          tg=i-1;
        }
      }
    }
    for(auto &nx : res){cout << nx << '\n';}
  }
  return 0;
}