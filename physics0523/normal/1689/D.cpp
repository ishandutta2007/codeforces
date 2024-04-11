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
    vector<string> s(h);
    for(auto &nx : s){cin >> nx;}
    vector<vector<vector<int>>> f(4,vector<vector<int>>(h,vector<int>(w,-1e9)));
    for(int k=0;k<4;k++){
      for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
          int p=i,q=j;
          int dx=1,dy=1;
          if(k&1){p=h-i-1;dx=-1;}
          if(k&2){q=w-j-1;dy=-1;}
          if(s[p][q]=='B'){
            f[k][p][q]=max(f[k][p][q],0);
          }
          int np=p+dx,nq=q+dy;
          if(0<=np && np<h){
            f[k][np][q]=max(f[k][np][q],f[k][p][q]+1);
          }
          if(0<=nq && nq<w){
            f[k][p][nq]=max(f[k][p][nq],f[k][p][q]+1);
          }
        }
      }
    }
    int rp=0,rq=0,rv=1e9;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        int cv=-1e9;
        for(int k=0;k<4;k++){
          cv=max(cv,f[k][i][j]);
        }
        if(rv>cv){
          rv=cv;
          rp=i;rq=j;
        }
      }
    }
    cout << rp+1 << ' ' << rq+1 << '\n';
  }
  return 0;
}