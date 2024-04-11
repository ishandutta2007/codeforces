#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s,t;
    cin >> s >> t;
    int ss=s.size();
    int ts=t.size();
    int res=ss+ts;
    for(int i=0;i<ss;i++){
      for(int j=1;i+j<=ss;j++){
        for(int k=0;k<ts;k++){
          for(int l=1;k+l<=ts;l++){
            if(s.substr(i,j)==t.substr(k,l)){res=min(ss+ts-j-l,res);}
          }
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}