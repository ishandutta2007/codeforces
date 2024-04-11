#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<vector<int>> fl(30,vector<int>(n+5,0));
    for(int i=0;i<m;i++){
      int l,r,v;
      cin >> l >> r >> v;
      for(int j=0;j<30;j++){
        if(v&(1<<j)){continue;}
        fl[j][l]++;
        fl[j][r+1]--;
      }
    }
    vector<int> bk(30,0);
    for(int i=1;i<=n;i++){
      for(int j=0;j<30;j++){
        fl[j][i]+=fl[j][i-1];
        if(fl[j][i]==0){bk[j]=1;}
      }
    }
    long long res=0;
    long long ce=power(2,n-1);
    for(int i=0;i<30;i++){
      if(bk[i]){
        res+=(1ll<<i)*ce;
        res%=mod;
      }
    }
    cout << res << "\n";
  }
  return 0;
}