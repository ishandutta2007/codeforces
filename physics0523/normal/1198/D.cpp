#include<bits/stdc++.h>

using namespace std;

//2D-Ruisekiwa Simple
int bsum[52][52]={0};

int cbz(int fx,int fy,int tx,int ty){
  if(fx>tx || fy>ty){return 0;}
  if(fx==0 && fy == 0){return bsum[tx][ty];}
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

int dp[52][52][52][52];

void dpinit(){
  for(int i=0;i<52;i++){
    for(int j=0;j<52;j++){
      for(int k=0;k<52;k++){
        for(int l=0;l<52;l++){
          dp[i][j][k][l]=1e9;
        }
      }
    }
  }
}

int rep(int lx,int rx,int ly,int ry){
  if(lx>rx){return 0;}
  if(ly>ry){return 0;}
  if(dp[lx][rx][ly][ry]<5e8){
    return dp[lx][rx][ly][ry];
  }

  int res=max(rx-lx+1,ry-ly+1);
  for(int i=lx;i<=rx;i++){
    if(cbz(i,ly,i,ry)==0){
      res=min(res,rep(lx,i-1,ly,ry)+rep(i+1,rx,ly,ry));
    }
  }
  for(int i=ly;i<=ry;i++){
    if(cbz(lx,i,rx,i)==0){
      res=min(res,rep(lx,rx,ly,i-1)+rep(lx,rx,i+1,ry));
    }
  }
  dp[lx][rx][ly][ry]=res;
  // if(res<0){cout << lx << ' ' << rx << ' ' << ly << ' ' << ry << ':' << res << '\n';}
  return res;
}

int main(){
  dpinit();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  bool na=true;
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    for(int j=0;j<n;j++){
      if(s[j]=='#'){na=false;bsum[i][j]=1;}
      else{bsum[i][j]=0;}
    }
  }
  if(na){cout << "0\n";return 0;}
  for(int i=0;i<n;i++){
    for(int j=1;j<n;j++){bsum[i][j]+=bsum[i][j-1];}
  }
  for(int i=1;i<n;i++){
    for(int j=0;j<n;j++){bsum[i][j]+=bsum[i-1][j];}
  }

  cout << rep(0,n-1,0,n-1) << '\n';
  return 0;
}