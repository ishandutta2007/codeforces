#include<bits/stdc++.h>

using namespace std;

bool aw(vector<string> &s){
  for(auto &nx : s){
    for(auto &ny : nx){
      if(ny!='W'){return false;}
    }
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int h,w,r,c;
    cin >> h >> w >> r >> c;
    r--;c--;
    vector<string> s(h);
    for(auto &nx : s){cin >> nx;}
    if(s[r][c]=='B'){cout << "0\n";continue;}
    if(aw(s)){cout << "-1\n";continue;}
    bool isone=false;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if((i==r || j==c) && s[i][j]=='B'){isone=true;}
      }
    }
    if(isone){cout << "1\n";}
    else{cout << "2\n";}
  }
  return 0;
}