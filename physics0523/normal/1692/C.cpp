#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    vector<string> s(8);
    for(auto &nx : s){cin >> nx;}
    int ri=-1,rj=-1;
    for(int i=0;i<=5;i++){
      for(int j=0;j<=5;j++){
        int ac=0;
        for(int di=0;di<3;di++){
          for(int dj=0;dj<3;dj++){
            if((di+dj)%2==0 && s[i+di][j+dj]=='#'){ac++;}
            if((di+dj)%2==1 && s[i+di][j+dj]=='.'){ac++;}
          }
        }
        if(ac==9){ri=i+2;rj=j+2;}
      }
    }
    cout << ri << ' ' << rj << '\n';
  }
  return 0;
}