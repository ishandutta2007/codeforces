#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  long long mat[32][10][10]={0};
  for(int i=0;i<9;i++){mat[0][i][i+1]=1;}
  mat[0][9][0]=1;
  mat[0][9][1]=1;

  for(int i=1;i<32;i++){
    for(int j=0;j<10;j++){
      for(int k=0;k<10;k++){
        for(int l=0;l<10;l++){
          mat[i][j][l]+=mat[i-1][j][k]*mat[i-1][k][l];
          mat[i][j][l]%=mod;
        }
      }
    }
  }

  while(t>0){
    t--;
    string s;
    int m;
    cin >> s >> m;
    vector<long long> mem(10,0);
    for(auto &c : s){mem[c-'0']++;}
    for(int i=30;i>=0;i--){
      if((m&(1<<i))==0){continue;}
      vector<long long> nem(10,0);
      for(int j=0;j<10;j++){
        for(int k=0;k<10;k++){
          nem[k]+=mem[j]*mat[i][j][k];
          nem[k]%=mod;
        }
      }
      mem.swap(nem);
    }
    long long res=0;
    for(int i=0;i<10;i++){res+=mem[i];}
    cout << res%mod << '\n';
  }
  return 0;
}