#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    if(n*a!=m*b){
      cout << "NO\n";continue;
    }
    else{
      cout << "YES\n";
      vector<string> s(n);
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){s[i].push_back('0');}
      }
      int tg=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<a;j++){
          s[i][tg]='1';
          tg++;tg%=m;
        }
      }
      for(auto &nx : s){cout << nx << '\n';}
    }
  }
  return 0;
}