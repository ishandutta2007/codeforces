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
    vector<string> s(n);
    int c0=0,c1=0;
    for(auto &nx : s){
      cin >> nx;
      for(auto &ny : nx){
        if(ny=='0'){c0++;}
        else{c1++;}
      }
    }
    if(c0==0){cout << c1-2 << "\n";continue;}
    bool ok=false;
    for(int i=1;i<n;i++){
      for(int j=1;j<m;j++){
        int blc=0;
        if(s[i-1][j-1]=='0'){blc++;}
        if(s[i-1][j]=='0'){blc++;}
        if(s[i][j-1]=='0'){blc++;}
        if(s[i][j]=='0'){blc++;}
        if(blc>=2){ok=true;}
      }
    }
    if(!ok){c1--;}
    cout << c1 << "\n";
  }
  return 0;
}