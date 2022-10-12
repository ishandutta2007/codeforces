#include<bits/stdc++.h>

using namespace std;

#define bas 1
long long delta[3][3];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long x,y;
    cin >> x >> y;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        delta[i][j]=8e18;
      }
    }
    delta[bas][bas]=0;
    cin >> delta[bas+1][bas+1];
    cin >> delta[bas][bas+1];
    cin >> delta[bas-1][bas];
    cin >> delta[bas-1][bas-1];
    cin >> delta[bas][bas-1];
    cin >> delta[bas+1][bas];
    for(int tr=0;tr<10;tr++){
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
              int ni=(i+k)-bas;
              int nj=(j+l)-bas;
              if(!(0<=ni && ni<3)){continue;}
              if(!(0<=nj && nj<3)){continue;}
              delta[ni][nj]=min(delta[ni][nj],delta[i][j]+delta[k][l]);
            }
          }
        }
      }
    }

    long long res=0;
    while(abs(x)!=0 || abs(y)!=0){
      long long ex=((x==0) ? 0 : x/abs(x));
      long long ey=((y==0) ? 0 : y/abs(y));
      long long ce=min(abs(x),abs(y));
      if(ex==0){ce=abs(y);}
      if(ey==0){ce=abs(x);}
      res+=ce*delta[ex+bas][ey+bas];
      x-=ex*ce;
      y-=ey*ce;
    }
    cout << res << '\n';
  }
  return 0;
}