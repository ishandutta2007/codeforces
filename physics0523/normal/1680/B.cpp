#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int h,w;
    cin >> h >> w;
    int mh=1e9,mw=1e9;
    vector<string> s(h);
    for(int i=0;i<h;i++){
      cin >> s[i];
      for(int j=0;j<w;j++){
        if(s[i][j]=='R'){mh=min(mh,i);mw=min(mw,j);}
      }
    }
    assert(mh<5e8);
    if(s[mh][mw]=='R'){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}