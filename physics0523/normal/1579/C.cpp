#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m,d;
    cin >> n >> m >> d;
    vector<string> s(n),g(n);
    for(auto &nx : s){cin >> nx;}
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){g[i].push_back('.');}
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        int mv=0,p=j,q=j;
        for(int h=i;h>=0;h--){
          if(s[h][p]=='.' || s[h][q]=='.'){break;}
          mv++;
          p--;q++;
          if(p<0 || q>=m){break;}
        }
        if(mv>d){
          //cout << i << ' ' << j << ' ' << mv << '\n';
          p=j;q=j;
          for(int h=i;h>(i-mv);h--){
            g[h][p]='*';g[h][q]='*';
            p--;q++;
          }
        }
      }
    }
    if(s==g){cout << "YES\n";}else{cout << "NO\n";}
  }
  return 0;
}