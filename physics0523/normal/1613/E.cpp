#include<bits/stdc++.h>

using namespace std;

int dx4[4]={1,-1,0,0};
int dy4[4]={0,0,1,-1};

int h,w;
bool jud(int i,int j){
  if(i<0 || h<=i){return false;}
  if(j<0 || w<=j){return false;}
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    cin >> h >> w;
    vector<string> s(h);
    for(auto &nx : s){cin >> nx;}
    int lh,lw;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(s[i][j]=='L'){lh=i;lw=j;}
      }
    }
    queue<pair<int,int>> q;
    q.push({lh,lw});
    while(!q.empty()){
      pair<int,int> od=q.front();q.pop();
      for(int k=0;k<4;k++){
        int ni=od.first+dx4[k];
        int nj=od.second+dy4[k];
        if(!jud(ni,nj)){continue;}
        if(s[ni][nj]!='.'){continue;}
        int deg=0;
        for(int l=0;l<4;l++){
          int mi=ni+dx4[l];
          int mj=nj+dy4[l];
          if(!jud(mi,mj)){continue;}
          if(s[mi][mj]=='.'){deg++;}
        }
        if(deg<=1){
          s[ni][nj]='+';
          q.push({ni,nj});
        }
      }
    }
    for(auto &nx : s){cout << nx << '\n';}
  }
  return 0;
}