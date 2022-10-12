#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,l,r;
  cin >> n >> l >> r;
  vector<long long> cnt(3,0);
  while((r-l+1)%3!=0 && l<=r){
    cnt[l%3]++;
    l++;
  }
  long long add=(r-l+1)/3;
  cnt[0]+=add;cnt[0]%=mod;
  cnt[1]+=add;cnt[1]%=mod;
  cnt[2]+=add;cnt[2]%=mod;
  vector<vector<long long>> mat(3,vector<long long>(3,0));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      mat[i][(i+j)%3]=cnt[j];
    }
  }
  vector<long long> vec={1,0,0};
  for(int i=0;i<32;i++){
    if(n&(1<<i)){
      vector<long long> nvec={0,0,0};
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          nvec[j]+=vec[i]*mat[i][j];
          nvec[j]%=mod;
        }
      }
      vec=nvec;
    }
    vector<vector<long long>> nmat(3,vector<long long>(3,0));
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
          nmat[i][k]+=mat[i][j]*mat[j][k];
          nmat[i][k]%=mod;
        }
      }
    }
    mat=nmat;
  }
  cout << vec[0] << '\n';
  return 0;
}