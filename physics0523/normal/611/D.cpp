#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int dp[5005][5005]={0};
int run[5005][5005]={0};
int lv[5005][5005];

int l;
string s;
// void lvcalc(int tg,int fv,vector<int> &list){
//   vector<vector<int>> nl(10);
//   for(auto &nx : list){
//     if((nx+tg)>=l){continue;}
//     nl[s[nx+tg]-'0'].push_back(nx);
//   }
//   int nfv=fv;
//   for(int i=0;i<10;i++){
//     if(nl[i].empty()){continue;}
//     for(auto &nx : nl[i]){lv[nx][nx+tg]=nfv;}
//     lvcalc(tg+1,nfv,nl[i]);
//     nfv+=nl[i].size();
//   }
// }

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> l >> s;
  vector<int> mem;
  for(int i=0;i<l;i++){mem.push_back(i);}

  //lvcalc(0,0,mem);
  vector<vector<int>> va={mem};
  for(int tg=0;tg<l;tg++){
    vector<vector<int>> nva;
    int id=0;
    for(auto &nx : va){
      vector<vector<int>> keep(10);
      for(auto &ny : nx){
        if((ny+tg)>=l){continue;}
        keep[s[(ny+tg)]-'0'].push_back(ny);
      }
      for(auto &ny : keep){
        if(ny.empty()){continue;}
        for(auto &nz : ny){
          lv[nz][nz+tg]=id;
        }
        id+=ny.size();
        nva.push_back(ny);
      }
    }
    va.swap(nva);
  }
  // for(int i=0;i<l;i++){
  //   for(int j=0;i+j<l;j++){
  //     cout << lv[j][i+j] << ',';
  //   }cout << '\n';
  // }

  run[0][0]=1;
  for(int i=0;i<l;i++){
    for(int j=i;j<l;j++){
      if(j>=1){
        run[i][j]+=run[i][j-1];
        run[i][j]%=mod;
      }
      dp[i][j]+=run[i][j];
      dp[i][j]%=mod;
      int sl=j+(j-i+1);
      if(!(j==l-1 || sl<l)){continue;}
      if(dp[i][j]==0){continue;}
      if(j+1<l){
        if(s[j+1]=='0'){continue;}
        if(sl<l){
          if(lv[i][j]<lv[j+1][sl]){
            //cout << i << ',' << j << "->" << j+1 << ',' << sl << '\n';
            dp[j+1][sl]+=dp[i][j];
            dp[j+1][sl]%=mod;
          }
        }
        if(sl+1<l){
          run[j+1][sl+1]+=dp[i][j];
          run[j+1][sl+1]%=mod;
        }
      }
    }
  }
  // for(int i=0;i<l;i++){
  //   for(int j=i;j<l;j++){
  //     cout << i << ',' << j << ':' << dp[i][j] << '\n';
  //   }
  // }

  int res=0;
  for(int i=0;i<l;i++){res+=dp[i][l-1];res%=mod;}
  cout << res << '\n';
  return 0;
}