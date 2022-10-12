#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> bsum;
int cbz(int fx,int fy,int tx,int ty){
  if(fx>tx || fy>ty){return 0;}
  if(fx==0 && fy==0){return bsum[tx][ty];}
  else if(fx==0){
    return bsum[tx][ty]-bsum[tx][fy-1];
  }
  else if(fy==0){
    return bsum[tx][ty]-bsum[fx-1][ty];
  }
  else{
    return bsum[tx][ty]-bsum[tx][fy-1]-bsum[fx-1][ty]+bsum[fx-1][fy-1];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<string> s;
  string ps;
  for(int i=0;i<m+2;i++){ps.push_back('.');}
  s.push_back(ps);
  for(int i=0;i<n;i++){
    string cs;
    cin >> cs;
    cs="."+cs+".";
    s.push_back(cs);
  }
  s.push_back(ps);
  n+=2;m+=2;
  bsum.resize(n);
  for(int i=0;i<n;i++){
    bsum[i].resize(m);
    for(int j=0;j<m;j++){
      if(s[i][j]=='.'){bsum[i][j]=0;}
      else{bsum[i][j]=1;}
      if(j){bsum[i][j]+=bsum[i][j-1];}
    }
  }
  for(int i=1;i<n;i++){
    for(int j=0;j<m;j++){
      bsum[i][j]+=bsum[i-1][j];
    }
  }
  //for(auto &nx : s){cout << nx << '\n';}
  int st=0,fi=(min(n,m)-1)/2;
  while(st<=fi){
    int te=(st+fi)/2;
    int l=2*te+1;
    bool isok=true;
    vector<vector<int>> jud(n,vector<int>(m,0));
    for(int i=0;i<=n-l;i++){
      for(int j=0;j<=m-l;j++){
        int cnt=cbz(i,j,i+l-1,j+l-1);
        if(cnt==l*l){
          jud[i][j]++;
          if(i+l<n){jud[i+l][j]--;}
          if(j+l<m){jud[i][j+l]--;}
          if(i+l<n && j+l<m){jud[i+l][j+l]++;}
        }
      }
    }
    for(int i=0;i<n;i++){
      for(int j=1;j<m;j++){jud[i][j]+=jud[i][j-1];}
    }
    for(int i=1;i<n;i++){
      for(int j=0;j<m;j++){jud[i][j]+=jud[i-1][j];}
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(jud[i][j]==0 && s[i][j]=='X'){isok=false;}
      }
    }
    if(isok){st=te+1;}
    else{fi=te-1;}
  }
  cout << fi << '\n';
  vector<string> res(n,ps);
  int l=2*fi+1;
  for(int i=0;i<=n-l;i++){
    for(int j=0;j<=m-l;j++){
      int cnt=cbz(i,j,i+l-1,j+l-1);
      if(cnt==l*l){res[i+fi][j+fi]='X';}
    }
  }
  for(int i=1;i<n-1;i++){
    for(int j=1;j<m-1;j++){
      cout << res[i][j];
    }cout << '\n';
  }
  return 0;
}