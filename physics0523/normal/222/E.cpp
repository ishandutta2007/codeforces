#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int cvrt(char c){
  if('a'<=c && c<='z'){return (c-'a');}
  return 26+(c-'A');
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m,k;
  cin >> n >> m >> k;
  n--;
  vector<vector<long long>> mat(m,vector<long long>(m,1));
  for(int i=0;i<k;i++){
    string s;
    cin >> s;
    mat[cvrt(s[0])][cvrt(s[1])]=0;
  }
  vector<vector<long long>> rm(m,vector<long long>(m,0));
  for(int i=0;i<m;i++){rm[i][i]=1;}
  for(int tg=0;tg<60;tg++){
    if(n&(1ll<<tg)){
      vector<vector<long long>> nrm(m,vector<long long>(m,0));
      for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
          for(int k=0;k<m;k++){
            nrm[i][k]+=rm[i][j]*mat[j][k];
            nrm[i][k]%=mod;
          }
        }
      }
      rm.swap(nrm);
    }
    vector<vector<long long>> nmat(m,vector<long long>(m,0));
    for(int i=0;i<m;i++){
      for(int j=0;j<m;j++){
        for(int k=0;k<m;k++){
          nmat[i][k]+=mat[i][j]*mat[j][k];
          nmat[i][k]%=mod;
        }
      }
    }
    mat.swap(nmat);
  }
  long long res=0;
  for(auto &nx : rm){
    for(auto &ny : nx){res+=ny;res%=mod;}
  }
  cout << res << '\n';
  return 0;
}