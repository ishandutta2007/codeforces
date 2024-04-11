#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int dx4[4]={1,-1,0,0};
int dy4[4]={0,0,1,-1};

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
    for(auto &nx : s){cin >> nx;}
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(s[i][j]=='B'){
          for(int k=0;k<4;k++){
            int ni=i+dx4[k];
            int nj=j+dy4[k];
            if(!(0<=ni && ni<n)){continue;}
            if(!(0<=nj && nj<m)){continue;}
            if(s[ni][nj]=='.'){s[ni][nj]='#';}
          }
        }
      }
    }
    //for(auto &nx : s){cout << nx << '\n';}cout << '\n';
    vector<vector<bool>> fl(n,vector<bool>(m,false));
    queue<pi> q;
    if(s[n-1][m-1]!='#'){
      q.push({n-1,m-1});
      fl[n-1][m-1]=true;
    }
    while(!q.empty()){
      pi od=q.front();q.pop();
      int i=od.first;
      int j=od.second;
      for(int k=0;k<4;k++){
        int ni=i+dx4[k];
        int nj=j+dy4[k];
        if(!(0<=ni && ni<n)){continue;}
        if(!(0<=nj && nj<m)){continue;}
        if(s[ni][nj]!='#' && fl[ni][nj]==false){
          fl[ni][nj]=true;
          q.push({ni,nj});
        }
      }
    }
    bool isok=true;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(s[i][j]=='G' && fl[i][j]==false){isok=false;}
        if(s[i][j]=='B' && fl[i][j]==true){isok=false;}
      }
    }
    if(isok){cout << "Yes\n";}
    else{cout << "No\n";}
  }
  return 0;
}