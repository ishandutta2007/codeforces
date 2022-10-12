#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  for(auto &nx : s){cin >> nx;}
  vector<vector<int>> hz(h+1,vector<int>(w+1,0));
  vector<vector<int>> vc(h+1,vector<int>(w+1,0));
  for(int i=0;i<h;i++){
    for(int j=1;j<w;j++){
      hz[i+1][j+1]=hz[i+1][j];
      if(s[i][j-1]=='.' && s[i][j]=='.'){
        hz[i+1][j+1]++;
      }
    }
  }
  for(int j=0;j<w;j++){
    for(int i=1;i<h;i++){
      vc[i+1][j+1]=vc[i][j+1];
      if(s[i-1][j]=='.' && s[i][j]=='.'){
        vc[i+1][j+1]++;
      }
    }
  }
  int q;
  cin >> q;
  while(q>0){
    q--;
    int rl,cl,rr,cr,res=0;
    cin >> rl >> cl >> rr >> cr;
    for(int i=rl;i<=rr;i++){
      //cout << hz[i][cr]-hz[i][cl] << ',';
      res+=hz[i][cr]-hz[i][cl];
    }//cout << '\n';
    for(int i=cl;i<=cr;i++){
      //cout << vc[rr][i]-vc[rl][i] << ',';
      res+=vc[rr][i]-vc[rl][i];
    }//cout << '\n';
    cout << res << '\n';
  }
  return 0;
}